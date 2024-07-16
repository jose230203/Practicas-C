#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int i;
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

// Función para concatenar dos pilas
void concatenarPilas(struct Pila *pila1, struct Pila *pila2) {
    while (!estaVacia(pila2)) {
        int elemento = desapilar(pila2);
        apilar(pila1, elemento);
    }
}

// Función para entremezclar dos pilas
struct Pila entremezclarPilas(struct Pila *pila1, struct Pila *pila2) {
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

    int elemento, n;
    
    printf("Ingrese el numero de elementos para la primera pila: ");
    scanf("%d", &n);
    printf("Ingrese los elementos de la primera pila:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &elemento);
        apilar(&pila1, elemento);
    }

    printf("Ingrese el numero de elementos para la segunda pila: ");
    scanf("%d", &n);
    printf("Ingrese los elementos de la segunda pila:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &elemento);
        apilar(&pila2, elemento);
    }

    printf("Concatenando las dos pilas...\n");
    concatenarPilas(&pila1, &pila2);

    printf("Pila concatenada:\n");
    while (!estaVacia(&pila1)) {
        printf("%d ", desapilar(&pila1));
    }
    printf("\n");

    printf("Entremezclando las dos pilas...\n");
    struct Pila pilaResultante = entremezclarPilas(&pila1, &pila2);

    printf("Pila entremezclada:\n");
    while (!estaVacia(&pilaResultante)) {
        printf("%d ", desapilar(&pilaResultante));
    }
    printf("\n");

    return 0;
}

