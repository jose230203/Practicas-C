//Tercero ejercicio Guia
#include <stdio.h>
#include <conio.h>

int main (){
	float p,d;
	printf("cual es el precio de el vestido?\n");
	printf("Recuerde que tenemos una promocion que si el precio es superior a 2500 le aplicaremos un descuento de el 15%%\n");
	printf("en cambio si el precio es menor el descuento sera de el 8%%\n");
	scanf("%f",&p);
	
	if(p>=2500)
	{
		d = p * 15 / 100;
		p-=d;
		printf("el precio es %.2f\n",p);
		printf("su descuento es de  %.2f\n",d);
	}
	else
	{
	d = p * 8 / 100;
		p-=d;
		printf("el precio es %.2f\n",p);
		printf("su descuento es de  %.2f\n",d);
	}
	
}
