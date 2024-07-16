#include <stdio.h>

int main() {
    int num_materias,i;
    float calificacion, creditos,promedio_ponderado;
    float suma_calificaciones = 0, suma_creditos = 0;

    printf("Ingrese el numero de materias: ");
    scanf("%d", &num_materias);

    for (i = 1; i <= num_materias; i++) {
        printf("Ingrese la calificacion de la materia %d: ", i);
        scanf("%f", &calificacion);

        printf("Ingrese los creditos de la materia %d: ", i);
        scanf("%f", &creditos);

        suma_calificaciones += calificacion * creditos;
        suma_creditos += creditos;
    }

  promedio_ponderado = suma_calificaciones / suma_creditos;

    printf("El promedio ponderado del alumno es: %.2f\n", promedio_ponderado);

    return 0;
}

