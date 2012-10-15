#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#define size 1001

int main()
{

int nb,X,mini=0,maxi=1000;
srand(time(NULL));
X = rand()%size;

do{
		do{
			printf("Donner un nombre entre %d et %d :",mini,maxi);
			scanf("%d",&nb);
			if((nb>maxi)&&(nb<mini))printf("\nVeuillez donner un nombre entre %d et %d inclus\n",mini,maxi);
		  }while((nb>maxi)&&(nb<mini));
		if (nb<X)
		{
			printf("Trop petit\n");
			mini=nb+1;
		}
		else if (nb>X)
		{
			printf("Trop grand\n");
			maxi=nb-1;
		}
  }while(nb!=X);
	printf("Gagné! \n");

return 0;
}
