#include <stdio.h>

int main() {
    float cost, ganancia, pvp;

    printf("Introduce el precio de coste del artículo: ");
    scanf("%f", &cost);

    if (cost < 300) {
        ganancia = cost * 0.15;
    } else if (cost >= 300 && cost <= 600) {
        ganancia = 50;
    } else {
        ganancia = cost * 0.25;
    }

    pvp = cost + ganancia;

    printf("El precio de venta del artículo es: C$ %.2f\n", pvp);

    return 0;
}

