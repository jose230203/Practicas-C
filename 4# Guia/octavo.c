#include <stdio.h>

int main() {
    int edad, antiguedad;
    int sumaAntiguedad = 0;
    int pagoQuincenal,i;

    printf("Ingrese la edad del empleado: ");
    scanf("%d", &edad);

    printf("Ingrese los anos de antiguedad del empleado: ");
    scanf("%d", &antiguedad);

    for (i = 1; i <= antiguedad; i++) {
        sumaAntiguedad += i;
    }

    pagoQuincenal = 100 + edad + sumaAntiguedad;

    printf("El pago quincenal del empleado es: $%d\n", pagoQuincenal);

    return 0;
}

