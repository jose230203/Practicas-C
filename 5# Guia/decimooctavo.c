#include <stdio.h>

int main() {
    int calificacion, contador_menor_100 = 0, contador_90_99 = 0, contador_80_89 = 0, contador_70_79 = 0;

    for (int i = 1; i <= 25; i++) {
        printf("Ingrese la calificaci�n del estudiante %d: ", i);
        scanf("%d", &calificacion);

        if (calificacion < 100) {
            contador_menor_100++;
        } else if (calificacion >= 90 && calificacion < 100) {
            contador_90_99++;
        } else if (calificacion >= 80 && calificacion < 90) {
            contador_80_89++;
        } else if (calificacion >= 70 && calificacion < 80) {
            contador_70_79++;
        }
    }

    printf("Cantidad de estudiantes con calificaci�n menor a 100: %d\n", contador_menor_100);
    printf("Cantidad de estudiantes con calificaci�n de 90 o m�s pero menor que 100: %d\n", contador_90_99);
    printf("Cantidad de estudiantes con calificaci�n de 80 o m�s pero menor que 90: %d\n", contador_80_89);
    printf("Cantidad de estudiantes con calificaci�n de 70 o m�s pero menor a 80: %d\n", contador_70_79);

    return 0;
}

