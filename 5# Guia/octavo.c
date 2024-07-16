#include <stdio.h>

int main() {
    int numero, par = 0, impar = 0;
    char respuesta;

    do {
        printf("Ingrese un numero entero: ");
        scanf("%d", &numero);

        if (numero % 2 == 0) {
            par++;
        } else {
            impar++;
        }

        printf("¿Desea introducir otro numero? (s/n): ");
        scanf(" %c", &respuesta);
    } while (respuesta != 'n');

    printf("Cantidad de numeros pares introducidos: %d\n", par);
    printf("Cantidad de numeros impares introducidos: %d\n", impar);

    return 0;
}

