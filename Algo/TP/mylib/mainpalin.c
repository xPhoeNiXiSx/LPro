#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <readline/readline.h>
#include "palin.h"

int main()
{
	char *s ;

	s = readline("Entrer un mot: ") ;
	if (palin(s))
		printf("%s est un palindrome\n",s) ;
	else
		printf("%s n'est pas un palindrome\n",s) ;

	free(s) ;

	return 0 ;
}
