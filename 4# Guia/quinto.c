#include <stdio.h>
int Sumacuadrados(int);
int Sumacuadrados(int n) {
    int suma = 0;
     int i;
    for (i = 1; i <= n; i++) {
        suma += i * i;
    }

    return suma;
}

int main() {
    int n;
    int resultado;

    printf("Ingrese un Numero entero positivo: ");
    scanf("%d", &n);
    if(n>0)
	resultado = Sumacuadrados(n);
    else
    {
	printf("Ingreso un numero negativo");
	return 0;
    }
    printf("La suma de los cuadrados de los primeros %d numeros naturales es: %d\n", n, resultado);

    return 0;
}

