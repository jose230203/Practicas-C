/*En un estacionamiento, se cobra de la siguiente manera: los primeros 10 minutos son gratis, los
siguientes 30 minutos tiene un valor de $15 . Diseñe un Programa que reciba minutos y
muestre lo que debe cancelar el cliente.*/
#include <stdio.h>
#include <conio.h>

int main(){
	int a;
	float b,c;
	printf("Cuantos minutos paso estacionado?\n");
	scanf("%d",&a);
	
	if(a<=10)
	{
		printf("Los primeros 10 min eran gratis No debe pagar");
	}
	else
	{
		b = (float)a/30;
		c = b * 15;
		printf("Su cantidad a pagar es de %.2f$",c);
	}
	getch();
	return 0;
}
