#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
	if(argc==1){
		fprintf(stderr,"Please provide an argument, which is the weigh to the main mass, secondary mass is 1kg\n");
		return -1;
	}
	if(argc>2){
		fprintf(stderr,"Please provide only one argument\n");
		return -1;
	}
	unsigned long long  main_mass=10;
	int ratio, secondary_mass=1;
	double main_vel=1, secondary_vel=0, vcm;
	unsigned long  collisions=0;
	ratio=atoi(argv[1]);
	if(ratio<=0){
		fprintf(stderr,"Please provide a correct, positive number\n");
		return -1;
	}
	main_mass=pow(100,ratio);
	do
	{
		//cubes collide
		vcm = (main_mass*main_vel+secondary_mass*secondary_vel)/(main_mass+secondary_mass);
		main_vel = (2*vcm-main_vel);
		secondary_vel = 2*vcm-secondary_vel;
		collisions++;
		if(secondary_vel>0){
		//wall and cube collide
		secondary_vel = secondary_vel*(-1);
		collisions ++;}

	}
	while( secondary_vel < main_vel ||( secondary_vel>0 && main_vel > 0));
	printf("There are %lu collisions\n",collisions);

	return 0;


}
