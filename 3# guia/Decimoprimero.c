#include <stdio.h>

int main() {
    float a, b, c;
    char d;
    
    printf("Ingrese el valor total de la compra: ");
    scanf("%f", &a);
    
    printf("Seleccione el color de la bolita (W=blanco, G=verde, Y=amarilla, B=azul, R=roja): ");
    scanf(" %c", &d);
    
    switch(d) {
        case 'W':
            b = 0;
            break;
        case 'G':
            b = 0.1 * a;
            break;
        case 'Y':
            b = 0.25 * a;
            break;
        case 'B':
            b = 0.5 * a;
            break;
        case 'R':
            b = a;
            break;
        default:
            printf("Color de bolita no válido.\n");
            return 1;
    }
    
    c = a - b;
    
    printf("El valor final de la compra es: %.2f\n", c);
    
    return 0;
}

