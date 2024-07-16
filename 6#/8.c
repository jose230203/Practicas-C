#include <stdio.h>
#include <math.h>
float potencia(float x,int n);
int main() {
    float x;
    int n;

    printf("Ingrese un numero real x: ");
    scanf("%f", &x);

    printf("Ingrese un exponente entero n: ");
    scanf("%d", &n);

    float resultado = potencia(x,n);

    printf("%.2f elevado a la potencia %d es igual a %.2f\n",x,n,resultado); 

    return 0;
}
float potencia(float x,int n)
{
	float resultado;
	resultado=pow(x,n);
	return resultado;
}

