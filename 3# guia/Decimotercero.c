#include <stdio.h>

int main() {
    char a,b;
    int c,d;

    
    printf("Introduce el tipo de vehiculo (C para camion, A para automovil): ");
    scanf(" %c", &a);
    printf("Introduce el tipo de hora (A para alta congestion, B para baja congestion): ");
    scanf(" %c", &b);
    printf("Introduce el numero de pasajeros: ");
    scanf("%d", &c);

   
    if (a == 'C') { 
        if (b == 'A') {
            d = 50;
        } else { 
            d = 30;
        }
    } else {
        if (b == 'A' && c >= 3) {
            d = 0;
        } else {
            d = 25;
        }
    }
    getch();
    printf("La tarifa a cobrar es de %d euros.\n", d);

    return 0;
}

