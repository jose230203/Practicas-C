//Primer ejercicio Guia
#include <stdio.h>
#include <conio.h>

int main (){
	int a;
	
	printf("escriba un numero\n ");
	scanf("%d",&a);
	
	if(a % 2 == 0)
	{
	 printf("su numero es par\n");
	}
	else
	{
		printf("su numero es impar\n");
	}
	
	getch();
	
	
	
	return 0;
}
