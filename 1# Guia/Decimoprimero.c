/*Una compañía ha clasificado a sus empleados en dos Grupos: Grupo 1 y Grupo 2. Cada empleado
del grupo 1 recibirá un aumento de C$25.00 córdobas, mientras que cada empleado del grupo 2
recibirá un aumento de solo C$15.00 córdobas. Elabore un Programa que permita calcular el nuevo
sueldo.*/
#include <stdio.h>
#include <conio.h>

int main(){
	int a,b;
	
	printf("A que grupo pertenece?\n");
	scanf("%d",&a);
	
	printf("Cual es su salario actual\n");
	scanf("%d",&b);
	
	if(a==1)
	{
		b += 25.00;
		printf("Su Nuevo salario seria %d Cordobas\n",b);
	}
	else
	{
		if(a==2)
		{
			b += 15.00;
			printf("Su nuevo salario seria %d Cordobas\n",b);
		}
		else
		{
			printf("Ingreso un Grupo incorrecto\n");
		}
	}
	getch();
	return 0;
}
