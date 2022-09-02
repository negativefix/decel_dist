CC=gcc
main: decel_dist.c
	${CC} decel_dist.c -lm -o decel_dist

clean:
	rm -f decel_dist
