#include<stdio.h>
#include<stdlib.h>

struct Element 
{
	int valeur;
	struct Element * suivant;
};
typedef struct Element * Liste;


int appartient (Liste L, int x)
{
	Liste temp = L;


	while(temp!=NULL)	
	{
		if(temp->valeur == x) return 1;
		else
		{
			temp=temp->suivant;
		}
	}
	return 0;
}



void supprimer (Liste *L, int x)
{
	Liste temp=*L,aux;

		if((*L)->valeur == x) 
		{
			aux = *L;
			*L = (*L)->suivant;	
		}
		else
		{
			while ((temp->suivant != NULL) && (temp->suivant->valeur != x))
				temp=temp->suivant;
			if (temp->suivant!=NULL)
			{
				aux = temp->suivant;
				temp->suivant=temp->suivant->suivant;
			}
		}
	free(aux);
}



int main()
{
	Liste L;
	L=malloc(sizeof(struct Element));
	L->valeur = 10;
	L->suivant = NULL;

	printf("appartient(L,10) = %d\n",appartient(L,10));
	printf("appartient(L,11) = %d\n",appartient(L,11));

	

	return 0;
}
