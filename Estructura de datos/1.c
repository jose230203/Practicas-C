#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

// Estructura para representar una llamada
typedef struct {
    int tiempo_llegada;
} Llamada;

// Cola para almacenar las llamadas en espera
typedef struct Nodo {
    Llamada llamada;
    struct Nodo* siguiente;
} Nodo;

typedef struct {
    Nodo* frente;
    Nodo* final;
} Cola;

// Inicializar la cola
void inicializarCola(Cola* cola) {
    cola->frente = NULL;
    cola->final = NULL;
}

// Insertar una llamada en la cola
void encolar(Cola* cola, Llamada llamada) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->llamada = llamada;
    nuevoNodo->siguiente = NULL;
    if (cola->final == NULL) {
        cola->frente = nuevoNodo;
        cola->final = nuevoNodo;
    } else {
        cola->final->siguiente = nuevoNodo;
        cola->final = nuevoNodo;
    }
}

// Desencolar una llamada de la cola
Llamada desencolar(Cola* cola) {
    if (cola->frente == NULL) {
        Llamada llamadaVacia;
        llamadaVacia.tiempo_llegada = -1; // Valor indicativo de llamada vacía
        return llamadaVacia;
    }
    Nodo* nodoAEliminar = cola->frente;
    Llamada llamada = nodoAEliminar->llamada;
    cola->frente = cola->frente->siguiente;
    free(nodoAEliminar);
    if (cola->frente == NULL) {
        cola->final = NULL;
    }
    return llamada;
}

// Verificar si la cola está vacía
bool colaVacia(Cola* cola) {
    return cola->frente == NULL;
}

// Generar un número aleatorio entre min y max
int generarNumeroAleatorio(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Simulación del centro de información de reserva con un solo empleado
int main() {
    srand(time(NULL)); // Inicializar el generador de números aleatorios
    
    Cola cola_llamadas;
    inicializarCola(&cola_llamadas);
    
    int tiempo_simulacion = 60; // Duración de la simulación en segundos
    int tiempo_transcurrido = 0;
    
    bool empleado_disponible = true; // Estado inicial del empleado
    int llamadas_en_cola = 0; // Contador de llamadas en cola
    
    while (tiempo_transcurrido < tiempo_simulacion) {
        // Generar una nueva llamada con una probabilidad aleatoria
        if (rand() % 100 < 40) { // Probabilidad del 40%
            Llamada nueva_llamada;
            nueva_llamada.tiempo_llegada = tiempo_transcurrido;
            encolar(&cola_llamadas, nueva_llamada);
            llamadas_en_cola++; // Incrementar el contador
            printf("Nueva llamada en espera. Total de llamadas en cola: %d\n", llamadas_en_cola);
        }
        
        // Verificar si el empleado está disponible para atender llamadas
        if (empleado_disponible && !colaVacia(&cola_llamadas)) {
            Llamada llamada = desencolar(&cola_llamadas);
            printf("Atendiendo llamada...\n");
            int tiempo_atencion = generarNumeroAleatorio(3, 7); // Tiempo aleatorio de atención
            sleep(tiempo_atencion);
            printf("Llamada atendida en %d segundos\n", tiempo_atencion);
            empleado_disponible = false; // El empleado está ocupado
            llamadas_en_cola--; // Decrementar el contador
        }
        
        // Verificar si el empleado vuelve a estar disponible
        if (!empleado_disponible) {
            empleado_disponible = rand() % 2 == 1; // 50% de probabilidad de estar disponible
            if (empleado_disponible) {
                printf("El empleado esta disponible de nuevo.\n");
            }
        }
        
        tiempo_transcurrido += 1; // Incrementar el tiempo en 1 segundo
        sleep(1); // Simular el paso del tiempo
    }
    
    return 0;
}

