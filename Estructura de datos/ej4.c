#include <stdio.h>
#include <stdlib.h>

// Definici�n de la estructura de un nodo
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Definici�n de la estructura de una cola
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Funci�n para inicializar una cola
void initialize(Queue* queue) {
    queue->front = queue->rear = NULL;
}

// Funci�n para verificar si una cola est� vac�a
int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

// Funci�n para encolar un elemento en la cola
void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Funci�n para desencolar un elemento de la cola
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("La cola est� vac�a.\n");
        return -1; // Valor sentinela para indicar error
    }
    int data = queue->front->data;
    Node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    return data;
}

// Funci�n para intercambiar elementos de dos colas manteniendo su orden de salida
void swapQueues(Queue* c1, Queue* c2) {
    Queue temp;
    initialize(&temp);

    // Intercambia los elementos de c1 a temp
    while (!isEmpty(c1)) {
        int data = dequeue(c1);
        enqueue(&temp, data);
    }

    // Intercambia los elementos de c2 a c1
    while (!isEmpty(c2)) {
        int data = dequeue(c2);
        enqueue(c1, data);
    }

    // Intercambia los elementos de temp a c2
    while (!isEmpty(&temp)) {
        int data = dequeue(&temp);
        enqueue(c2, data);
    }
}

int main() {
    Queue C1, C2;
    initialize(&C1);
    initialize(&C2);

    // Agrega elementos a C1 y C2 (puedes modificar esto seg�n tus necesidades)
    enqueue(&C1, 1);
    enqueue(&C1, 2);
    enqueue(&C1, 3);

    enqueue(&C2, 4);
    enqueue(&C2, 5);
    enqueue(&C2, 6);

    printf("Contenido de C1 antes del intercambio:\n");
    while (!isEmpty(&C1)) {
        printf("%d ", dequeue(&C1));
    }
    printf("\n");

    printf("Contenido de C2 antes del intercambio:\n");
    while (!isEmpty(&C2)) {
        printf("%d ", dequeue(&C2));
    }
    printf("\n");

    // Intercambia las colas
    swapQueues(&C1, &C2);

    printf("Contenido de C1 despu�s del intercambio:\n");
    while (!isEmpty(&C1)) {
        printf("%d ", dequeue(&C1));
    }
    printf("\n");

    printf("Contenido de C2 despu�s del intercambio:\n");
    while (!isEmpty(&C2)) {
        printf("%d ", dequeue(&C2));
    }
    printf("\n");

    return 0;
}

