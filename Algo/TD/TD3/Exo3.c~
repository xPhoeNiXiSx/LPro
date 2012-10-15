#include<stdio.h>
#include<stdlib.h>

struct element
{
	int val;
	struct element *precedent;
	struct element *suivant;
};
typedef struct element *liste;


//Creer une liste
void creer_liste (liste *l)
{
	int rep;
	liste tmp=NULL;
	
	printf ("Voulez-vous ajouter un nombre à la liste (1=oui, 2=non) ?");
	scanf ("%d",&rep);

	if (rep == 1)
	{
		(*l) = malloc (sizeof(struct element));
		
		printf ("Quelle nombre voulez-vous ajouter à la liste ?");
		scanf ("%d",&((*l)->val));
		(*l)->suivant = NULL;
		(*l)->precedent = NULL;

		printf ("Voulez-vous ajouter un nombre à la liste (1=oui, 2=non) ?");
		scanf ("%d",&rep);

		while (rep == 1)
		{
			tmp = malloc (sizeof(struct element));
			
			printf ("Quelle nombre voulez-vous ajouter à la liste ?");
			scanf ("%d",&(tmp->val));
		
			tmp->suivant=(*l);
			tmp->precedent = NULL;
			(*l)->precedent = tmp;
			(*l)=tmp;

			printf ("Voulez-vous ajouter un nombre à la liste (1=oui, 2=non) ?");
			scanf ("%d",&rep);
		}
	}
}


//Insere une valeur à la bonne place
void inserer (liste *maliste, int val)
{
	liste tmp,l;
	
	tmp = malloc (sizeof(struct element));
	tmp->val = val;
	l = *maliste;

	if ((*maliste == NULL ) || (val <= (*maliste)->val)) // NULL ou premier à inserer
	{
		tmp->suivant = (*maliste);
		tmp->precedent = NULL;
		if (*maliste != NULL)
			(*maliste)->precedent = tmp;
		*maliste=tmp;
	}
	else //Non NULL et pas le premier
	{
		while ((l->suivant != NULL) && (l->val < val))
			l = l->suivant;
		if(l->val >= val) //Cas general
		{
			tmp->suivant = l;
			tmp->precedent = l->precedent;
			l->precedent->suivant = tmp;
			l->precedent = tmp;
		}
		else //Dernier element à inserer
		{
			tmp->precedent = l;
			tmp->suivant = NULL;	
			l->suivant = tmp;
		}
	}
}



//Supprime une valeur donné dans la la liste 
void supprimer (liste *l, int val)
{
	liste tmp = (*l);

	if ((*l) != NULL)
	{
		if ((*l)->val == val) // Le premier element de la liste
		{
			if ((*l)->suivant != NULL) //S'il y a plusieurs éléments dans la liste
				(*l)->suivant->precedent = NULL;
			*l = (*l)->suivant;
			free(tmp);
		}
		else
		{
			while ((tmp != NULL) && (tmp->val != val))
				tmp = tmp->suivant;
			if (tmp != NULL)
			{
				tmp->precedent->suivant = tmp->suivant;
				if (tmp->suivant != NULL)
									tmp->suivant->precedent = tmp->precedent;
				free(tmp);
			}
		}
	}
}


//Affiche une liste doublement-chainé
void affiche_liste (liste l)
{
	while (l != NULL)
	{
		printf ("%d ",l->val);
		l = l->suivant;
	}
	printf ("\n");
}


//Affiche une liste
void affiche_liste2 (liste l)
{
	
	while (l != NULL)
	{
		if (l->precedent != NULL)
			if (l->suivant != NULL)
				printf ("%d(%d,%d)",l->val,l->precedent->val,l->suivant->val);
			else
				printf ("%d(%d,NULL)",l->val,l->precedent->val);
		else 
			if (l->suivant != NULL)
				printf ("%d(NULL,%d)",l->val,l->suivant->val);	
			else
				printf ("%d(NULL,NULL)",l->val);
		l=l->suivant;
	}
	printf("\n");
}
		
		


//Programme principal
int main()
{
	liste l=NULL;

	//creer_liste (&l);
	//affiche_liste2 (l);

	inserer(&l,9);
	affiche_liste2(l);
	inserer(&l,5);
	affiche_liste2(l);
	inserer(&l,14);
	affiche_liste2(l);
	inserer(&l,12);
	inserer(&l,2);
	affiche_liste2(l);
	supprimer(&l,12);
	affiche_liste2(l);
	supprimer(&l,5);
	affiche_liste2(l);
	supprimer(&l,14);
	affiche_liste2(l);

	return 0;
}
