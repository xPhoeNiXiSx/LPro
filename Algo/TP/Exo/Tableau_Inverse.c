#include<stdio.h>
#define size 5

int main()
{
	int i,temp,tab[size];

	printf("Donner 5 nombre a rentrer dans un tableau : \n");

	for(i=0;i<size;i++)
	{
		scanf("%d ",&tab[i]);
	}

	for(i=0;i<size/2;i++)
	{
		temp=tab[i];
		tab[i] = tab[size-i-1];
		tab[size-i-1] = temp;
	}

	for(i=0;i<size;i++)
	{
		printf("%d ",tab[i]);
	}
	printf("\n");
return 0;
}
