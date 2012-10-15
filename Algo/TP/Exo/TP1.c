#include<stdio.h>


/*Partie 1 :*/

/*
int main()
{
	int i,j=0;
	float x,y;
	char c;

	printf("Entrer un entier, un réel et un caractère :");
	scanf("%d %f %c",&i,&x,&c);

	printf("%d %f %c \n",i,x,c);

	printf("%d %c %c \n",c,c+1,c-1);
	
	i++;
	c--;
	
	printf("%d %d \n",i,c);

	x = i/11;
	y = i/11;

	printf("%f %f %.2f \n",x,y,y);
	printf("%f %f \n",j/i,j/(float)i);

	printf("%d %d %d \n",sizeof(int),sizeof(x),sizeof(c));

	j*=2;
	printf("%d \n",j);
	
	j-= 10;
	printf("%d \n",j);


	return 0;
}*/


/*Partie 2*/

/*int main()
{
	int S=0,i,n=20;
	
	for (i=1;i<=n;i++)
	{
		S += i;
		printf("i=%d S=%d \n",i,S);
	}
return 0;
}
*/

/*int main()
{
	int S=0,i=1,n=20;
	
	while (i<=n)
	{
		S += i;
		printf("i=%d S=%d \n",i,S);
		i++;
	}
return 0;
}
*/

int main()
{
	int S=0,i=1,n=20;
	
	do{
		S += i;
		printf("i=%d S=%d \n",i,S);
		i++;
	}while (i<=n);
return 0;
}

