#include<stdio.h>
#include<string.h>


/* strcmp, strcpy */

int main()
{
	char s1[10], s2[10], x[10] ;
	
	printf("Donner une chaine de caractère \n");
	scanf("%s",s1);

	printf("Donner une seconde chaine de caractère \n");
	scanf("%s",s2);

	if (strcmp(s1,s2)>0)
	{
		strcpy(x,s1);
		strcpy(s1,s2);
		strcpy(s2,x);
	}

	printf("La premiere chaine : %s \n et la deuxieme : %s \n",s1,s2);

	return 0;
}

/************* Donne l'ordre alphabétique ************************************/
