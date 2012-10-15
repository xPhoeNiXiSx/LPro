#include<stdio.h>


unt calcul(int n)
{
	if (n==0) return 0;
	else return n+calcul(n-1);		
}


void main(int argc, char * argv[])
{
	int n;
	printf("Donner un nombre à additionner :");
	scanf("%d",n);
	printf("%d\n",calcul(n));
}
