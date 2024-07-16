//Cuarto  ejercicio Guia
#include <stdio.h>
#include <conio.h>

int main (){
	int a,b,c;
	printf("Cual es su sueldo por hora?\n");
	scanf("%d",&b);
	printf("Cuantas Horas Trabajo esta semana?\n");
	scanf("%d",&a);
	
	if(a>40)
	{
		c = 40*b;
		a -=40;
		b *= 2;
		a *= b;
		c += a;
		printf("Su sueldo total es de %d\n",c);
	}
	else
	{
		c=a * b;
		printf("Su sueldo total es de  %d\n",c);
	}
	
	getch();
}
