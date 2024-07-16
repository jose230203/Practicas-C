#include <stdio.h>

int main() {
    int CantN = 0;
    int CantP = 0;
    int CantM = 0;
    int Par = 0;

    int valor,i;

    for (i = 0; i < 10; i++) {
        printf("Ingrese un valor entero: ");
        scanf("%d", &valor);

        if (valor < 0) {
            CantN++;
        } else if (valor > 0) {
            CantP++;
        }

        if (valor % 15 == 0) {
            CantM++;
        }

        if (valor % 2 == 0) {
            Par += valor;
        }
    }

    printf("Cantidad de valores ingresados negativos: %d\n", CantN);
    printf("Cantidad de valores ingresados positivos: %d\n", CantP);
    printf("Cantidad de múltiplos de 15: %d\n", CantM);
    printf("Valor acumulado de los números ingresados que son pares: %d\n", Par);

    return 0;
}

