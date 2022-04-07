#include <stdio.h>
#include <stdlib.h>

unsigned long long power(int a, int b);

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
	unsigned long long  main_mass=10, check_value;
	int ratio, secondary_mass=1;
	double main_vel=1, secondary_vel=0, vcm;
	unsigned long  collisions=0;
	char *ptr;
	ratio=strtod(argv[1], &ptr);
	if(ratio<=0){
		fprintf(stderr,"Please provide a correct, positive number\n");
		return -1;
	}
	main_mass=power(100,ratio);
	printf("secondary mass is %i, main mass is %llu, selected ratio is %i\n", secondary_mass, main_mass, ratio);
	check_value = power(10, ratio - 1); 
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
			collisions ++;
			if(collisions % check_value == 0 ) printf("there have been %lu collisions so far\n", collisions);
		}
	}
	while( secondary_vel < main_vel ||( secondary_vel>0 && main_vel > 0));
	printf("There are %lu collisions\n",collisions);

	return 0;


}

unsigned long long power(int a, int b)
{
	unsigned long long result;
	result = a;
	for(int i = 0; i < b; i++)
	{
		result = result * a;
	} 
	return result;
}
