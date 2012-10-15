#include<stdio.h>
#define L 20

int un_a_un(char *s)
{
	int i=0;

	while (s[i] != '\0') i++ ;

	return i ;
}

int un_a_un2(char *s) //Version 2 sans utiliser d'indice
{
	char *p=s ;
	while (*++p)
	return p-s-1;
}

int main()
{
	char s[L] ;

	fgets(s,L-1,stdin);
	
	printf("%d \n",un_a_un(s)) ;

	return 0;
}
