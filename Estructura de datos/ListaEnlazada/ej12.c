#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Definición de la estructura de nodo de lista enlazada
typedef struct Nodo {
    char palabra[100];
    struct Nodo *siguiente;
} Nodo;

// Función para crear un nuevo nodo
Nodo *crearNodo(const char *palabra) {
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) {
        perror("Error al asignar memoria para el nodo");
        exit(1);
    }
    strcpy(nuevoNodo->palabra, palabra);// Funcion para copiar la Cadena de una variable a otra
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

// Función para insertar un nodo al final de la lista
void insertarNodo(Nodo **lista, const char *palabra) {
    Nodo *nuevoNodo = crearNodo(palabra);
    if (*lista == NULL) {
        *lista = nuevoNodo;
    } else {
        Nodo *actual = *lista;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
}

// Función para imprimir las palabras en la lista
void imprimirLista(Nodo *lista) {
    Nodo *actual = lista;
    while (actual != NULL) {
        printf("%s\n", actual->palabra);
        actual = actual->siguiente;
    }
}

// Función para encontrar palabras comunes entre dos listas
void encontrarPalabrasComunes(Nodo *lista1, Nodo *lista2) {
    while (lista1 != NULL) {
        Nodo *temp = lista2;//Temp sera lista2
        while (temp != NULL) {
            if (strcmp(lista1->palabra, temp->palabra) == 0) {
                printf("Palabra comun: %s\n", lista1->palabra);
                break;
            }
            temp = temp->siguiente;//Siguiente nodo de lista2
        }
        lista1 = lista1->siguiente;//Siguiente nodo lista1
    }
}

// Función para eliminar una palabra de la lista
int eliminarPalabra(Nodo **lista, const char *palabra) {
    Nodo *anterior = NULL;
    Nodo *actual = *lista;

    while (actual != NULL) {
        if (strcmp(actual->palabra, palabra) == 0) {
            if (anterior != NULL) {
                anterior->siguiente = actual->siguiente;
            } else {
                *lista = actual->siguiente;
            }
            free(actual);
            return 1; // Éxito, la palabra se eliminó 1 = true
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    return 0; // La palabra no se encontró 0 = false 
}

// Función para liberar la memoria de la lista
void liberarLista(Nodo *lista) {
    while (lista != NULL) {
        Nodo *temp = lista;
        lista = lista->siguiente;
        free(temp);
    }
}

int main() {
    Nodo *lista1 = NULL; //Creacion de lista1 
    Nodo *lista2 = NULL; //Creacion de lista2 
    char palabra[100];
    int opcion;

    while (1) {
        printf("\nMenu:\n");
        printf("1) Ingresar palabra a F1\n");
        printf("2) Ingresar palabra a F2\n");
        printf("3) Mostrar palabras comunes\n");
        printf("4) Eliminar palabra de lista F1\n");
        printf("5) Eliminar palabra de lista F2\n");
        printf("6) Mostrar lista F1\n");
        printf("7) Mostrar lista F2\n");
        printf("8) Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingresa palabra para F1: ");
                scanf("%s", palabra);
                insertarNodo(&lista1, palabra);
                break;
            case 2:
                printf("Ingresa palabra para F2: ");
                scanf("%s", palabra);
                insertarNodo(&lista2, palabra);
                break;
            case 3:
                printf("Palabras comunes:\n");
                encontrarPalabrasComunes(lista1, lista2);
                break;
            case 4:
                printf("Ingresa palabra a eliminar de lista F1: ");
                scanf("%s", palabra);
                if (eliminarPalabra(&lista1, palabra)) {
                    printf("La palabra %s fue eliminada de lista F1.\n",palabra);
                } else {
                    printf("La palabra %s no se encontro en lista F1.\n");
                }
                break;
            case 5:
                printf("Ingresa palabra a eliminar de lista F2: ",palabra);
                scanf("%s", palabra);
                if (eliminarPalabra(&lista2, palabra)) {
                    printf("La palabra %s fue eliminada de lista F2.\n",palabra);
                } else {
                    printf("La palabra %s no se encontro en lista F2.\n",palabra);
                }
                break;
            case 6:
                printf("Lista F1:\n");
                imprimirLista(lista1);
                break;
            case 7:
                printf("Lista F2:\n");
                imprimirLista(lista2);
                break;
            case 8:
                // Liberar memoria de las listas
                liberarLista(lista1);
                liberarLista(lista2);
                return 0;
            default:
                printf("Opcion no valida. Por favor, elige una opcion valida.\n");
        }
    }

    return 0;
}

