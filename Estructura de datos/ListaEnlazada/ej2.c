/*
Ejercicio 2
Un pequeño supermercado dispone en la salida de 
dos cajas de pago. En el local hay 20 carritos de compra.
Escribir un programa que simule el funcionamiento
siguiendo las siguientes reglas:
1-Si cuando llega un cliente no hay ningun carrito disponible
 espera a que lo haya. 
2-Ningun cliente se impacienta y abandona el supermercado 
sin pasar  por alguna de las filas de la caja. 
3-Cuando un cliente finaliza su compra, se coloca 
en la fila de la caja que hay menos gente y no se 
cambia de fila. 
4-En el momento en que un cliente paga en la caja,
el carro de la compra que tiene queda disponible
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
} Cliente;

typedef struct {
    int id;
    int disponible;
} Carrito;

typedef struct NodoCola {
    Cliente cliente;
    struct NodoCola* siguiente;
} NodoCola;

typedef struct {
    NodoCola* frente;
    NodoCola* final;
    int tamano;
} Cola;

void inicializarCola(Cola* cola) {
    cola->frente = NULL;
    cola->final = NULL;
    cola->tamano = 0;
}

int estaVacia(Cola* cola) {
    return cola->tamano == 0;
}

void encolar(Cola* cola, Cliente cliente) {
    NodoCola* nuevoNodo = (NodoCola*)malloc(sizeof(NodoCola));
    nuevoNodo->cliente = cliente;
    nuevoNodo->siguiente = NULL;

    if (estaVacia(cola)) {
        cola->frente = nuevoNodo;
        cola->final = nuevoNodo;
    } else {
        cola->final->siguiente = nuevoNodo;
        cola->final = nuevoNodo;
    }

    cola->tamano++;
}

Cliente desencolar(Cola* cola) {
    if (estaVacia(cola)) {
        printf("La cola esta vacia.\n");
        Cliente clienteVacio = { -1 };
        return clienteVacio;
    }

    NodoCola* nodoAEliminar = cola->frente;
    Cliente clienteDesencolado = nodoAEliminar->cliente;

    cola->frente = nodoAEliminar->siguiente;
    free(nodoAEliminar);

    cola->tamano--;

    if (cola->tamano == 0) {
        cola->frente = NULL;
        cola->final = NULL;
    }

    return clienteDesencolado;
}

int main() {
    int i, tiempo, numCarritos = 20;
    Carrito* carritos = (Carrito*)malloc(numCarritos * sizeof(Carrito));

    for (i = 0; i < numCarritos; i++) {
        carritos[i].id = i + 1;
        carritos[i].disponible = 1;
    }

    Cola colaCaja1, colaCaja2;
    inicializarCola(&colaCaja1);
    inicializarCola(&colaCaja2);

    Cliente clienteActual;
    int idCliente = 1;  // Identificador de cliente

    // Simulacion: Llegada de clientes y asignacion a colas
    for (tiempo = 1; tiempo <= 50; tiempo++) {
        // Generar un nuevo cliente en el supermercado
        Cliente nuevoCliente;
        nuevoCliente.id = idCliente;
        idCliente++;

        // Si hay carritos disponibles, el cliente entra al supermercado
        if (numCarritos > 0) {
            printf("Tiempo %d: Llega un nuevo cliente (ID: %d).\n", tiempo, nuevoCliente.id);
            numCarritos--;

            // Determinar a cual caja unirse (la que tiene menos gente)
            if (colaCaja1.tamano <= colaCaja2.tamano)
                encolar(&colaCaja1, nuevoCliente);
            else
                encolar(&colaCaja2, nuevoCliente);
        } else {
            printf("Tiempo %d: Llega un nuevo cliente (ID: %d), pero no hay carritos disponibles. Espera.\n", tiempo, nuevoCliente.id);
        }

        // Simulacion de clientes pagando y liberando carritos
        if (tiempo % 5 == 0) {
            if (!estaVacia(&colaCaja1)) {
                clienteActual = desencolar(&colaCaja1);
                printf("Tiempo %d: Cliente (ID: %d) paga en caja 1.\n", tiempo, clienteActual.id);
                numCarritos++;
            }

            if (!estaVacia(&colaCaja2)) {
                clienteActual = desencolar(&colaCaja2);
                printf("Tiempo %d: Cliente (ID: %d) paga en caja 2.\n", tiempo, clienteActual.id);
                numCarritos++;
            }
        }
    }

    free(carritos);

    return 0;
}

