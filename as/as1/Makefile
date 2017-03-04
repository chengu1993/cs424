CC = icc
CFLAGS = -g -O1 -fno-alias -std=c99
#CFLAGS = -g -O3 -no-vec -no-simd -fno-alias -std=c99
#CFLAGS = -g -O3 -xHost -fno-alias -std=c99

all: ex1

ex1:	ex1.o timing.o
	$(CC) -o $@ $(CFLAGS) $^

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f ex1 *.o

