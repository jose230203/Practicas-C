#include <stdio.h>

int main() {
    char codigo;
    float costo;
    float venta;
    int cantidad;
    int i;
    float gan = 0;
    float gananciapro;
    // Ingresar los datos de cada producto
    for (i = 0; i < 3; i++){
        printf("Ingrese los datos del producto %c:\n", 'A' + i);
        printf("codigo: ");
        scanf(" %c", &codigo);
        printf("Precio de costo: ");
        scanf("%f", &costo);
        printf("Precio de venta: ");
        scanf("%f", &venta);
        printf("Cantidad vendida: ");
        scanf("%d", &cantidad);
        printf("\n");
        gananciapro=((venta - costo) * cantidad);
        gan += gananciapro;
    }
    printf("Las ganancias totales de la tienda son: %.2f\n", gan);

    return 0;
}

