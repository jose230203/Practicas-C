/*Hacer un Programa para un programa que calcule el pago que hacen un grupo de personas para ver
una pel�cula teniendo en cuenta que si el grupo es menor de 8 personas el pago es de 75 c�rdobas
por persona y para grupos de 8 personas o m�s el pago es 60 c�rdobas por persona.*/
#include <stdio.h>
#include <conio.h>

int main()
{
	int a,b;
	
	printf("De cuanto es su grupo?\n");
	scanf("%d",&a);
	
	if(a>=8)
	{
		b = a * 60;
		printf("Su total a pagar es de %d\n",b);
	}
	else
	{
		b = a * 75;
		printf("Su total a pagar es de %d\n",b);
	}
}
