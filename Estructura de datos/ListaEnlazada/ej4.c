#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Nodo {
    float temperatura;
    struct Nodo* siguiente;
};

struct Nodo* CrearNodo(float temperatura) {
    struct Nodo* nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->temperatura = temperatura;
    nuevo->siguiente = NULL;
    return nuevo;
}

void AgregarNodo(struct Nodo** cabeza, float temperatura) {
    struct Nodo* nuevo = CrearNodo(temperatura);
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}

void ImprimirLista(struct Nodo* cabeza) {
    struct Nodo* actual = cabeza;
    while (actual != NULL) {
        printf("%.1f ", actual->temperatura);
        actual = actual->siguiente;
    }
    printf("\n");
}

void SepararTemperaturas(struct Nodo* lista, struct Nodo** menor, struct Nodo** mayor, struct Nodo** rango) {
    struct Nodo* actual = lista;
    
    while (actual != NULL) {
        if (actual->temperatura < 0) {
            AgregarNodo(menor, actual->temperatura);
        } else if (actual->temperatura > 10) {
            AgregarNodo(mayor, actual->temperatura);
        } else {
            AgregarNodo(rango, actual->temperatura);
        }
        
        actual = actual->siguiente;
    }
}

int main() {
	int i;
    struct Nodo* listaTemperaturas = NULL;
    struct Nodo* listaMenor0 = NULL;
    struct Nodo* listaMayor10 = NULL;
    struct Nodo* listaRango0_9 = NULL;

    // Inicializar el generador de números aleatorios
    srand(time(NULL));

    // Generar 30 temperaturas aleatorias en el rango de -40 a 40
    for (i = 0; i < 30; i++) {
        float temperatura = (float)(rand() % 81 - 40);
        AgregarNodo(&listaTemperaturas, temperatura);
    }

    // Separar las temperaturas en las tres listas
    SepararTemperaturas(listaTemperaturas, &listaMenor0, &listaMayor10, &listaRango0_9);

    // Imprimir las tres listas
    printf("Temperaturas menores a 0: ");
    ImprimirLista(listaMenor0);

    printf("Temperaturas mayores a 10: ");
    ImprimirLista(listaMayor10);

    printf("Temperaturas en el rango 0-9: ");
    ImprimirLista(listaRango0_9);

    // Liberar la memoria
    free(listaMenor0);
    free(listaMayor10);
    free(listaRango0_9);

    return 0;
}

