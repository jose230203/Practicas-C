/*Se tiene registrado la producci�n (unidades) logradas por un operario a lo largo de la semana
(lunes a s�bado). Elabore un Programa que muestre o diga si el operario recibir� incentivos
sabiendo que el promedio de producci�n m�nima es de 100 unidades.*/
#include <stdio.h>
#include <conio.h>

int main(){
	int a,b;
	
	printf("Cual a sido su produccion a lo largo de la semana?\n");
	scanf("%d",&a);
	if(a>=100)
	{
		printf("Usted recibira un incentivos\n");
	}
	else
	{
		printf("Usted no recibira incentivos\n");
	}
	getch();
	return 0;
}
