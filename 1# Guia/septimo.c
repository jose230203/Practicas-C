//septimo
#include <stdio.h>
#include <conio.h>

int main(){
	int a;
	printf("cual es el valor en pesos?\n");
	scanf("%d",&a);
	
	if(a<5)
	{
		printf("su cantidad a pagar es de 10 centavos\n");
	}
	else
	{
		a -= 5;
		a *= 5;
		a += 10;
		printf("la cantidad a pagar es de %d\n",a);
	}
	
	getch();
	return 0;
}
