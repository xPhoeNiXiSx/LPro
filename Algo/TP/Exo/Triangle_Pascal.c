#include<stdio.h>
#define N 100


int C(int n, int p)
{
	
}

int main()
{
	int i,j,ligne,mat[N][N];


	printf("Combien de ligne du triangle de Pascal voulez-vous afficher?\n");
	scanf("%d",&ligne);
	printf("\n");

	for(i=0;i<=ligne-1;i++)
	{
		mat[i][0]=1;
		mat[i][i]=1;
		for(j=1;j<i;j++)
		{
			mat[i][j]=mat[i-1][j]+mat[i-1][j-1];
		}
	}

	for(i=0;i<=ligne-1;i++)
	{
		for(j=0;j<=i;j++)
		{
			printf("%3d",mat[i][j]);
		}
	printf("\n");
	}
return 0;
}


/** Copie d'un tableau T1:
		memcopy(T1,T2, sizeof(T1));  ==> Dans string.h
**/
