#include <stdio.h>

int main() {
    int ventas200OMenos = 0;
    int ventasEntre200y400 = 0;
    int ventas400OSuperiores = 0;
    int venta;
    int i;

    for (i = 1; i <= 6; i++) {
        printf("Ingrese el monto de la venta %d: C$", i);
        scanf("%d", &venta);

        if (venta <= 200) {
            ventas200OMenos++;
        } else if (venta > 200 && venta < 400) {
            ventasEntre200y400++;
        } else {
            ventas400OSuperiores++;
        }
    }

    printf("Cantidad de ventas de C$200 o menos: %d\n", ventas200OMenos);
    printf("Cantidad de ventas mayores a C$200 pero inferiores a C$400: %d\n", ventasEntre200y400);
    printf("Cantidad de ventas de C$400 o superiores: %d\n", ventas400OSuperiores);

    return 0;
}

