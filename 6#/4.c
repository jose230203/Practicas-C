#include <stdio.h>
#include <math.h>
#define PI 3.1416
#define SIZE 10
int pot(float a,int b);

int main (){
	int i,b;
	float a;
	a=PI;
	b=SIZE;

	printf("",pot(a,b));
	
	return 0;
}

int pot(float a, int n)
{
	int i;
		for (i=2;i<=n;i++)
	{
		printf("El numero elevado a %d es : %.2f \n",i,pow(a,i));
		printf("La raiz cuadrada de este numero seria %.2f\n",sqrt(pow(a,i)));
		printf("\n");
	}
	return 0;
}
