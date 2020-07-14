#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(void)
{
	unsigned long long  main_mass=10;
	int ratio, secondary_mass=1;
	double main_vel=1, secondary_vel=0, vcm;
	unsigned long  collisions=0;
	do
	{
		printf("enter the weight of the main mass(positive), the secondary mass is 1kg");
		scanf("%d",&ratio);
		main_mass=pow(100,ratio);
	}
	while(ratio<0);


	do
	{
		//cubes collide
		vcm = (main_mass*main_vel+secondary_mass*secondary_vel)/(main_mass+secondary_mass);
//		printf("2*%f-%f=",vcm,main_vel);
		main_vel = (2*vcm-main_vel);
//		printf("%f\n",main_vel);
		secondary_vel = 2*vcm-secondary_vel;
		collisions++;
		if(secondary_vel>0){
		//wall and cube collide
		secondary_vel = secondary_vel*(-1);
		collisions ++;}

	}
	while( secondary_vel < main_vel ||( secondary_vel>0 && main_vel > 0));
	printf("%lu collisions\n",collisions);

	return 0;


}
