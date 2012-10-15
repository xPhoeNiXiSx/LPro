#include <stdio.h>
#include <stdlib.h>

#define N 10

struct Element
{
	struct noeud * val;
	struct Element * suivant;
};
typedef struct Element * File;


struct noeud
{
	int val;
	struct noeud * gauche;
	struct noeud * droit;
};
typedef struct noeud * arbre;

typedef int TAB[N];



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


//Passe d'un Arbre Binaire vers un Arbre Binaire de Recherche
void AB_vers_ABR (arbre a,arbre *b)
{
	if (a != NULL)
	{
		inserer(&(*b),a->val);		
		AB_vers_ABR (a->gauche,&(*b));
		AB_vers_ABR (a->droit,&(*b));
	}
}


void remplitableau(arbre a,TAB t,int *j)
{
	if (a != NULL)
	{
		remplitableau(a->gauche,t,&(*j));
		t[*j]=a->val;
		(*j)++;
		remplitableau(a->droit,t,&(*j));
	}
}


void TriTableau(TAB tab,int n)
{
	arbre abr=NULL;
	int i,j=0;
	
	for(i=0;i<n;i++)
		inserer(&abr,tab[i]);
	remplitableau(abr,tab,&j);	
}

void affiche_tab (TAB t,int n)
{
	int i;
	
	for(i=0;i<n;i++)
		printf("%d ",t[i]);
}

void enfiler(File *mafile, arbre val)
{
	File tmp;
	tmp = (File)malloc(sizeof(struct Element));
	tmp->val = val;
	tmp->suivant = *mafile;
	*mafile=tmp;
}

File defiler(File *mafile)
{
	File tmp,tmp2;
	if (*mafile == NULL)
		return NULL;
	else
		{
			tmp = *mafile;
			if ((*mafile)->suivant == NULL)
				{
					(*mafile) = NULL;
					return tmp;
				}
			else
				{
					while(tmp->suivant->suivant != NULL)
						tmp=tmp->suivant;
					tmp2 = tmp->suivant;
					tmp->suivant = NULL;
					return tmp2;
				}
		}
}


int estvide(File f)
{
	if (f == NULL) 
		return 0;
	else
		return 1;
}


void larg(arbre a)
{
	arbre v;
	File f,tmp; 
	f = NULL;
	if (a != NULL)
		{
			enfiler(&f, a);
			while (estvide(f) == 1)
				{ 
					tmp = defiler(&f);
					v = tmp->val;
					free(tmp);
					printf("%d ",v->val);
					if (v->gauche != NULL)
						{
							enfiler(&f,v->gauche);
						}
					if (v->droit != NULL)
						{
							enfiler(&f,v->droit);
						}
				}
		}
}


void largeur (arbre a, File * f)
{
  arbre tmp;
  File tmpf;
  if (a != NULL)
	{
	  printf("%d ",a->val);
	  if (a->gauche != NULL)
		  enfiler(&(*f),a->gauche);
	  if (a->droit != NULL)	
		  enfiler(&(*f),a->droit);
	  if (estvide(*f) != 0)
		{
			tmpf = defiler(&(*f));
			tmp = tmpf->val;
			free(tmpf);
			largeur(tmp,&(*f));
		}
	}
}

		
		
		

//PP
int main()
{
	File f = NULL;

	int tab[N] = {5,6,2,1,10,7,9,8,3,4};
	
	arbre ab,abr;
	arbre tmp1,tmp2,tmp3,tmp4,tmp5,tmp6,tmp7,tmp8,tmp9;

	ab = NULL;
	abr = NULL;

	tmp1 = malloc(sizeof(struct noeud));
	tmp1->val = 1;
	tmp1->gauche = NULL;
	tmp1->droit = NULL;
	tmp2 = malloc(sizeof(struct noeud));
	tmp2->val = 3;
	tmp2->gauche = NULL;
	tmp2->droit = NULL;
	tmp3 = malloc(sizeof(struct noeud));
	tmp3->val = 7;
	tmp3->gauche = NULL;
	tmp3->droit = NULL;
	tmp4 = malloc(sizeof(struct noeud));
	tmp4->val = 2;
	tmp4->gauche = NULL;
	tmp4->droit = NULL;
	tmp5 = malloc(sizeof(struct noeud));
	tmp5->val = 9;
	tmp5->gauche = tmp1;
	tmp5->droit = tmp2;
	tmp6 = malloc(sizeof(struct noeud));
	tmp6->val = 10;
	tmp6->gauche = NULL;
	tmp6->droit = tmp3;
	tmp7 = malloc(sizeof(struct noeud));
	tmp7->val = 6;
	tmp7->gauche = tmp4;
	tmp7->droit = NULL;
	tmp8 = malloc(sizeof(struct noeud));
	tmp8->val = 4;
	tmp8->gauche = tmp5;
	tmp8->droit = NULL;
	tmp9 = malloc(sizeof(struct noeud));
	tmp9->val = 8;
	tmp9->gauche = tmp6;
	tmp9->droit = tmp7;
	ab = malloc(sizeof(struct noeud));
	ab->val = 5;
	ab->gauche = tmp8;
	ab->droit = tmp9;
	
	printf("AB: ");
	affiche_infixe(ab);
	printf("\n");

	printf("ABR: ");
	AB_vers_ABR(ab,&abr);

	affiche_infixe(abr);
	printf("\n");

	printf("-------------------------\n");

	printf("Tableau dans le desordre : ");
	affiche_tab(tab,10);
	printf("\n");

	TriTableau(tab,10);

	printf("Tableau dans l'ordre : ");
	affiche_tab(tab,10);
	printf("\n");

	printf("-------------------------\n");

	affiche_infixe(abr);
	printf("\n");

	largeur(abr,&f);
	printf("\n");	

	return 0;
}
