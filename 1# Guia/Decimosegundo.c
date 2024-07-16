/*Construya un Programa para calcular el precio del billete ida y vuelta en ferrocarril conociendo la
distancia del viaje de ida y el tiempo de estancia. Se sabe además que si el número de días de
estancia es superior a 7 y la distancia total(ida y vuelta) a recorrer es superior a 800 km, el
billete tiene una reducción del 30%. El precio por km es de $017.*/
#include <stdio.h>
#include <conio.h>

int main(){
	int a,b;
	float c,d;
	
	printf("Cual es la Distancia hasta su destino en KM\n");
	scanf("%d",&a);
	
	printf("Cual seria la duracion de su estancia\n");
	scanf("%d",&b);
	
	if(a<=400 && b>=7)
	{
		a *= 2;
		c = a*0.17;
		d = c*0.30;
		c -= d;
		printf("Su total a pagar es de %.2f\n",c);
	}
	else
	{
		a*=2;
		c = a*0.17;
		printf("Su total a pagar es de %.2f\n",c);
	}
	getch();
	return 0;
}
