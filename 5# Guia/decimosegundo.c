#include <stdio.h>

int main() {
    float montoVenta;
    float iva;
    float totalPagar;
    float cantidadPago;
    float cambio;
    float totalCaja = 0;

    int numClientes,i;

    printf("Ingrese el numero de clientes: ");
    scanf("%d", &numClientes);

    for (i = 1; i <= numClientes; i++) {
        printf("\nCliente %d:\n", i);

        printf("Monto de la venta: $");
        scanf("%f", &montoVenta);

        iva = montoVenta * 0.09;
        totalPagar = montoVenta + iva;

        printf("IVA: $%.2f\n", iva);
        printf("Total a pagar: $%.2f\n", totalPagar);

        printf("Cantidad con la que paga el cliente: $");
        scanf("%f", &cantidadPago);

        cambio = cantidadPago - totalPagar;
        totalCaja += totalPagar;

        printf("Cambio: $%.2f\n", cambio);
    }

    printf("\nCantidad de dinero en la caja al final del dia: $%.2f\n", totalCaja);

    return 0;
}

