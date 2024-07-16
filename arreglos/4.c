#include <stdio.h>

int main(){
	int n;
	int a[n],b[n],c[n];
	int i,sum;
	printf("Cuantos numeros ingresara?");
	scanf("%d",&n);
	
	printf("\nIngrese los numeros de el primer vector\n");
	for  (i=0;i<=n-1;i++)
	{
		printf("Ingrese el numero de el vector 1 en la posicion %d",i);
		scanf("%d",&a[i]);
	}
	for  (i=0;i<=n-1;i++)
	{
		printf("Ingrese el numero de el vector 2 en la posicion %d",i);
		scanf("%d",&b[i]);
		c[i]=a[i]+b[i];
	}
	for  (i=0;i<=n-1;i++)
	{
		printf("Los elementos de las posiciones %d de la lista a y b son : %d ",i,c[i]);
	}
