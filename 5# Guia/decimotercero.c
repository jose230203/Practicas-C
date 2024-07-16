#include <stdio.h>

int main() {
    const int LIMITE_1 = 100;	
    const int LIMITE_2 = 300;
    const int LIMITE_3 = 500;
    const int LIMITE_4 = 700;
    const float COMISION_1 = 0.03;
    const float COMISION_2 = 0.04;
    const float COMISION_3 = 0.05;
    const float COMISION_4 = 0.06;

    int i,ventas;	
    float comision;

    for (i = 0; i < 20; i++) {
        printf("Ingrese las ventas del vendedor %d: ", i + 1);
        scanf("%d", &ventas);

        if (ventas < LIMITE_2) {
            comision = ventas * COMISION_1;
        } else if (ventas < LIMITE_3) {
            comision = ventas * COMISION_2;
        } else if (ventas < LIMITE_4) {
            comision = ventas * COMISION_3;
        } else {
            comision = ventas * COMISION_4;
        }

        printf("Comision anual del vendedor %d: %.2f\n", i + 1, comision);
    }

    return 0;
}
