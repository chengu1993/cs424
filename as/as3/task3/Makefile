TIMINGDIR = /home/fas/cpsc424/ahs3/utils/timing
CC = mpicc
CFLAGS = -g -O3 -xHost -fno-alias -std=c99 -I$(TIMINGDIR)

all: task3

task3: task3.o $(TIMINGDIR)/timing.o
	$(CC) -o $@ $(CFLAGS) $^

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f task3 *.o
