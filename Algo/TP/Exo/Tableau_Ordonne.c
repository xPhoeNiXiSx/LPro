#include<stdio.h>
#define N 100

int main()
{
	int i,j,n,temp,tab[N];

	printf("Combien de valeur voulez-vous rentrer?");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Saisissez une valeur :");
		scanf("%d",&tab[i]);
	}

	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(tab[i]<tab[j])
			{
				temp=tab[i];
				tab[i]=tab[j];
				tab[j]=temp;
			}
		}
	}

	for(i=0;i<n;i++)
	{
		printf("%d ",tab[i]);
	}
return 0;
}
