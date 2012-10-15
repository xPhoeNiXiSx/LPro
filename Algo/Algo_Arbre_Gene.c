#include<stdio.h>
#include<stdlib.h>

struct fils
{
	struct noeud * n;
	struct fils * suivant;
};

struct noeud
{
	int val;
	struct fils * f;
};


int main()
{
	return 0;
}
