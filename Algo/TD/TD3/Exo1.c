#include<stdio.h>
#include<stdlib.h>

/*Structure d'une liste */

struct Element 
{
	int numero;
	struct Element * suivant;
};
typedef struct Element * liste;

/*Retourne la dernière occurence d'une valeur passée en paramètre*/

liste derniere_occ (liste l, int val)
{
	liste temp=NULL;

	while(l!=NULL)
	{
		if(l->numero == val) temp = l;
		l=l->suivant;
	}
	return temp;
}



/*Supprime toutes les occurences de val*/
void supprime_occ (liste *l, int val)
{
	liste aux;

	if(*l != NULL)
		{
			if((*l)->numero == val)
			{
				aux = *l;
				*l = (*l)->suivant;
				free(aux);
				supprime_occ (&(*l), val);
			}
			else 
				supprime_occ (&((*l)->suivant), val);
		}
}


		
/*Affiche une liste*/
void affiche_liste (liste l)
{
	while(l!=NULL)
	{
		printf(" -> %d",l->numero);
		l=l->suivant;
	}

	printf("\n");
}



/*Creer un liste*/
void creer_liste (liste *l)
{
	int rep;
	liste new=NULL;
	
	printf ("Combien voulez-vous mettre de chiffre dans la liste ?\n");
	scanf ("%d",&rep);

		while (rep!=0)
		{
			new = malloc (sizeof (struct Element));
			printf("Quel est le numero ?\n");
			scanf("%d",&(new->numero));
			new->suivant = *l;
			*l = new;
			rep --;	
		}
}

void vider_liste(liste *l)
{
	liste p;
	if(*l==NULL) return;
	else 
	{
		p=*l;
		*l=(*l)->suivant;
		free(p);
		vider_liste(l);
	}
}	
		
	
/*Prog principal*/
int main()
{
	liste l=NULL;

	creer_liste (&l);
	printf("Liste saisie : ");
	affiche_liste (l);
	printf("\n");
	supprime_occ (&l, 5);
	printf("Liste après suppression : ");
	affiche_liste (l);
	printf("\n");
	vider_liste (&l);


	return 0;
}
	
