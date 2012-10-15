#include<stdio.h>//Thomas Fraquet LicProInfo
#include<stdlib.h>

#define N 5


/*Définition d'une structure file*/
struct e_file
{
	int tab[N];//tab[N] qui est le tableau qui contiendra les valeurs de la file avec pour taille N
	int debut;//debut qui est le numéro de la case où commencela file
	int nbr_val;//nbr_val qui est le nombre de valeur que le tableau tab contient
};
typedef struct e_file *file;



/*Définition d'une structure pile*/
struct e_pile
{
	int tab[N];//idem que file
	int nbr_val;//idem que file
};
typedef struct e_pile *pile;



/*Procédure qui initialise une file*/
void init_file (file *f)
{
	(*f)->debut = 0;
	(*f)->nbr_val = 0;
}
/*Procédure qui initialise une file*/
void init_pile (pile *p)
{
	(*p)->nbr_val = 0;
}

																				/*Vide ou non*/

/*Fonction qui teste si la file ou la pile est vide, 
c'est-à-dire si le nombre de valeurs est égale à 0 */
int est_vide_file (file f)
{
	if (f->nbr_val == 0)
		return 1;
	else
		return 0;
}
int est_vide_pile (pile p)
{
	if (p->nbr_val == 0)
		return 1;
	else
		return 0;
}

																				/*Pleine ou non*/

/*Fonction qui teste si la file ou la pile est pleine,
c'est-à-dire si le nombres de valeurs est égale à N */
int est_pleine_file (file f)
{
	if (f->nbr_val == N)
		return 1;
	else
		return 0;
}
int est_pleine_pile (pile p)
{
	if (p->nbr_val == N)
		return 1;
	else
		return 0;
}

																				/*Enfile et Empile*/

/*Procédure qui ajoute en bout de file une valeur passée
en paramètre (val)*/
void enfile(file *f, int val)
{
	printf("-->Insertion de : %d\n",val);

	if (est_pleine_file(*f))
		printf ("------------>File pleine à l'insertion de %d\n",val);
	else
	{
		(*f)->tab[((*f)->debut+(*f)->nbr_val) % N] = val;      //Si la file n'est pas pleine, on insère la valeur a l'indice = indice de debut + le nombre totale de valeurs
		(*f)->nbr_val++;									  //modulo la taille maximale du tableau pour inserer la valeur au debut du tableau si la fin est occupée
	}														 // par exemple si debut=2 et il y a 3 éléments, on a (2+3)%5=0 donc la valeur s'insere au debut
}
/*Procédure qui ajoute en bout de pile une valeur passée
en paramètre (val)*/
void empile(pile *p, int val)
{
	printf("-->Insertion de : %d\n",val);

	if(est_pleine_pile(*p))
		printf ("------------>Pile pleine à l'insertion de %d\n",val);
	else
	{
		(*p)->tab[(*p)->nbr_val] = val;
		(*p)->nbr_val++;
	}
}

																				/*Defile et Depile*/

/*Procédure qui supprime le premier élément de la file*/
void defile(file *f)
{
	printf("-->Suppression\n");

	if (est_vide_file(*f))
		printf ("------------>File vide, impossible de supprimer une valeur\n");
	else
	{
		(*f)->debut = ((*f)->debut + 1) % N;	
		(*f)->nbr_val--;
	}
}
void depile(pile *p)
{
	printf("-->Suppression\n");

	if (est_vide_pile(*p))
		printf ("------------>Pile vide, impossible de supprimer une valeur\n");
	else
		(*p)->nbr_val--;
}

																				/*Affichage*/

//Affichage d'une file
void affiche_file (file f)
{
	int i,j;

	i = f->debut;

	printf ("Affichage file :");
	
	if(est_vide_file(f))
		printf("(vide)");
	else	
		for (j=0;j<(f->nbr_val);j++)
		{
			printf (" -> %d (case %d)",f->tab[i],i); //Affiche la valeur dans le tableau avec le numero de la case 
			if(i == N-1)						//du tableau pour montrer le décalage des indices dans le tableau
				i = 0;
			else
				i++;
		}
	printf("\n");
}
//Affichage d'une pile
void affiche_pile (pile p)
{
	int i;

	printf ("Affichage pile :");
	
	if(est_vide_pile(p))
		printf("(vide)");
	else	
		for (i=0 ; i<(p->nbr_val) ; i++)
		{
			printf (" -> %d (case %d) ",p->tab[i],i);
		}
	printf("\n");
}



//------------------------------------------------------------------------------------------------------/
//------------------------------------------------------------------------------------------------------/



																/*****Programme principal*****/
int main()
{
	file f;
	pile p;

	p = malloc (sizeof(struct e_pile));		//Allocation de mémoire pour la pile
	f = malloc (sizeof(struct e_file));		//Allocation de mémoire pour la file

	init_pile(&p);		//Initialisation de p
	init_file(&f);		//Initialisation de f

															/*Manipulation des file*/
	printf("\nManipulation des files :\n\n");

		/**Insertion dans la file**/

	enfile(&f,5);		//Insertions de la valeur 5
	affiche_file (f);
	enfile(&f,4);		//Insertions de la valeur 4
	affiche_file (f);
	enfile(&f,3);		//Insertions de la valeur 3
	affiche_file (f);
	enfile(&f,2);		//Insertions de la valeur 2
	affiche_file (f);
	enfile(&f,1);		//Insertions de la valeur 1
	affiche_file (f);
	enfile(&f,0);		//Insertions de la valeur 0

		/**Partie suppression**/

	defile(&f);			//Suppressions dans la file
	affiche_file (f);
	defile(&f);			//Suppressions dans la file
	affiche_file (f);
	defile(&f);			//Suppressions dans la file
	affiche_file (f);
	defile(&f);			//Suppressions dans la file
	affiche_file (f);

		/**Réinsertion dans la file**/

	enfile(&f,6);		//Insertions de la valeur 6
	enfile(&f,7);		//Insertions de la valeur 7
	enfile(&f,8);		//Insertions de la valeur 8

	affiche_file (f);

															/*Manipulation des pile*/
	printf("\nManipulation des piles :\n\n");


	empile(&p,1);		//Insertions de la valeur 0
	affiche_pile(p);
	empile(&p,1);		//Insertions de la valeur 1
	affiche_pile(p);
	empile(&p,2);		//Insertions de la valeur 2
	affiche_pile(p);
	empile(&p,3);		//Insertions de la valeur 3
	affiche_pile(p);
	empile(&p,4);		//Insertions de la valeur 4
	affiche_pile(p);
	empile(&p,5);		//Insertions de la valeur 5
	affiche_pile(p);



	depile(&p);			//Suppressions dans la pile
	affiche_pile (p);
	depile(&p);			//Suppressions dans la pile
	affiche_pile (p);
	depile(&p);			//Suppressions dans la pile
	affiche_pile (p);
	depile(&p);			//Suppressions dans la pile
	affiche_pile (p);	



	free (f);			//Libération de mémoire pour la file f
	free (p);			//Libération de mémoire pour la pile p

	return 0;
}

