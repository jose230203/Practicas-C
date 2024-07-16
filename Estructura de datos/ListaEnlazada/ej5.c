#include <stdio.h>
#include <stdlib.h>

// Estructura para representar un nodo de la lista de enteros
struct NodoEntero {
    int valor;
    struct NodoEntero* siguiente;
};

// Función para crear un nuevo nodo de la lista
struct NodoEntero* CrearNodoEntero(int valor) {
    struct NodoEntero* nuevo = (struct NodoEntero*)malloc(sizeof(struct NodoEntero));
    nuevo->valor = valor;
    nuevo->siguiente = NULL;
    return nuevo;
}

// Función para agregar un nodo al inicio de la lista
void AgregarNodoEntero(struct NodoEntero** cabeza, int valor) {
    struct NodoEntero* nuevo = CrearNodoEntero(valor);
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}

// Función para imprimir una lista de enteros
void ImprimirListaEnteros(struct NodoEntero* cabeza) {
    struct NodoEntero* actual = cabeza;
    while (actual != NULL) {
        printf("%d ", actual->valor);
        actual = actual->siguiente;
    }
    printf("\n");
}

// Función para invertir una lista de enteros
void InvertirListaEnteros(struct NodoEntero** cabeza) {
    struct NodoEntero* anterior = NULL;
    struct NodoEntero* actual = *cabeza;
    struct NodoEntero* siguiente = NULL;

    while (actual != NULL) {
        siguiente = actual->siguiente;
        actual->siguiente = anterior;
        anterior = actual;
        actual = siguiente;
    }

    *cabeza = anterior;
}

// Función para formar una lista con elementos comunes de dos listas
struct NodoEntero* IntersectarListas(struct NodoEntero* lista1, struct NodoEntero* lista2) {
    struct NodoEntero* resultado = NULL;

    while (lista1 != NULL) {
        int valor = lista1->valor;
        struct NodoEntero* temp = lista2;

        while (temp != NULL) {
            if (temp->valor == valor) {
                AgregarNodoEntero(&resultado, valor);
                break;
            }
            temp = temp->siguiente;
        }

        lista1 = lista1->siguiente;
    }

    return resultado;
}

// Función para calcular la longitud de una lista de enteros
int LongitudListaEnteros(struct NodoEntero* cabeza) {
    int longitud = 0;
    struct NodoEntero* actual = cabeza;
    
    while (actual != NULL) {
        longitud++;
        actual = actual->siguiente;
    }
    
    return longitud;
}

// Función para mover un nodo j, n posiciones más adelante
void MoverNodoAdelante(struct NodoEntero** cabeza, int j, int n) {
    if (n <= 0) {
        return;
    }

    struct NodoEntero* actual = *cabeza;
    struct NodoEntero* nodoJ = NULL;

    int posicion = 0;
    while (actual != NULL) {
        if (posicion == j) {
            nodoJ = actual;
            break;
        }
        posicion++;
        actual = actual->siguiente;
    }

    if (nodoJ == NULL) {
        return;
    }

    if (j == 0) {
        *cabeza = nodoJ->siguiente;
    } else {
        actual = *cabeza;
        for (posicion = 0; posicion < j - 1 && actual != NULL; posicion++) {
            actual = actual->siguiente;
        }
        if (actual != NULL) {
            actual->siguiente = nodoJ->siguiente;
        }
    }

    actual = *cabeza;
    for (posicion = 0; posicion < n && actual != NULL; posicion++) {
        if (posicion == n - 1) {
            nodoJ->siguiente = actual->siguiente;
            actual->siguiente = nodoJ;
            break;
        }
        actual = actual->siguiente;
    }
}


int main() {
    struct NodoEntero* lista = NULL;

    int opcion;
    int valor;
    int j, n;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Agregar elemento a la lista\n");
        printf("2. Invertir la lista\n");
        printf("3. Formar una lista con elementos comunes de dos\n");
        printf("4. Calcular la longitud de la lista\n");
        printf("5. Mover un nodo j, n posiciones mas adelante\n");
        printf("6. Mostrar lista\n");
        printf("7. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese un valor a agregar a la lista: ");
                scanf("%d", &valor);
                AgregarNodoEntero(&lista, valor);
                break;
            case 2:
                InvertirListaEnteros(&lista);
                printf("Lista invertida.\n");
                break;
            case 3: {
                struct NodoEntero* lista2 = NULL;
                printf("Ingrese valores para la segunda lista (0 para terminar):\n");
                while (1) {
                    scanf("%d", &valor);
                    if (valor == 0)
                        break;
                    AgregarNodoEntero(&lista2, valor);
                }
                struct NodoEntero* resultado = IntersectarListas(lista, lista2);
                printf("Elementos comunes entre las dos listas: ");
                ImprimirListaEnteros(resultado);
                free(resultado);
                break;
            }
            case 4:
                printf("Longitud de la lista: %d\n", LongitudListaEnteros(lista));
                break;
            case 5:
                printf("Ingrese el indice del nodo a mover (j): ");
                scanf("%d", &j);
                printf("Ingrese la cantidad de posiciones a mover (n): ");
                scanf("%d", &n);
                MoverNodoAdelante(&lista, j, n);
                break;
            case 6:
                printf("Lista actual: ");
                ImprimirListaEnteros(lista);
                break;
            case 7:
                // Liberar la memoria y salir
                while (lista != NULL) {
                    struct NodoEntero* temp = lista;
                    lista = lista->siguiente;
                    free(temp);
                }
                return 0;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
                break;
        }
    }

    return 0;
}

