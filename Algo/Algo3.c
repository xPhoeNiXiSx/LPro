#include<stdio.h>

int main()
{
	int nb;
	
	printf("Donner un nombre --->  ");
	scanf("%d", &nb);

	if(nb%2==0) printf("Votre nombre est pair.\n\n");
	else printf("Votre nombre est impair.\n\n");
return 0;
}
