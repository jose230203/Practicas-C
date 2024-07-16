//segunda ejercicio Guia
#include <stdio.h>
#include <conio.h>

int main (){
	int c;
	printf("que cantidad de lapiz comprara\n");
	printf("Si usted compra mas de 1k de lapiz estos costaran 85 cada 1\n");
	printf("Si compra menos de 1k estos costaran 90 cada 1\n");
	scanf("%d",&c);
	
	if(c<1000)
	{
		printf("usted debera pagar %d\n", c * 90);
	}
	else
	{
		printf("usted debera pagar %d\n",c * 85);
	}
	getch();
	
	return 0;
}
