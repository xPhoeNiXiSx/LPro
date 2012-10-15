#include<stdio.h>
#include <sys/types.h>
#include<pwd.h>
#include<grp.h>

int main(int argc, char **arg)
{
	struct group *group=getgrent();
	char **nom_mem;

	if (argc != 2)
	{
		printf("Mauvais nombre d'arguments !\n");
		return 1;
	}
	
	while((group->gr_name != arg[1]) && (group!=NULL))
		group=getgrent();

	printf("NomGroupe = %s, user = ",arg[1]);

	if(group != NULL)
	{
		nom_mem = group->gr_mem;
		while(*nom_mem != NULL)
		{
			printf("%s, ",*nom_mem);
			nom_mem++;
		}
		printf("\n");
	}
	else printf("Nom de groupe incorrect !\n");
	return 0;
}
