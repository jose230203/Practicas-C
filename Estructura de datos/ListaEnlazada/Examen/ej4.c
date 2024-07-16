#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *izquierda;
    struct Nodo *derecha;
};

struct Nodo* crearNodo(int valor) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = valor;
    nuevoNodo->izquierda = NULL;
    nuevoNodo->derecha = NULL;
    return nuevoNodo;
}

struct Nodo* insertarNodo(struct Nodo* raiz, int valor) {
    if (raiz == NULL) {
        return crearNodo(valor);
    }

    if (valor < raiz->dato) {
        raiz->izquierda = insertarNodo(raiz->izquierda, valor);
    } else if (valor > raiz->dato) {
        raiz->derecha = insertarNodo(raiz->derecha, valor);
    }

    return raiz;
}

void mostrarEnOrden(struct Nodo* raiz) {
    if (raiz != NULL) {
        mostrarEnOrden(raiz->izquierda);
        printf("%d ", raiz->dato);
        mostrarEnOrden(raiz->derecha);
    }
}

struct Nodo* encontrarMin(struct Nodo* nodo) {
    struct Nodo* actual = nodo;
    while (actual && actual->izquierda != NULL) {
        actual = actual->izquierda;
    }
    return actual;
}

struct Nodo* eliminarNodo(struct Nodo* raiz, int valor) {
    if (raiz == NULL) {
        return raiz;
    }

    if (valor < raiz->dato) {
        raiz->izquierda = eliminarNodo(raiz->izquierda, valor);
    } else if (valor > raiz->dato) {
        raiz->derecha = eliminarNodo(raiz->derecha, valor);
    } else {
        if (raiz->izquierda == NULL) {
            struct Nodo* temp = raiz->derecha;
            free(raiz);
            return temp;
        } else if (raiz->derecha == NULL) {
            struct Nodo* temp = raiz->izquierda;
            free(raiz);
            return temp;
        }

        struct Nodo* temp = encontrarMin(raiz->derecha);
        raiz->dato = temp->dato;
        raiz->derecha = eliminarNodo(raiz->derecha, temp->dato);
    }
    return raiz;
}

struct Nodo* encontrarNodo(struct Nodo* raiz, int valor) {
    if (raiz == NULL || raiz->dato == valor) {
        return raiz;
    }

    if (valor < raiz->dato) {
        return encontrarNodo(raiz->izquierda, valor);
    }
    return encontrarNodo(raiz->derecha, valor);
}

void encontrarMax(struct Nodo* raiz) {
    if (raiz == NULL) {
        printf("El arbol esta vacio.\n");
        return;
    }

    while (raiz->derecha != NULL) {
        raiz = raiz->derecha;
    }
    printf("El elemento mayor es: %d\n", raiz->dato);
}

void encontrarMinimo(struct Nodo* raiz) {
    if (raiz == NULL) {
        printf("El arbol esta vacio.\n");
        return;
    }

    while (raiz->izquierda != NULL) {
        raiz = raiz->izquierda;
    }
    printf("El elemento menor es: %d\n", raiz->dato);
}

int main() {
    struct Nodo* raiz = NULL;
    int opcion, valor;

    do {
        printf("\nMenu:\n");
        printf("1. Insertar elemento\n");
        printf("2. Mostrar arbol\n");
        printf("3. Buscar elemento\n");
        printf("4. Eliminar elemento\n");
        printf("5. Mayor elemento\n");
        printf("6. Menor elemento\n");
        printf("7. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el elemento a insertar: ");
                scanf("%d", &valor);
                raiz = insertarNodo(raiz, valor);
                break;
            case 2:
                printf("El arbol en orden es: ");
                mostrarEnOrden(raiz);
                printf("\n");
                break;
            case 3:
                printf("Ingrese el elemento a buscar: ");
                scanf("%d", &valor);
                if (encontrarNodo(raiz, valor) != NULL) {
                    printf("El elemento %d esta en el arbol.\n", valor);
                } else {
                    printf("El elemento %d no esta en el arbol.\n", valor);
                }
                break;
            case 4:
                printf("Ingrese el elemento a eliminar: ");
                scanf("%d", &valor);
                raiz = eliminarNodo(raiz, valor);
                break;
            case 5:
                encontrarMax(raiz);
                break;
            case 6:
                encontrarMinimo(raiz);
                break;
            case 7:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida. Por favor, seleccione una opcion valida.\n");
                break;
        }
    } while (opcion != 7);

    return 0;
}

