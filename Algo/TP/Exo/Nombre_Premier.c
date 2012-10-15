#include <stdio.h>

int main()
{

	int test,nbr,i=1;
	
	printf("Voulez-vous tester la primalité d'un nombre ?(1=oui, 2=non)");
	scanf("%d",&test);

	while(test!=2)
	{
		printf("Entrez un entier >2 : ");
		scanf("%d",&nbr);

		while (nbr%i != 0 && i*i <= nbr) i++;
		if (nbr%i != 0)
			printf("C'est un nombre premier \n");
		else
			printf("Ce n'est pas un nombre premier \n");


	printf("Voulez-vous tester la primalité d'un autre nombre ?(1=oui, 2=non)");
	scanf("%d",&test);
	}

return 0;
}
