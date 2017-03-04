TIMINGDIR = /home/fas/cpsc424/ahs3/utils/timing
CC = mpicc
CFLAGS = -g -O3 -xHost -fno-alias -std=c99 -I$(TIMINGDIR)

all: task2

task2: task2.o $(TIMINGDIR)/timing.o
	$(CC) -o $@ $(CFLAGS) $^

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f task2 *.o
