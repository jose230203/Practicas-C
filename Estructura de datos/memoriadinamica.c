/*Memoria dinamica*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int* arreglo = NULL;
    int tamaniooInicial = 10;
    int nuevoTamanioo = 20;

    // Asignar memoria para el arreglo inicial
    arreglo = (int*)malloc(tamaniooInicial * sizeof(int));

    if (arreglo == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }

    // Llenar el arreglo inicial con datos (opcional)
    for (int i = 0; i < tamaniooInicial; i++) {
        arreglo[i] = i;
    }

    // Cambiar el tamaño del arreglo
    int* nuevoArreglo = (int*)realloc(arreglo, nuevoTamanioo * sizeof(int));

    if (nuevoArreglo == NULL) {
        printf("Error: No se pudo redimensionar el arreglo.\n");
        free(arreglo); // Liberar la memoria del arreglo original
        return 1;
    }

    arreglo = nuevoArreglo; // Actualizar el puntero al nuevo arreglo

    // Llenar el espacio adicional en el nuevo arreglo (opcional)
    for (int i = tamaniooInicial; i < nuevoTamanioo; i++) {
        arreglo[i] = i;
    }

    // Imprimir los elementos del nuevo arreglo
    for (int i = 0; i < nuevoTamanioo; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    // Liberar la memoria del nuevo arreglo cuando ya no sea necesario
    free(arreglo);

    return 0;
}

