#include <stdio.h>

int main() {
    int cola, naranja, limon;
    float precioCola, precioNaranja, precioLimon;
    float totalCola, totalNaranja, totalLimon, totalVentas;


    printf("Ingrese la cantidad vendida de refresco de cola: ");
    scanf("%d", &cola);
    printf("Ingrese el precio del refresco de cola: ");
    scanf("%f", &precioCola);

    printf("Ingrese la cantidad vendida de refresco de naranja: ");
    scanf("%d", &naranja);
    printf("Ingrese el precio del refresco de naranja: ");
    scanf("%f", &precioNaranja);

    printf("Ingrese la cantidad vendida de refresco de limón: ");
    scanf("%d", &limon);
    printf("Ingrese el precio del refresco de limón: ");
    scanf("%f", &precioLimon);

    totalCola = cola * precioCola;
    totalNaranja = naranja * precioNaranja;
    totalLimon = limon * precioLimon;

    totalVentas = totalCola + totalNaranja + totalLimon;

    // Mostrar el informe de venta
    printf("Producto\tVenta\t\tPrecio\tTotal\n");
    printf("---------------------------------------------\n");
    printf("Cola\t\t%d\t\t%.2f\t%.2f\n", cola, precioCola, totalCola);
    printf("Naranja\t\t%d\t\t%.2f\t%.2f\n", naranja, precioNaranja, totalNaranja);
    printf("Limón\t\t%d\t\t%.2f\t%.2f\n", limon, precioLimon, totalLimon);
    printf("Total\t\t\t\t\t%.2f\n", totalVentas);

    return 0;
}

