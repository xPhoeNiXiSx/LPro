#include <stdio.h>
#include <stdlib.h>

struct noeud
{
	int val;
	struct noeud * gauche;
	struct noeud * droit;
};
typedef struct noeud * arbre;


//Donne le nombre de noeud présent dans l'arbre
int taille (arbre a)
{
	if (a == NULL) return 0;
	else return 1+(taille(a->gauche))+(taille(a->droit));
}

//Donner la hauteur pour un noeud donné
int hauteur (arbre a, int elemt)
{
	int h;

	if (a == NULL) 
		return -1;
	if(a->val == elemt)
		return 0 ;
	h=1+hauteur(a->gauche,elemt);
	if (h==0)
	{
		h=1+hauteur(a->droit,elemt);
		if (h==0)
			return -1;
		else 
			return h;
	}
	return h;
}


//Affiche parcous prefixe
void affiche_prefixe (arbre a)
{
	if (a != NULL)
	{
		printf ("%d ",a->val);
		affiche_prefixe (a->gauche);
		affiche_prefixe (a->droit);
	}
}


//Affiche parcours infixe
void affiche_infixe (arbre a)
{
	if (a != NULL)
	{
		affiche_infixe (a->gauche);
		printf ("%d ",a->val);
		affiche_infixe (a->droit);
	}
}


//Affiche parcours sufixe
void affiche_suffixe (arbre a)
{
	if (a != NULL)
	{
		affiche_infixe (a->gauche);
		affiche_infixe (a->droit);
		printf ("%d ",a->val);
	}
}


//Inserer valeur arbre binaire de recherche (ABR)
void inserer (arbre *a, int val)
{

	if (*a==NULL)
	{
		*a = malloc (sizeof (struct noeud));
		(*a)->val=val;
		(*a)->gauche=NULL;
		(*a)->droit=NULL;
	}
	else
	{
		if (val <= (*a)->val)
				inserer (&(*a)->gauche,val);
		else
				inserer (&(*a)->droit,val);
	}		
}


//Recherche d'une valeur
int recherche (arbre a, int val)
{
	if(a == NULL)
		return 1;
	else
		if(a->val == val)
			return 0;
		else
			if (val > a->val)
				return recherche (a->droit,val);
			else
				return recherche (a->gauche,val);
}


//Désalloue tout les noeuds de l'arbre a
void detruit (arbre *a)
{
	if (*a!=NULL)
	{
		detruit (&(*a)->gauche);
		detruit (&(*a)->droit);
		free(*a);
		*a = NULL;
	}
}

int main()
{
	arbre a,tmp1,tmp2,tmp3,tmp4,tmp5,tmp6,tmp7,tmp8,tmp9;

	tmp1 = (arbre)malloc(sizeof(struct noeud));
	tmp1->val = 1;
	tmp1->gauche = NULL;
	tmp1->droit = NULL;

	tmp2 = (arbre)malloc(sizeof(struct noeud));
	tmp2->val = 3;
	tmp2->gauche = NULL;
	tmp2->droit = NULL;

	tmp3 = (arbre)malloc(sizeof(struct noeud));
	tmp3->val = 7;
	tmp3->gauche = NULL;
	tmp3->droit = NULL;

	tmp4 = (arbre)malloc(sizeof(struct noeud));
	tmp4->val = 9;
	tmp4->gauche = NULL;
	tmp4->droit = NULL;

	tmp5 = (arbre)malloc(sizeof(struct noeud));
	tmp5->val = 2;
	tmp5->gauche = tmp1;
	tmp5->droit = tmp2;

	tmp6 = (arbre)malloc(sizeof(struct noeud));
	tmp6->val = 6;
	tmp6->gauche = NULL;
	tmp6->droit = tmp3;

	tmp7 = (arbre)malloc(sizeof(struct noeud));
	tmp7->val = 10;
	tmp7->gauche = tmp4;
	tmp7->droit = NULL;

	tmp8 = (arbre)malloc(sizeof(struct noeud));
	tmp8->val = 4;
	tmp8->gauche = tmp5;
	tmp8->droit = NULL;

	tmp9 = (arbre)malloc(sizeof(struct noeud));
	tmp9->val = 8;
	tmp9->gauche = tmp6;
	tmp9->droit = tmp7;

	a = (arbre)malloc(sizeof(struct noeud));
	a->val = 5;
	a->gauche = tmp8;
	a->droit = tmp9;


	printf("La hauteur de 10 est %d\n",hauteur(a,10));
	printf("Taille de l'arbre a = %d\n",taille(a));
	
	printf("Affiche prefixe : ");
	affiche_prefixe (a);
	inserer (&a,1);
	printf("\n");
	printf("Affiche infixe  : ");
	affiche_infixe (a);
	inserer (&a,11);
	printf("\n");
	printf("Affiche suffixe : ");
	affiche_suffixe (a);
	printf("\n");

	printf ("Recherche de 2 = %d\n",recherche(a,2));
	printf ("Recherche de 12 = %d\n",recherche(a,12));
	printf ("Recherche de 2 = %d\n",recherche(a,5));
	printf ("Recherche de 12 = %d\n",recherche(a,0));
	
	detruit(&a);

	printf("Affiche suffixe : ");
	affiche_suffixe (a);
	printf("\n");
	
	return 0;

}
