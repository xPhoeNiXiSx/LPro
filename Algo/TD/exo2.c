#include <stdio.h>


int fibo(n)
{
if ((n==1)||(n==2)) return 1;
else return fibo(n-1)+fibo(n-2);
}

int main ()
{
int n,rep;
printf ("Entrez un nombre entier positif :\n");
scanf ("%d",&n);
rep=fibo(n);
printf ("La suis Fibonacci du nombre %d est : %d \n",n,rep);
return 0 ;
}
