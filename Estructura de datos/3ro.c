#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PILAS 10  // Número máximo de pilas
#define MAX_OPERACIONES 1000  // Número máximo de operaciones por pila
int i;
// Definición de la estructura de la pila
struct Pila {
    int elementos[MAX_OPERACIONES];
    int tope;
};

// Función para inicializar una pila
void inicializar(struct Pila *pila) {
    pila->tope = -1;
}

// Función para verificar si una pila está vacía
int estaVacia(struct Pila *pila) {
    return (pila->tope == -1);
}

// Función para verificar si una pila está llena
int estaLlena(struct Pila *pila) {
    return (pila->tope == MAX_OPERACIONES - 1);
}

// Función para apilar un elemento en una pila
void apilar(struct Pila *pila, int elemento) {
    if (!estaLlena(pila)) {
        pila->elementos[++(pila->tope)] = elemento;
    }
}

// Función para desapilar un elemento de una pila
int desapilar(struct Pila *pila) {
    if (!estaVacia(pila)) {
        return pila->elementos[(pila->tope)--];
    }
    return -1; // Valor especial para indicar pila vacía
}

int main() {
    srand(time(NULL)); // Inicializar la semilla aleatoria
    int numPilas;

    printf("Ingrese el numero de pilas a simular: ");
    scanf("%d", &numPilas);

    if (numPilas < 1 || numPilas > MAX_PILAS) {
        printf("Numero de pilas no valido. Debe estar entre 1 y %d.\n", MAX_PILAS);
        return 1;
    }

    struct Pila pilas[MAX_PILAS];
    int trabajoPilas[MAX_PILAS] = {0}; // Array para rastrear el trabajo en cada pila

    for (i = 0; i < numPilas; i++) {
        inicializar(&pilas[i]);
    }

    int numOperaciones;
    printf("Ingrese el numero de operaciones a simular: ");
    scanf("%d", &numOperaciones);

    if (numOperaciones < 1 || numOperaciones > MAX_OPERACIONES) {
        printf("Numero de operaciones no valido. Debe estar entre 1 y %d.\n", MAX_OPERACIONES);
        return 1;
    }

    // Simulación de operaciones aleatorias en las pilas
    for (i = 0; i < numOperaciones; i++) {
        int pilaAleatoria = rand() % numPilas;
        int operacion = rand() % 2; // 0 para apilar, 1 para desapilar

        if (operacion == 0) {
            apilar(&pilas[pilaAleatoria], rand() % 100); // Elemento aleatorio entre 0 y 99
        } else {
            desapilar(&pilas[pilaAleatoria]);
        }

        // Actualizar el trabajo de la pila
        trabajoPilas[pilaAleatoria]++;
    }

    // Encontrar la pila de mayor y menor trabajo
    int maxTrabajo = trabajoPilas[0];
    int minTrabajo = trabajoPilas[0];
    int maxPila = 0;
    int minPila = 0;

    for (i = 1; i < numPilas; i++) {
        if (trabajoPilas[i] > maxTrabajo) {
            maxTrabajo = trabajoPilas[i];
            maxPila = i;
        }
        if (trabajoPilas[i] < minTrabajo) {
            minTrabajo = trabajoPilas[i];
            minPila = i;
        }
    }

    printf("\nResultado de la simulación:\n");
    for (i = 0; i < numPilas; i++) {
        printf("Pila %d: Trabajo = %d\n", i + 1, trabajoPilas[i]);
    }

    printf("La pila de mayor trabajo es la Pila %d con %d operaciones.\n", maxPila + 1, maxTrabajo);
    printf("La pila de menor trabajo es la Pila %d con %d operaciones.\n", minPila + 1, minTrabajo);

    return 0;
}

