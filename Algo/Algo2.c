#include<stdio.h>
#include<math.h>

int main()
{
	float info,math,chimie;
	int coef_info=3,coef_math=3,coef_chimie=2;

	printf("Quelle est ta note en informatique?");
	scanf ("%f",&info);
	printf("Quelle est ta note en math?");
	scanf ("%f",&math);
	printf("Quelle est ta note en chimie?");
	scanf ("%f",&chimie);

	printf("Votre moyenne est de %f/20.\n",(info*coef_info+math*coef_math+chimie*coef_chimie)/(coef_info+coef_math+coef_chimie));
	return 0;
}
