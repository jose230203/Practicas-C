#include <stdio.h>

int main() {
    float nota;

    while (1) {
        printf("Ingrese la nota de la asignatura: ");
        scanf("%f", &nota);

        if (nota >= 0 && nota <= 10) {
            break;
        } else {
            printf("ERROR: Nota incorrecta, debe ser >= 0 y <= 10\n");
        }
    }

    if (nota >= 5) {
        printf("APROBADO\n");
    } else {
        printf("SUSPENDIDO\n");
    }

    return 0;
}

