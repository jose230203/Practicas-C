#include <stdio.h>

#define NUM_EQUIPOS 5
#define NUM_ESTUDIANTES 6
#define TIEMPO_MAXIMO_200M 25.0
#define TIEMPO_MAXIMO_1500M 180.0

int main() {
    int equipoSeleccionado = -1;
    float tiempoTotalSeleccionado = 0.0;
    int i,j;
    float tiempo200m, tiempo1500m;

    for (i = 0; i < NUM_EQUIPOS; i++) {
        int equipoDesestimado = 0;
        float tiempoTotalEquipo = 0.0;

   
        for (j = 0; j < NUM_ESTUDIANTES; j++) {
         

            printf("Ingrese el tiempo del estudiante %d del equipo %d - Carrera 200m: ", j + 1, i + 1);
            scanf("%f", &tiempo200m);

            printf("Ingrese el tiempo del estudiante %d del equipo %d - Carrera 1500m: ", j + 1, i + 1);
            scanf("%f", &tiempo1500m);

            if (tiempo200m > TIEMPO_MAXIMO_200M || tiempo1500m > TIEMPO_MAXIMO_1500M) {
                equipoDesestimado = 1;
                break;
            }

            tiempoTotalEquipo += tiempo200m + tiempo1500m;
        }

        if (!equipoDesestimado) {
            if (equipoSeleccionado == -1 || tiempoTotalEquipo < tiempoTotalSeleccionado) {
                equipoSeleccionado = i;
                tiempoTotalSeleccionado = tiempoTotalEquipo;
            }
        }
    }

    // Mostrar resultado
    if (equipoSeleccionado != -1) {
        printf("El equipo seleccionado es el numero %d\n", equipoSeleccionado + 1);
        printf("Tiempo total del equipo: %.2f\n", tiempoTotalSeleccionado);
    } else {
        printf("No hay equipos que puedan participar en los campeonatos regionales.\n");
    }

    return 0;
}

