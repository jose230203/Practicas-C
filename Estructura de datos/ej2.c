#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PERSONAS 30
#define PRECIO_ENTRADA 50
int i;
typedef struct {
    int cantidadComprada;
    int montoTotal;
} Boleteria;

int main() {
    srand(time(NULL));

    int lugaresDisponibles;
    int personasEnCola = rand() % (MAX_PERSONAS + 1);
    Boleteria boleteria = {0, 0};

    printf("Simulacion de boleteria de teatro\n");
    printf("Lugares disponibles: ");
    scanf("%d", &lugaresDisponibles);

    printf("Personas en la cola: %d\n", personasEnCola);

    for ( i = 0; i < personasEnCola; i++) {
        int cantidadComprada = rand() % (lugaresDisponibles + 1);
        if (cantidadComprada > 0) {
            int monto = cantidadComprada * PRECIO_ENTRADA;
            boleteria.cantidadComprada += cantidadComprada;
            boleteria.montoTotal += monto;
            lugaresDisponibles -= cantidadComprada;
            printf("Persona %d compro %d entradas por un total de %d\n", i + 1, cantidadComprada, monto);
        }
    }

    printf("Cantidad de personas que compraron entradas: %d\n", boleteria.cantidadComprada);
    printf("Monto total por ventas: %d\n", boleteria.montoTotal);
    printf("Cantidad de entradas sobrantes: %d\n", lugaresDisponibles);

    return 0;
}

