CCX=gcc
CFLAGS=-Wall -pedantic -fpic -g


all: pi.out

pi.out: pi.c
	$(CCX) $^ -o $@ $(CFLAGS) -lm

clean:
	rm *.out
