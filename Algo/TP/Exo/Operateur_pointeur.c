#include<stdio.h>

int main()
{
	int i= 12;
	int *ptr;
	
	ptr = &i;
	*ptr = 21;

	printf("ptr= %p *ptr= %d i= %d\n",ptr,*ptr,i) ;
	scanf("%d",ptr) ;
	printf("ptr= %p *ptr= %d i= %d\n",ptr,*ptr,i) ;
return 0;
}
