/*En la Podunka State University, los veteranos sólo pagan $30 dólares por materia, mientras que
los demás (regulares) pagan $50 por materia. Escriba un Programa en el que el usuario introduce
los datos del estudiante (Vet o Reg) y el número de materias. La salida debe indicar si el
estudiante es de la categoría veterano o regular e indicar el número de materias y los costos de
colegiatura.*/
#include<stdio.h>
#include <conio.h>

int main()
{
	int a,b,c;
	printf("Usted es 1)Veterano o 2)Regular?\n");
	scanf("%d",&c);
	printf("Cuantas Materias Tomara?\n");
	scanf("%d",&a);
	
	if(c==1)
	{
		b = a * 30;
		printf("Usted es Veterano\n");
		printf("Usted lleva %d Materias\n",a);
		printf("Su Total a Pagar es de : %d\n",b);
 	}
 	else
 	{
 		if(c==2)
 		{
 		 b = a * 50;
 	 	 printf("Usted es Regular\n");
		 printf("Usted lleva %d Materias\n",a);
		 printf("Su Total a Pagar es de : %d\n",b);
		}
		else
		{
			printf("Ingreso Mal Veterano o Regular\n");
		}
	 }
	 getch();
	 return 0;
}
