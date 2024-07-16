#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int i;
// Estructura para representar una nevera
struct Nevera {
    int codigo;
    char descripcion[100];
    struct Nevera* siguiente;
};

// Estructura para representar una solicitud de tienda
struct Solicitud {
    char tienda[100];
    int cantidad;
    struct Solicitud* siguiente;
};

// Función para agregar una nevera al almacen
void AgregarNevera(struct Nevera** almacen, int codigo, const char* descripcion) {
    struct Nevera* nuevaNevera = (struct Nevera*)malloc(sizeof(struct Nevera));
    nuevaNevera->codigo = codigo;
    strncpy(nuevaNevera->descripcion, descripcion, sizeof(nuevaNevera->descripcion));
    nuevaNevera->siguiente = NULL;

    if (*almacen == NULL) {
        *almacen = nuevaNevera;
    } else {
        struct Nevera* actual = *almacen;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevaNevera;
    }
}

// Función para agregar una solicitud de tienda
void AgregarSolicitud(struct Solicitud** solicitudes, const char* tienda, int cantidad) {
    struct Solicitud* nuevaSolicitud = (struct Solicitud*)malloc(sizeof(struct Solicitud));
    strncpy(nuevaSolicitud->tienda, tienda, sizeof(nuevaSolicitud->tienda));
    nuevaSolicitud->cantidad = cantidad;
    nuevaSolicitud->siguiente = NULL;

    if (*solicitudes == NULL) {
        *solicitudes = nuevaSolicitud;
    } else {
        struct Solicitud* actual = *solicitudes;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevaSolicitud;
    }
}

// Función para asignar neveras a las tiendas (de más nuevas a más viejas)
void AsignarNeveras(struct Nevera** almacen, struct Solicitud** solicitudes) {
    struct Solicitud* actualSolicitud = *solicitudes;

    while (actualSolicitud != NULL) {
        int cantidadSolicitada = actualSolicitud->cantidad;
        const char* tienda = actualSolicitud->tienda;

        for (i = 0; i < cantidadSolicitada; i++) {
            if (*almacen == NULL) {
                printf("No hay suficientes neveras en el almacen para la tienda %s.\n", tienda);
                break; // Sal del bucle si no hay suficientes neveras
            } else {
                struct Nevera* neveraActual = *almacen;
                struct Nevera* neveraAnterior = NULL;

                while (neveraActual->siguiente != NULL) {
                    neveraAnterior = neveraActual;
                    neveraActual = neveraActual->siguiente;
                }

                if (neveraAnterior != NULL) {
                    neveraAnterior->siguiente = NULL;
                } else {
                    *almacen = NULL;
                }

                printf("Se asigno la nevera %d al almacen de la tienda %s.\n", neveraActual->codigo, tienda);
                free(neveraActual);
            }
        }

        actualSolicitud = actualSolicitud->siguiente;
    }
}


// Función para mostrar las neveras en el almacen
void MostrarAlmacen(struct Nevera* almacen) {
    printf("Neveras en el almacen:\n");
    struct Nevera* actual = almacen;
    while (actual != NULL) {
        printf("Codigo: %d, Descripcion: %s\n", actual->codigo, actual->descripcion);
        actual = actual->siguiente;
    }
}

int main() {
    struct Nevera* almacen = NULL;
    struct Solicitud* solicitudes = NULL;

    int opcion;
    int codigo;
    char descripcion[100];
    char tienda[100];
    int cantidad;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Agregar nevera al almacen\n");
        printf("2. Agregar solicitud de tienda\n");
        printf("3. Asignar neveras a tiendas\n");
        printf("4. Mostrar neveras en el almacen\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el codigo de la nevera: ");
                scanf("%d", &codigo);
                printf("Ingrese la descripcion de la nevera: ");
                getchar(); // Consumir el salto de línea anterior
                fgets(descripcion, sizeof(descripcion), stdin);
                descripcion[strlen(descripcion) - 1] = '\0'; // Eliminar el carácter de nueva línea
                AgregarNevera(&almacen, codigo, descripcion);
                break;
            case 2:
                printf("Ingrese el nombre de la tienda: ");
                getchar(); // Consumir el salto de línea anterior
                fgets(tienda, sizeof(tienda), stdin);
                tienda[strlen(tienda) - 1] = '\0'; // Eliminar el carácter de nueva línea
                printf("Ingrese la cantidad de neveras solicitadas: ");
                scanf("%d", &cantidad);
                AgregarSolicitud(&solicitudes, tienda, cantidad);
                break;
            case 3:
                AsignarNeveras(&almacen, &solicitudes);
                break;
            case 4:
                MostrarAlmacen(almacen);
                break;
            case 5:
                // Liberar memoria y salir
                while (almacen != NULL) {
                    struct Nevera* temp = almacen;
                    almacen = almacen->siguiente;
                    free(temp);
                }
                while (solicitudes != NULL) {
                    struct Solicitud* temp = solicitudes;
                    solicitudes = solicitudes->siguiente;
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

