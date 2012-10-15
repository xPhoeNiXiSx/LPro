#include<stdio.h>

typedef int GRILLE[49];
typedef int TIRAGE[7];

void init(GRILLE *G)
{
	int i;

	for(i=0;i<49;i++)
	{
		*G[i]=0;
	}
}

void rempli(GRILLE *G)
{
	int i, val;

	for(i=1;i<6;i++)
	{
		printf("Donner votre %dème numéro:\n",i);
		scanf("%d",&val);
		*G[val-1]=1;
	}
	printf("Et le numero complémentaire :\n");
	scanf("%d",&val);
	*G[val-1]=1;
}

int present(GRILLE G,int N)
{
	if(G[N-1]==1) return 1;
	else return 0;
}

int numero(GRILLE G,TIRAGE T)
{
	int i,bonn_rep=0;

	for(i=0;i<6;i++)
	{
		if(present(G,T[i])) bonn_rep++;
	}
return bonn_rep;
}

void resultat(GRILLE G, TIRAGE T)
{

	/**Essayer Avec le Switch**/


	if(numero(G,T)<3) printf("Rien\n");
	else 
	{
		printf("%d bons numéros",numero(G,T));
		if(present(G,T[6])==1) printf(" + complémentaire\n");
		else printf("\n");
	}
}

int main()
{
	TIRAGE T={1,2,3,14,29,9};
	GRILLE G;
	
	init(&G);
	rempli(&G);
	resultat(G,T);

return 0;
}









