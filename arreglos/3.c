#include <stdio.h>

int main(){
	int a[25];
	int i,sum;
	for  (i=0;i<=24;i++)
	{
		printf("Ingrese el digito en la casilla %d\n",i);
		scanf("%d",&a[i]);
		sum +=a[i];
	}
	for  (i=0;i<=24;i++)
	{
		printf("el numero en la casilla %d es : %d\n",i,a[i]);
	}
	printf("La suma de los numeros es : %d",sum);
	getch();
	return 0;
}
