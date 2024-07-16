#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Definición de la estructura de la pila
struct Pila {
    int elementos[MAX];
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
    return (pila->tope == MAX - 1);
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

// Función para contar la cantidad de elementos en una pila
int contarElementos(struct Pila *pila) {
    return (pila->tope + 1);
}

// Función para mostrar el contenido de una pila
void mostrarPila(struct Pila *pila) {
    printf("Contenido de la pila:\n");
    while (!estaVacia(pila)) {
        printf("%d ", desapilar(pila));
    }
    printf("\n");
}

// Función para intercalar dos pilas
struct Pila intercalarPilas(struct Pila *pila1, struct Pila *pila2) {
    struct Pila pilaResultante;
    inicializar(&pilaResultante);

    while (!estaVacia(pila1) || !estaVacia(pila2)) {
        if (!estaVacia(pila1)) {
            apilar(&pilaResultante, desapilar(pila1));
        }
        if (!estaVacia(pila2)) {
            apilar(&pilaResultante, desapilar(pila2));
        }
    }

    return pilaResultante;
}

int main() {
    struct Pila pila1, pila2;
    inicializar(&pila1);
    inicializar(&pila2);

    int opcion;
    int elemento;

    do {
        printf("\nMenú:\n");
        printf("1. Insertar en Pila 1\n");
        printf("2. Insertar en Pila 2\n");
        printf("3. Mostrar Pila 1\n");
        printf("4. Mostrar Pila 2\n");
        printf("5. Cantidad de elementos en Pila 1\n");
        printf("6. Cantidad de elementos en Pila 2\n");
        printf("7. Intercalar las Pilas\n");
        printf("8. Salir\n");
        printf("Elija una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese un elemento para Pila 1: ");
                scanf("%d", &elemento);
                apilar(&pila1, elemento);
                break;

            case 2:
                printf("Ingrese un elemento para Pila 2: ");
                scanf("%d", &elemento);
                apilar(&pila2, elemento);
                break;

            case 3:
                mostrarPila(&pila1);
                break;

            case 4:
                mostrarPila(&pila2);
                break;

            case 5:
                printf("Cantidad de elementos en Pila 1: %d\n", contarElementos(&pila1));
                break;

            case 6:
                printf("Cantidad de elementos en Pila 2: %d\n", contarElementos(&pila2));
                break;

            case 7:
                printf("Intercalando las Pilas...\n");
                struct Pila pilaIntercalada = intercalarPilas(&pila1, &pila2);
                mostrarPila(&pilaIntercalada);
                break;

            case 8:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }

    } while (opcion != 8);

    return 0;
}

