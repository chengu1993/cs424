CC = gcc

CFLAGS = -g -O3 -std=c99

all: serial compare

serial: serial.o timing.o
	$(CC) -o $@ $(CFLAGS) $^

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f serial *.o 

