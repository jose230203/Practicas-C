//octavo
#include <stdio.h>
#include <conio.h>
#include <time.h>

int main(){
	int a;
	float b,c;
	srand(time(NULL));
a=rand() % 149;
	printf("Bienvenido su numero aleatorio es %d\n",a);
	
	printf("cual es la cantidad a pagar?\n");
	scanf("%f",&b);
	
	if(a<74)
	{
		printf("su descuento es de el 15%%\n");
		c = (b*15) / 100;
		printf("el total descontado es de %.2f\n",c);
	}
	else
	{
		printf("su descuento es de el 20%%\n");
			c = (b*20) / 100;
		printf("el total descontado es de %.2f\n",c);
	}
	return 0;
}
