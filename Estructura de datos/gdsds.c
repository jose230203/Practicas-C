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

// Simulación del centro de información de reserva
int main() {
    srand(time(NULL)); // Inicializar el generador de números aleatorios
    
    Cola cola_llamadas;
    inicializarCola(&cola_llamadas);
    
    int tiempo_llegada_promedio = 10; // Tiempo promedio entre llegadas de llamadas en segundos
    int tiempo_atencion_promedio = 5; // Tiempo promedio de atención por llamada en segundos
    int max_empleados = 3; // Número máximo de empleados disponibles
    
    int tiempo_simulacion = 60; // Duración de la simulación en segundos
    int tiempo_transcurrido = 0;
    
    while (tiempo_transcurrido < tiempo_simulacion) {
        // Generar una nueva llamada con una probabilidad aleatoria
        if (rand() % 100 < 100) { // Probabilidad del 50%
            Llamada nueva_llamada;
            nueva_llamada.tiempo_llegada = tiempo_transcurrido;
            encolar(&cola_llamadas, nueva_llamada);
            printf("Nueva llamada en espera. Total de llamadas en cola: %d\n", cola_llamadas.final ? cola_llamadas.final - cola_llamadas.frente + 1 : 0);
        }
        
        // Verificar si hay empleados disponibles para atender llamadas
        int empleados_disponibles = max_empleados;
        while (!colaVacia(&cola_llamadas) && empleados_disponibles > 0) {
            Llamada llamada = desencolar(&cola_llamadas);
            printf("Atendiendo llamada...\n");
            int tiempo_atencion = generarNumeroAleatorio(tiempo_atencion_promedio - 2, tiempo_atencion_promedio + 2);
           
            printf("Llamada atendida en %d segundos\n", tiempo_atencion);
            empleados_disponibles--;
        }
        
        tiempo_transcurrido += 1; // Incrementar el tiempo en 1 segundo
        sleep(1); // Simular el paso del tiempo
    }
    
    return 0;
}

