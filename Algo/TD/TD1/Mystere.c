#include<stdio.h>

int mystere(int n)
{
	if(n==1)
		return 1;
	else
		return mystere(n-1)+2*(n-1)+1;
}

//Carré
