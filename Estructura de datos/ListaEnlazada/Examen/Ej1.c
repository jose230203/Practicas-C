#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int i;

// Estructura del nodo
struct Node {
    int data;
    struct Node* next;
};

// Función para insertar un nodo al final de la lista
void insertNode(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

// Función para mostrar los elementos de la lista
void displayList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Función para eliminar nodos que superen un valor dado
void deleteNodesGreaterThan(struct Node** head_ref, int value) {
    struct Node* current = *head_ref;
    struct Node* prev = NULL;
    struct Node* temp = NULL;

    while (current != NULL && current->data > value) {
        temp = current;
        *head_ref = current->next;
        free(temp);
        current = *head_ref;
    }

    while (current != NULL) {
        while (current != NULL && current->data <= value) {
            prev = current;
            current = current->next;
        }

        if (current == NULL) {
            return;
        }

        prev->next = current->next;
        free(current);
        current = prev->next;
    }
}

int main() {
    struct Node* head = NULL;
    srand(time(0)); // Inicializar la semilla para números aleatorios

    // Crear una lista enlazada de números enteros positivos al azar
    for (i = 0; i < 10; i++) {
        insertNode(&head, rand() % 100); // Números aleatorios entre 0 y 99
    }

    int opcion;
    int valorMaximo;

    do {
        printf("\nMenu:\n");
        printf("1. Mostrar lista original\n");
        printf("2. Eliminar nodos mayores que un valor dado\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("\nLista original: ");
                displayList(head);
                break;
            case 2:
                printf("\nIngrese el valor maximo: ");
                scanf("%d", &valorMaximo);
                deleteNodesGreaterThan(&head, valorMaximo);
                printf("Lista despues de eliminar nodos mayores que %d: ", valorMaximo);
                displayList(head);
                break;
            case 3:
                printf("\nSaliendo del programa...\n");
                break;
            default:
                printf("\nOpcion no valida. Por favor, seleccione una opcion valida.\n");
                break;
        }
    } while (opcion != 3);

    return 0;
}

