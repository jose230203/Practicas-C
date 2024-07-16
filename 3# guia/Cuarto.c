#include <stdio.h>

int main() {
    int a, b, c;
    float d, e;

    printf("Ingrese el turno (1 = diurno, 2 = nocturno): ");
    scanf("%d", &a);
    printf("Ingrese las horas trabajadas: ");
    scanf("%d", &b);
    printf(" ¿Es domingo? (1 = si, 0 = no): ");
    scanf("%d", &c);

    switch (a) {
        case 1:
            d = c ? 50.0 : 20.0;
            break;
        case 2:
            d = c ? 80.0 : 30.0;
            break;
        default:
            printf("ERROR: turno inválido.\n");
            return 0;
    }

    e = b * d;

    printf("El jornal a pagar es de %.2f cordobas.\n", e);

    return 0;
}
