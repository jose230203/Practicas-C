/*Se tiene registrado la producción (unidades) logradas por un operario a lo largo de la semana
(lunes a sábado). Elabore un Programa que muestre o diga si el operario recibirá incentivos
sabiendo que el promedio de producción mínima es de 100 unidades.*/
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
