/*Un colegio de la ciudad est� ofreciendo el siguiente descuento, aplicado al pago de
matricula y colegiatura
A�os estudiados en el colegio Descuento
Entre 1 y 2 15%
Entre 3 y 5 23%
Dise�e un Programa que presente esta situaci�n*/
#include <stdio.h>
#include <conio.h>

int main()
{
	int a;
	printf("Cuantos a�os llevas Estudiando en este colegio?\n");
	scanf("%d",&a);
	if (a>0 && a<=2)
	{
		printf("Su descuento sera de el 15%%\n");
	}
	else
	{
		if(a>=3 && a<=5)
		{
			printf("Su descuento es de el 23%%\n");
		}
		else
		{
			printf("Usted no obtendra descuento");
		}
	}
getch();
return 0;	
}
