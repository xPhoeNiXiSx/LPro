#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define SEED 35791246

int main()
{
   int iteration=0;
   double x,y;
   int i,count=0; /* # of points in the 1st quadrant of unit circle */
   double z;
   double pi;

   printf("Entrer le nom d'iterations pour estimer PI: ");
   scanf("%d",&iteration);

   srand(SEED);

   count=0;
	for ( i=0; i<iteration; i++) 
	{
      x = (double)rand()/RAND_MAX;
      y = (double)rand()/RAND_MAX;
      z = x*x+y*y;
      if (z<=1) count++;
     }
   pi=(double)count/iteration*4;

   printf("Avec %d itérations, PI est estimé à %f \n",iteration,pi);

return 0;
}
