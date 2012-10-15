#include <stdio.h>

#define ORIGINAL "monfichier"
#define COPIE "/usr/share/dict/words"
#define L 60

/* fopen, fclose, r read, w write, a append, NULL */
//fprintf (in, "___",...), fread, fscanf, fwrite,fgets

int main ()
{
	FILE *in, *out;
	char s[L];
	int n1 = 0;

	in = fopen (ORIGINAL,"r");
	if (in == NULL)
	{
		perror(ORIGINAL) ;
		return 1 ;
	}
	out = fopen(COPIE,"w");
	if (out == NULL)
	{
		perror(COPIE);
		return 2 ;
	}

	while(fgets(s,L-1,in) != NULL)
	{
		fprintf(out, "%02d: %s",n1,s);
		n1++;
	}

	fclose(in);
	fclose(out);

	return 0;
}
