#include <stdio.h>

int main() {
    int edad,i;
    int totalDia = 0;
    int totalTarde = 0;
    int totalNoche = 0;
    float promedioDia = 0.0;
    float promedioTarde = 0.0;
    float promedioNoche = 0.0;

    // Turno mañana
    printf("Ingrese las edades de los estudiantes del turno Dia:\n");
    for (i = 0; i < 5; i++) {
        printf("Estudiante %d: ", i + 1);
        scanf("%d", &edad);
        totalDia += edad;
    }
    promedioDia = totalDia / 5.0;

    // Turno tarde
    printf("\nIngrese las edades de los estudiantes del turno tarde:\n");
    for (i = 0; i < 6; i++) {
        printf("Estudiante %d: ", i + 1);
        scanf("%d", &edad);
        totalTarde += edad;
    }
    promedioTarde = totalTarde / 6.0;

    // Turno noche
    printf("\nIngrese las edades de los estudiantes del turno noche:\n");
    for (i = 0; i < 11; i++) {
        printf("Estudiante %d: ", i + 1);
        scanf("%d", &edad);
        totalNoche += edad;
    }
    promedioNoche = totalNoche / 11.0;

    // Impresión de los promedios de cada turno
    printf("\nPromedio de edades - Turno Dia: %.2f\n", promedioDia);
    printf("Promedio de edades - Turno tarde: %.2f\n", promedioTarde);
    printf("Promedio de edades - Turno noche: %.2f\n", promedioNoche);

    return 0;
}

