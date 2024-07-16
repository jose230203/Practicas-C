//quinto
#include <stdio.h>
#include <conio.h>

int main(){
	int a,b;
	printf("digite un numero\n");
	scanf("%d",&a);
	if(a>0)
	{
		printf("digite un segundo valor\n");
		scanf("%d",&b);
		
		printf("la suma de sus numeros son %d\n",a+b);
	}
	else
	{
		printf("ingreso un numero negativo\n");
	}
		getch();
	return 0;
}
