#include<stdio.h>

int pgcd (int a, int b)
{
	if(a==b) return a;
	else if(a>b) return pgcd((a-b),b);
		 else return pgcd(a,(b-a));
}

void main (int argc, char * argv[])
{
	int x,y;

	printf("Donner les deux nomres dont vous voulez connaitre le PGCD :");
	scanf("%d %d",x,y);
	
	printf("Le PGCD de %d et %d est %d.",x,y,pgcd(x,y));
}
