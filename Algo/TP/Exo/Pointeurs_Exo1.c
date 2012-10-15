#include<stdio.h>
#include<math.h>

int somme_prod (int s, int p, int *a, int *b)
{
	int delta=0;

	delta = s*s - 4*p;

	if(delta > 0)
	{
		*a = (s+sqrt(delta))/2;
		*b = (s-sqrt(delta))/2;
		return 1;
	}
	else return 0;
}

void swap (int *c, int *d)
{
	int temp;

	temp = *c;
	*c = *d;
	*d = temp;
}

int main()
{
	int s,p,res,a,b;

	printf("Donner une somme s et un produit p\n");
	scanf("%d %d",&s,&p);

	res = somme_prod(s,p,&a,&b);

	if(res==1) 
		printf("Avec comme somme s = %d et comme produit p = %d, on a comme chiffre a = %d et b = %d \n",s,p,a,b);
	else 
		printf("Pas de solution\n");

	return 0;
}
