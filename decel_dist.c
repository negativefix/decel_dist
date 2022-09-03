#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <stdbool.h>

#define ASTRONOMICAL_UNIT 149597870

void print_usage()
{
    puts("Usage: decel_dist <current_velocity> <max_speed> - both units are kilometers");
}

void print_program_desc()
{
    puts("Space Engine: Deceleration distance calculator");
}

double kmtoau(double distance_km)
{
    return distance_km / ASTRONOMICAL_UNIT;
}

int main(int argc, char *argv[])
{

    if (argc < 3) {
	print_usage();
	return 1;
    }

    int c;
    bool to_au = false;
    while ((c = getopt(argc, argv, "a")) != -1) {
	switch (c) {
	case 'a':
	    to_au = true;
	    break;
	default:
	    print_usage();
	    return 1;
	}
    }

    // check for the missing arguments to prevent seg fault
    if (argc == 3 && optind == 2) {
	print_program_desc();
	print_usage();
	return 1;
    }

    double current_velocity = atof(argv[optind]);
    double max_speed = atof(argv[optind + 1]);

    if (current_velocity == 0.0 || max_speed == 0.0) {
	print_program_desc();
	print_usage();
	return 1;
    }

    double distance_to_decel =
	(0 - pow(current_velocity, 2)) / (2 * max_speed);

    distance_to_decel =
	to_au == true ? kmtoau(distance_to_decel) : distance_to_decel;
    char *unit = to_au == true ? "AU" : "kilometers";

    print_program_desc();
    printf("Distance needed to decelerate is %f %s\n",
	   fabs(distance_to_decel), unit);
}
