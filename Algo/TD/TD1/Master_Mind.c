#include<stdio.h>
#include<math.h>
#include<time.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>

#define N 3



	typedef int TAB[N] ;
	TAB A,B,C;
	int gagne;

void saisie_tab (TAB *T)
{
	int i=0,tmp;

	while(i!=N)
	{
		printf("Saisissez un nombre entre 1 et 9:");
		scanf("%d",&tmp);
		if((tmp>0) && (tmp<10))
		{
			(*T)[i] = tmp;
			i++;
		}
	}
}

void affiche_tab(TAB T)
{
	int i;
	
	for(i=0;i<N;i++)
	{
		printf("%d | ",T[i]);
	}
	printf("\n\n");
}

int appartient(TAB T,int X)
{
	int i=N;
	for(i=0;i<N;i++)
	{
		if(T[i] == X) return 1;
	}
	return 0;
}

void compare_tab (TAB A,TAB B,TAB *C)
{
	int i,j=0;
	
	/**for(i=0;i<N;i++)
	{
		if(A[i]==B[i]) (*C)[i]=A[i];
		else if (appartient(B,A[i])) (*C)[i]=-A[i];
			else (*C)[i]=0;
	}

	for(i=0;i<N;i++)
	{
		if(A[i]!=B[i]) return;
	}
	gagne = 0;**/

 for(i=0;i<N;i++)
{
	if (A[i] == B[i])
	{
		(*C)[i] = A[i];
		j++;
	}
	else
	{
		if(appartient(B,A[i])) (*C)[i] = -A[i];
		else (*C)[i] = 0;
	}
}

if (j == N) gagne = 0;
		

	return;		
}

void creer_tableau_aleatoire(TAB *B)
{
	srand(time(NULL));
	int i,val;
	
	for(i=0;i<N;i++)
		(*B)[i]=0;

	for(i=0;i<N;i++)
	{
		val = rand()%9+1;
		while (appartient(*B,val) == 0) val = random()%9+1;
		(*B)[i]=val;
	}
}


int main()
{


	gagne = 1;

	creer_tableau_aleatoire(&B);

	do{
		saisie_tab(&A);
		affiche_tab(A);
		compare_tab(A,B,&C);
		affiche_tab(C);
	}while(gagne == 1);
	printf("Bravo, vous avez gagné!\n");
return 0;
}
