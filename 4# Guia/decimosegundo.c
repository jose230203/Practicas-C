#include <stdio.h>

int main() {
    char color;
    int per;
    float monto, descuento, montoFinal;
    printf("Cuantas clientes calculara?");
    scanf("%d",&per);
    do
    {
    printf("Ingrese el color del papelito (B: blanco, V: verde, R: rojo): ");
    scanf(" %c", &color);

    printf("Ingrese el monto de la compra: $");
    scanf("%f", &monto);

    switch (color) {
        case 'B':
            descuento = 2.63;
            break;
        case 'V':
            descuento = 4.85;
            break;
        case 'R':
            descuento = 5.02;
            break;
        default:
            descuento = 0.0;
            printf("Color de papelito inválido. No se aplica descuento.\n");
            break;
    }

    if (descuento > 0.0) {
        montoFinal = monto - (monto * (descuento / 100.0));
        printf("El monto a pagar con descuento es: $%.2f\n", montoFinal);
    }
    per--;
}while(per>0);
    return 0;
}

