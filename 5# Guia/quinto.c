#include <stdio.h>

int main() {
    int numero, cuadrado, suma = 0;
    char respuesta;

    do {
        printf("Ingrese un numero entero: ");
        scanf("%d", &numero);

        cuadrado = numero * numero;
        printf("%d elevado a 2 es: %d\n", numero, cuadrado);

        suma += cuadrado;

        printf("¿Desea introducir otro numero? (s/n): ");
        scanf(" %c", &respuesta);
    } while (respuesta != 'n');

    printf("La suma de los cuadrados calculados es: %d\n", suma);

    return 0;
}

