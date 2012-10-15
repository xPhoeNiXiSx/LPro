#include<stdio.h>

/*		Switch expression
		{
		case constante 1:
			<inst1>;
			break;
		case constante 2;
			<instn>;
			break;
		default :
			<inst0>;
			break;
}*/

void main(int argc, char *argv[])
{
	int pays;
	printf("Choisissez un pays (1France,2USA,3Mexique,4Chine):");
	scanf("%d",&pays);
	switch (pays)
		{
		case 1:printf("euro\n");
				break;
		case 2:printf("dollar\n");
				break;
		case 3:printf("peso\n");
				break;
		case 4:printf("yen\n");
				break;
		default:printf("Mauvaise sélection\n");
				break;
		}

return 0;
}
