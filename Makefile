CC=gcc
CFLAGS=-lm
main: decel_dist.c
	${CC} decel_dist.c -o decel_dist

clean:
	rm -f decel_dist
