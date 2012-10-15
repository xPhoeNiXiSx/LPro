#include<stdio.h>

void main(int argc, char * argv[])
{
	int mois;

	printf("Saisissez le numéro du mois :");
	scanf("%d",&mois);

	switch (mois)
	{
		case 1:case 3:case 5: case 7: case 8: case 10: case 12: printf("31 jour dans le mois.\n");
				break;
		case 4: case 6: case 9: case 11: printf("30 jour dans le mois.\n");
				break;
		case 2: printf("28 ou 29 jour dans le mois.\n");
				break;
		default : printf("Mauvaise sélection");
				break;
	}
}
