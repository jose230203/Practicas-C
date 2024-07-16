#include <stdio.h>
#include <math.h>
char first(char b[15]);
int main (){
	char a[15];
	printf("Ingrese la cadena de texto ");
	gets(a);
	printf("La primera letra de su cadena de texto es : %c",first(a));
}
char first(char b[15])
{
return b[0];
}
