#include <stdio.h>
#include <stdlib.h>

#define MAX_COCHES 10
int i,j;
typedef struct {
    char tipo; // 'E' para entrada, 'S' para salida
    char placa[8];
} Coche;

int main() {
    Coche estacionamiento[MAX_COCHES];
    int numCoches = 0;

    printf("Estacionamiento Scratchemup\n");

    while (1) {
        char tipo;
        char placa[8];

        printf("Ingrese 'E' para entrada, 'S' para salida, o 'Q' para salir: ");
        scanf(" %c", &tipo);

        if (tipo == 'Q' || tipo == 'q') {
            break;
        }

        if (tipo != 'E' && tipo != 'S') {
            printf("Entrada no válida. Use 'E' para entrada o 'S' para salida.\n");
            continue;
        }

        printf("Ingrese el número de placa: ");
        scanf("%s", placa);

        if (tipo == 'E') {
            if (numCoches < MAX_COCHES) {
                estacionamiento[numCoches].tipo = 'E';
                strcpy(estacionamiento[numCoches].placa, placa);
                numCoches++;
                printf("Coche con placa %s ha entrado en el estacionamiento.\n", placa);
            } else {
                printf("El estacionamiento está lleno. No se puede ingresar más coches.\n");
            }
        } else { // Salida
            int encontrado = 0;
            for (i = 0; i < numCoches; i++) {
                if (strcmp(estacionamiento[i].placa, placa) == 0) {
                    encontrado = 1;
                    printf("Coche con placa %s ha salido del estacionamiento.\n", placa);
                    for (j = i; j < numCoches - 1; j++) {
                        estacionamiento[j] = estacionamiento[j + 1];
                    }
                    numCoches--;
                    break;
                }
            }

            if (!encontrado) {
                printf("Coche con placa %s no encontrado en el estacionamiento.\n", placa);
            }
        }
    }

    printf("Programa finalizado. Gracias por usar Scratchemup.\n");

    return 0;
}

