#include<stdio.h>

float puissanceV1(float X, int n)
{
	if(n==0) return 1;
	else
	{
		if(n>0)
			return X*puissanceV1(X,n-1);
		else 
			return 1/puissanceV1(X,-n);
	}
}

float puissanceV2(float X, int n)
{
	
	if(n==0) return 1;
	else 
	{
		if(n>0)
		{
			if(n%2==0) return puissanceV2((X*X),n/2);
			else return X*puissanceV2(X,n-1);
		}
		else return 1/puissanceV2(X,-n);
	}
}


int main()
{
	float X;
	int n,opt;

	printf("Quel est le nombre dont vous voulez calculez la puissance?\n");
	scanf("%f",&X);
	printf("Quel est sa puissance ?\n");
	scanf("%d",&n);

	printf("Voulez-vous tester la premiere (1) ou la seconde version (2)?\n");
	scanf("%d",&opt);
	
	if(opt==1) printf("%f puissance %d = %f\n",X,n,puissanceV1(X,n));
	else printf("%f puissance %d = %f\n",X,n,puissanceV2(X,n));

return 0;
}	
