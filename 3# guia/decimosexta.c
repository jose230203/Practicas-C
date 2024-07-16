#include <stdio.h>

int main() {
    float a, b,c,d;
    
    printf("Ingrese la cantidad de kilogramos de manzanas comprados: ");
    scanf("%f", &a);
    printf("Cuanto es su total a pagar?");
    scanf("%f",&c);
    
    if (a >= 0 && a <= 2) {
        b = 0;
    } else if (a > 2 && a <= 5) {
        b = 0.1;
    } else if (a > 5 && a <= 10) {
        b = 0.15;
    } else if (a > 10) {
        b = 0.2;
    } else {
        printf("Cantidad de kilogramos no válida.\n");
        return 1;
    }
    d = c * (1 - b);
    
    printf("El precio total es: $%.2f\n", c);
    printf("El descuento aplicado es: %.0f%%\n", b * 100);
    printf("El precio con descuento es: $%.2f\n", d);
    
    return 0;
}

