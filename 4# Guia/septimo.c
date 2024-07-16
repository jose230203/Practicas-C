#include <stdio.h>

int main() {
    int cantidadMeses,i;
    float totalGastos = 0.0;
    float mediaGastos;

    printf("Ingrese la cantidad de meses: ");
    scanf("%d", &cantidadMeses);

    for (i = 1; i <= cantidadMeses; i++) {
        float gasto;
        printf("Ingrese el gasto del mes %d: $", i);
        scanf("%f", &gasto);
        totalGastos += gasto;
    }

    mediaGastos = totalGastos / cantidadMeses;

    printf("La media de gastos en los %d meses es: $%.2f\n", cantidadMeses, mediaGastos);

    return 0;
}

