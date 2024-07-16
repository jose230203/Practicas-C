#include <stdio.h>
int i,j;
void comp(int []);
int main(){
	int ven[10][15];
	int ventasvend,ventamod[15],totalVendedor[10];
for (i=0;i<=3;i++)
{
	for(j=0;j<=5;j++)
	{
		printf("Cuantos vehiculos vendio el vendedor %d de el modelo %d : ",i,j);
		scanf("%d",&ven[i][j]);
	}
}
for (i=0;i<=3;i++)
{
	printf("Vendedor %d   ",i);
	for(j=0;j<=5;j++)
	{
		ventasvend+= ven[i][j];
		printf("Modelo %d = %d  ",j,ven[i][j]);
		ventamod[j]+= ven[i][j];
	}
	printf("Total: %d\n", ventasvend);
	totalVendedor[i] = ventasvend;
}
printf("\nVentas por Modelo:\n");
    for (i = 0; i<=14; i++) {
        printf("Modelo %d: %d\n",i, ventamod[i]);
    }
}
void comp(int a[])
{
	int aux,vend;
	aux=a[0];
	for(i=0;i<=9;i++)
	{
		if (a[i] > aux) 
		{
            aux = a[i];
            vend = i;
       	}
	}
	printf("El vendedor que mas autos vendio es %d y vendio un total de %d",vend , aux);
}
