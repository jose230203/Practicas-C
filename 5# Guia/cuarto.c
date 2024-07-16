#include <stdio.h>

int main() {
    int numero, suma = 0, NumT = 0;
    char a;

    do {
        printf("Ingrese un numero entero: ");
        scanf("%d", &numero);

        suma += numero;
        NumT++;

        printf("¿Desea introducir otro numero? (s/n): ");
        scanf(" %c", &a);
    } while (a != 'n');

    printf("Se introdujeron %d numeros\n", NumT);
    printf("La suma de los numeros es: %d\n", suma);

    return 0;
}

