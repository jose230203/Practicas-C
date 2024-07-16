#include <stdio.h>

int main() {
    int numero, i;
    char respuesta;

    do {
        printf("Ingrese un numero entero: ");
        scanf("%d", &numero);

        printf("Tabla de multiplicar del %d:\n", numero);
        for (i = 1; i <= 10; i++) {
            printf("%d x %d = %d\n", numero, i, numero * i);
        }

        printf("¿Desea ver la tabla de multiplicar de otro numero? (s/n): ");
        scanf(" %c", &respuesta);
    } while (respuesta != 'n');

    return 0;
}

