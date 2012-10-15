#include<time.h>
#include<stdlib.h>
#include<stdio.h>

int main()
{

int nb,X,mini=0,maxi=1000;
srand(time(NULL));
X = rand()%1001;

do{
		do{
			printf("Donner un nombre entre %d et %d\n",mini,maxi);
			scanf("%d",&nb);
			if((nb>maxi)&&(nb<mini))printf("Veuillez donner un nombre entre %d et %d inclus\n",mini,maxi);
		  }while((nb>maxi)&&(nb<mini));
		if (nb<X)
		{
			printf("Trop grand\n");
			maxi=nb-1;
		}
		else if (nb>X)
		{
			printf("Trop petit\n");
			mini=nb+1;
		}
  }while(nb!=X);
	printf("Gagné!");

return 0;
}
