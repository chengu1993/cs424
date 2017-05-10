CC = icc

CFLAGS = -g -O3 -xHost -fno-alias -std=c99

all: poisson

poisson: poisson.o timing.o
	$(CC) -o $@ $(CFLAGS) $^

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f poisson *.o 

