//Elabora un Programa que solicite la edad de 2 hermanos y muestre un mensaje indicando
//la edad del mayor y cuantos años de diferencia tiene con el menor.
#include<stdio.h>
#include <conio.h>

int main(){
	int a,b,c;
	
	printf("Digite la edad de el primer hermano\n");
	scanf("%d",&a);
	printf("Digite la edad de el segundo hermano\n");
	scanf("%d",&b);
	
	if(a>b)
	{
		printf("el Primer Hermano es Mayor y la diferencia es de %d\n",a-b);
	}
	else
	{	
	if(b>a)
	{
		printf("el Segundo Hermano es Mayor y la diferencia es de %d\n",b-a);
	}
	else
	{
		printf("los Hermanos tienen la misma edad\n");
	}
}
	getch();
	return 0;
}
