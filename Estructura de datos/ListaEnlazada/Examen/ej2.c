#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void insertNode(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
    new_node->prev = last;
}

void displayList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

struct Node* unionLists(struct Node* list1, struct Node* list2) {
    struct Node* result = NULL;
    struct Node* temp = list1;

    while (temp != NULL) {
        insertNode(&result, temp->data);
        temp = temp->next;
    }

    temp = list2;
    while (temp != NULL) {
        insertNode(&result, temp->data);
        temp = temp->next;
    }

    printf("Union de listas realizada: ");
    displayList(result);

    return result;
}

void intersectionLists(struct Node* list1, struct Node* list2) {
    struct Node* result = NULL;
    struct Node* temp = list1;

    while (temp != NULL) {
        struct Node* check = list2;
        while (check != NULL) {
            if (temp->data == check->data) {
                insertNode(&result, temp->data);
                break;
            }
            check = check->next;
        }
        temp = temp->next;
    }

    printf("Interseccion de listas realizada: ");
    displayList(result);
}

void differenceLists(struct Node* list1, struct Node* list2) {
    struct Node* result1 = NULL;
    struct Node* result2 = NULL;
    struct Node* temp = list1;

    while (temp != NULL) {
        struct Node* check = list2;
        int found = 0;
        while (check != NULL) {
            if (temp->data == check->data) {
                found = 1;
                break;
            }
            check = check->next;
        }
        if (!found) {
            insertNode(&result1, temp->data);
        }
        temp = temp->next;
    }

    temp = list2;
    while (temp != NULL) {
        struct Node* check = list1;
        int found = 0;
        while (check != NULL) {
            if (temp->data == check->data) {
                found = 1;
                break;
            }
            check = check->next;
        }
        if (!found) {
            insertNode(&result2, temp->data);
        }
        temp = temp->next;
    }

    printf("Diferencias respecto a Lista 1: ");
    displayList(result1);
    printf("Diferencias respecto a Lista 2: ");
    displayList(result2);
}

void freeList(struct Node* node) {
    struct Node* temp;
    while (node != NULL) {
        temp = node;
        node = node->next;
        free(temp);
    }
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    struct Node* headUnion = NULL;

    int opcion, dato;

    do {
        printf("\nMenu:\n");
        printf("1. Ingresar dato a Lista 1\n");
        printf("2. Ingresar dato a Lista 2\n");
        printf("3. Mostrar Lista 1\n");
        printf("4. Mostrar Lista 2\n");
        printf("5. Union de Listas\n");
        printf("6. Mostrar Lista de Union\n");
        printf("7. Interseccion de Listas\n");
        printf("8. Diferencia de Listas\n");
        printf("9. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("\nIngrese dato para Lista 1: ");
                scanf("%d", &dato);
                insertNode(&head1, dato);
                break;
            case 2:
                printf("\nIngrese dato para Lista 2: ");
                scanf("%d", &dato);
                insertNode(&head2, dato);
                break;
            case 3:
                printf("\nLista 1: ");
                displayList(head1);
                break;
            case 4:
                printf("\nLista 2: ");
                displayList(head2);
                break;
            case 5:
                printf("\nRealizando la union de listas...\n");
                headUnion = unionLists(head1, head2);
                break;
            case 6:
                if (headUnion != NULL) {
                    printf("\nMostrando Lista de Union: ");
                    displayList(headUnion);
                    freeList(headUnion); // Liberar la memoria
                    headUnion = NULL; // Establecer el puntero a NULL
                } else {
                    printf("\nLa Lista de Union esta vacia.\n");
                }
                break;
            case 7:
                printf("\nRealizando la interseccion de listas...\n");
                intersectionLists(head1, head2);
                break;
            case 8:
                printf("\nRealizando la diferencia de listas...\n");
                differenceLists(head1, head2);
                break;
            case 9:
                printf("\nSaliendo del programa...\n");
                break;
            default:
                printf("\nOpcion no valida. Por favor, seleccione una opcion valida.\n");
                break;
        }
    } while (opcion != 9);

    return 0;
}

