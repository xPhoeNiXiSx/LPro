#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Element
{
	char valeur;
	struct Element * suivant;
};
typedef struct Element * Pile;


//Teste si la liste est vide
int estvide(Pile maliste)
{
	if (maliste == NULL)
	return 1 ;
	else return 0 ;
}


//Empile un élément en-tete de la liste
void empiler(Pile *mapile, char val)
{
	Pile tmp;
	tmp = malloc(sizeof(struct Element));
	tmp->valeur = val;
	tmp->suivant = *mapile;
	*mapile=tmp;
}


//Depile le premier element de la liste
Pile depiler(Pile *mapile)
{
	Pile tmp;
	if (*mapile == NULL)
		return NULL;
	else
		{
			tmp = *mapile;
			*mapile=(*mapile)->suivant;
			tmp->suivant = NULL;
			return tmp;
		}
}


//Affiche une pile
void afficher(Pile p)
{
	while(p!=NULL)
		{
			printf("%c ",p->valeur);
			p=p->suivant;
		}
	printf("\n");
}


//Pour désalloué toute la pile proprement
void detruire(Pile *p)
{
	while(*p != NULL)
		free(depiler(&(*p)));
}


//On verifie le parenthèsage de l'expression passée en paramètre
int comparer(char * exp) 
{
	Pile tmp,p = NULL;
	int len,i;
	char c;

	len = strlen(exp);
	for(i=0;i<len;i++)
		{
			switch (exp[i]) {
			case '(' : case '{' : case '[' :
				empiler(&p,exp[i]);
				break;
			case ')' : case '}' : case ']' :
				if (p == NULL)
					return 0;
				tmp=depiler(&p);
				c = tmp->valeur;
				free(tmp);
				if (((exp[i] == ')') && (c != '('))
				||((exp[i] == '}') && (c != '{')) 
				||((exp[i] == ']') && (c != '['))) 
					{
					detruire(&p);
					printf("Conflit entre %c et %c\n",exp[i],c);
					return 0;
					}
				break;
			}
		}
	if (p == NULL)
		return 1;
	else
	{
		detruire(&p);
		return 0;
	}
}	


//Programme principal
int main(int argc, char * argv[])
{ 
	int rep;

	printf("%s\n",argv[1]);
	
	rep =	comparer(argv[1]);
	
	printf("%d \n",rep);
	return 0;
}


