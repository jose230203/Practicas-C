#include <stdio.h>

int main() {
    float base, altura;
    int areasCalc = 0;

    while (1) {
        printf("Ingrese la base del triangulo (0 para salir): ");
        scanf("%f", &base);

        printf("Ingrese la altura del triangulo (0 para salir): ");
        scanf("%f", &altura);

        if (base != 0 && altura != 0) {
            float area = base * altura / 2;
            printf("El area del triangulo es: %.2f\n", area);
            areasCalc++;
        } else {
            break;
        }
    }

    printf("Se calcularon %d areas de triangulos\n", areasCalc);

    return 0;
}

