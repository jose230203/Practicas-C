#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo para la pila y la cola
struct Nodo {
    int dato;
    struct Nodo* siguiente;
};

// Definición de la estructura de la pila
struct Pila {
    struct Nodo* tope; // Puntero al nodo superior (último en entrar)
};

// Definición de la estructura de la cola
struct Cola {
    struct Nodo* frente; // Puntero al nodo frontal (primero en entrar)
    struct Nodo* final;  // Puntero al nodo final (último en entrar)
};

// Función para crear una nueva pila vacía
struct Pila* crearPila() {
    struct Pila* pila = (struct Pila*)malloc(sizeof(struct Pila));
    pila->tope = NULL; // Inicialmente, la pila está vacía
    return pila;
}

// Función para crear una nueva cola vacía
struct Cola* crearCola() {
    struct Cola* cola = (struct Cola*)malloc(sizeof(struct Cola));
    cola->frente = cola->final = NULL; // Inicialmente, la cola está vacía
    return cola;
}

// Función para insertar un elemento en la pila (push)
void push(struct Pila* pila, int dato) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = pila->tope;
    pila->tope = nuevoNodo;
}

// Función para eliminar y obtener el elemento superior de la pila (pop)
int pop(struct Pila* pila) {
    if (pila->tope == NULL) {
        printf("La pila está vacía. No se puede hacer pop.\n");
        return -1;
    }
    struct Nodo* nodoAEliminar = pila->tope;
    int dato = nodoAEliminar->dato;
    pila->tope = nodoAEliminar->siguiente;
    free(nodoAEliminar);
    return dato;
}

// Función para insertar un elemento en la cola (enqueue)
void enqueue(struct Cola* cola, int dato) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    if (cola->final == NULL) {
        cola->frente = cola->final = nuevoNodo;
    } else {
        cola->final->siguiente = nuevoNodo;
        cola->final = nuevoNodo;
    }
}

// Función para eliminar y obtener el elemento frontal de la cola (dequeue)
int dequeue(struct Cola* cola) {
    if (cola->frente == NULL) {
        printf("La cola está vacía. No se puede hacer dequeue.\n");
        return -1;
    }
    struct Nodo* nodoAEliminar = cola->frente;
    int dato = nodoAEliminar->dato;
    cola->frente = nodoAEliminar->siguiente;
    if (cola->frente == NULL) {
        cola->final = NULL; // Si la cola se queda vacía, actualizamos el puntero al final
    }
    free(nodoAEliminar);
    return dato;
}

int main() {
    struct Pila* miPila = crearPila();
    struct Cola* miCola = crearCola();

    // Insertar elementos en la pila y la cola
    push(miPila, 10);
    push(miPila, 20);
    enqueue(miCola, 30);
    enqueue(miCola, 40);

    // Sacar y mostrar elementos de la pila
    printf("Elementos en la pila:\n");
    while (miPila->tope != NULL) {
        int dato = pop(miPila);
        printf("%d ", dato);
    }
    printf("\n");

    // Sacar y mostrar elementos de la cola
    printf("Elementos en la cola:\n");
    while (miCola->frente != NULL) {
        int dato = dequeue(miCola);
        printf("%d ", dato);
    }
    printf("\n");

    return 0;
}

