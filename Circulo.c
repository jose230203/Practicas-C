/*Escriba un programa que lea el radio de un c�rculo y que imprima el di�metro del mismo,
su circunferencia y su �rea. Utilice el valor de Pi directamente en la f�rmula.*/
#include <stdio.h>

int main(){
	float r,a,c,d;
	
	
	printf("digite el radio de su circulo\n");
	scanf("%f",&r);
	
	a=r*r*3.1416;
	c=2*3.1416*r;
	d=r*2;
	
	printf("area de el circulo: %.2f\n",a);
	printf("circunferencia de el circulo: %.2f\n",c);
	printf("diametro de el circulo: %.2f\n",d);
	
		
	return 0;
}
