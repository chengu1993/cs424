#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

struct BodySet {
  float *x, *y, *z;
  float *vx, *vy, *vz;
};

void MoveBodies(const int nBodies, struct BodySet* const bodies, const float dt) {

  // Avoid singularity and interaction with self
  const float softening = 1e-20;
  // Loop over bodies that experience force
  #pragma omp parallel for 
  for (int i = 0; i < nBodies; i++) { 

    // Components of the gravity force on body i
    float Fx = 0, Fy = 0, Fz = 0; 
      
    // Loop over bodies that exert force: vectorization expected here
    for (int j = 0; j < nBodies; j++) { 
      
      // Newton's law of universal gravity
      const float dx = bodies->x[j] - bodies->x[i];
      const float dy = bodies->y[j] - bodies->y[i];
      const float dz = bodies->z[j] - bodies->z[i];
      const float drSquared  = dx*dx + dy*dy + dz*dz + softening;
      const float drPower32  = powf(drSquared, 1.5f); 
	  const float reciprocal = 1.0f / drPower32;	
      // Calculate the net force
      Fx += dx * reciprocal;  
      Fy += dy * reciprocal;  
      Fz += dz * reciprocal;

    }

    // Accelerate bodies in response to the gravitational force
    bodies->vx[i] += dt*Fx; 
    bodies->vy[i] += dt*Fy; 
    bodies->vz[i] += dt*Fz;
  }

  // Move bodies according to their velocities
  #pragma omp parallel for 
  for (int i = 0 ; i < nBodies; i++) { 
    bodies->x[i]  += bodies->vx[i]*dt;
    bodies->y[i]  += bodies->vy[i]*dt;
    bodies->z[i]  += bodies->vz[i]*dt;
  }
}

int main(const int argc, const char** argv) {

  // Problem size and other parameters
  const int nBodies = (argc > 1 ? atoi(argv[1]) : 16384);
  const int nThreads = (argc > 2 ? atoi(argv[2]) : 8);
  const int nSteps = 10;  // Duration of test
  const float dt = 0.01f; // Body propagation time step

  //Setting the Number of Threads in a Team
  omp_set_num_threads(nThreads);

  // Body data storeed as Strcuture of Arrays
  struct BodySet bodies;

  // Initialize random number generator and bodies
  srand(0);
  float randmax;
  randmax = (float) RAND_MAX;
  bodies.x = (float *) malloc(nBodies * sizeof(float));
  bodies.y = (float *) malloc(nBodies * sizeof(float));
  bodies.z = (float *) malloc(nBodies * sizeof(float));
  bodies.vx = (float *) malloc(nBodies * sizeof(float));
  bodies.vy = (float *) malloc(nBodies * sizeof(float));
  bodies.vz = (float *) malloc(nBodies * sizeof(float));
  for(int i = 0; i < nBodies; i++) {
    bodies.x[i] = ((float) rand())/randmax; 
    bodies.y[i] = ((float) rand())/randmax; 
    bodies.z[i] = ((float) rand())/randmax; 
    bodies.vx[i] = ((float) rand())/randmax; 
    bodies.vy[i] = ((float) rand())/randmax; 
    bodies.vz[i] = ((float) rand())/randmax; 
  }

  // Compute initial center of mass  
  float comx = 0.0f, comy=0.0f, comz=0.0f;
  #pragma omp parallel for reduction(+:comx, comy, comz)
  for (int i=0; i<nBodies; i++) {
    comx += bodies.x[i];
    comy += bodies.y[i];
    comz += bodies.z[i];
  }
  comx = comx / nBodies;
  comy = comy / nBodies;
  comz = comz / nBodies;

  printf("Initial center of mass: (%g, %g, %g)\n", comx, comy, comz);

  // Perform benchmark
  printf("\n\033[1mNBODY Version 03\033[0m\n");
  printf("\nPropagating %d bodies using %d thread on %s...\n\n", 
	 nBodies, nThreads, "CPU");

  double rate = 0, dRate = 0; // Benchmarking data
  const int skipSteps = 3; // Set this to a positive int to skip warm-up steps

  printf("\033[1m%5s %10s %10s %8s\033[0m\n", "Step", "Time, s", "Interact/s", "GFLOP/s"); fflush(stdout);

  for (int step = 1; step <= nSteps; step++) {

    const double tStart = omp_get_wtime(); // Start timing
	MoveBodies(nBodies, &bodies, dt);
    const double tEnd = omp_get_wtime(); // End timing

    // These are for calculating flop rate. It ignores symmetry and 
    // estimates 20 flops per body-body interaction in MoveBodies
    const float HztoInts   = (float)nBodies * (float)(nBodies-1) ;
    const float HztoGFLOPs = 20.0*1e-9*(float)nBodies*(float)(nBodies-1);

    if (step > skipSteps) { 
      // Collect statistics 
      rate  += HztoGFLOPs / (tEnd - tStart); 
      dRate += HztoGFLOPs * HztoGFLOPs / ((tEnd-tStart)*(tEnd-tStart)); 
    }

    printf("%5d %10.3e %10.3e %8.1f %s\n", 
	   step, (tEnd-tStart), HztoInts/(tEnd-tStart), HztoGFLOPs/(tEnd-tStart), (step<=skipSteps?"*":""));
    fflush(stdout);
  }

  rate/=(double)(nSteps-skipSteps); 
  dRate=sqrt(fabs(dRate/(double)(nSteps-skipSteps)-rate*rate));

  printf("-----------------------------------------------------\n");
  printf("\033[1m%s %4s \033[42m%10.1f +- %.1f GFLOP/s\033[0m\n",
	 "Average performance:", "", rate, dRate);
  printf("-----------------------------------------------------\n");
  printf("* - warm-up, not included in average\n\n");

  // Compute final center of mass
  comx = 0.0f; comy=0.0f; comz=0.0f;
  #pragma omp parallel for reduction(+:comx, comy, comz)
  for (int i=0; i<nBodies; i++) {
    comx += bodies.x[i];
    comy += bodies.y[i];
    comz += bodies.z[i];
  }
  comx = comx / nBodies;
  comy = comy / nBodies;
  comz = comz / nBodies;
  
  printf("Final center of mass: (%g, %g, %g)\n", comx, comy, comz);

  // Clean up to avoid memory leak
  free(bodies.x);
  free(bodies.y);
  free(bodies.z);
  free(bodies.vx);
  free(bodies.vy);
  free(bodies.vz);

}
