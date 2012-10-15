#include <stdio.h>
#define size 100

int main()
{
	char mot[size];
	int longueur,i;

	printf("Saisissez votre mot :\n");
	scanf ("%s",mot);

	longueur=strlen(mot);
	i=0;
	while ((i<longueur/2) && (mot[i]==mot[longueur-i-1]))
	{
		i++;
	}
	if (i==longueur/2)
		printf("C'est un palindrome");
	else
		printf("Ce n'est pas un palindrome");
}
