#include <stdio.h>
#include <math.h>
int comp(int x,int y);
int main (){
int a,b;
   printf("Ingrese los 2 digitos a comparar ");
   scanf("%d %d",&a,&b);
   printf("",comp(a,b));
}
int comp(int x,int y)
{
	if(x<y)
	printf("El Primer digito es menor %d",x);
	else
	if(y<x)
	printf ("El segundo digito es menor %d",y);
	else
	printf("Son iguales");
}
