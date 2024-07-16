#include <stdio.h>

int main() {
    int a;
    float b;
    printf("Ingrese la cantidad de minutos de la llamada: ");
    scanf("%d", &a);
    if (a <= 5) {
        b = 10.0;
    } else {
        b = 10.0 + 2.0 * (a - 5);
    }
    printf("El costo total de la llamada de %d minutos es de %.2f dolares.\n", a, b);
    return 0;
}

