#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para representar un trabajo de impresion
struct TrabajoImpresion {
    char nombreUsuario[100];
    char programa[100];
    struct TrabajoImpresion* siguiente;
};

// Funcion para agregar un trabajo a la cola de impresion
void EnviarImpresion(struct TrabajoImpresion** colaImpresion, const char* nombreUsuario, const char* programa) {
    struct TrabajoImpresion* nuevoTrabajo = (struct TrabajoImpresion*)malloc(sizeof(struct TrabajoImpresion));
    strncpy(nuevoTrabajo->nombreUsuario, nombreUsuario, sizeof(nuevoTrabajo->nombreUsuario));
    strncpy(nuevoTrabajo->programa, programa, sizeof(nuevoTrabajo->programa));
    nuevoTrabajo->siguiente = NULL;

    if (*colaImpresion == NULL) {
        *colaImpresion = nuevoTrabajo;
    } else {
        struct TrabajoImpresion* actual = *colaImpresion;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoTrabajo;
    }

    printf("Trabajo de impresion enviado por: %s desde el programa: %s\n", nombreUsuario, programa);
}

// Funcion para imprimir el primer trabajo de la cola de impresion
void ImprimirTrabajo(struct TrabajoImpresion** colaImpresion) {
    if (*colaImpresion == NULL) {
        printf("No hay trabajos de impresion en la cola.\n");
    } else {
        struct TrabajoImpresion* trabajoAImprimir = *colaImpresion;
        *colaImpresion = trabajoAImprimir->siguiente;
        printf("Imprimiendo trabajo de: %s desde el programa: %s\n", trabajoAImprimir->nombreUsuario, trabajoAImprimir->programa);
        free(trabajoAImprimir);
    }
}

// Funcion para eliminar un trabajo de la cola de impresion por numero
void EliminarImpresion(struct TrabajoImpresion** colaImpresion, int numeroTrabajo) {
    if (*colaImpresion == NULL) {
        printf("No hay trabajos de impresion en la cola.\n");
    } else {
        if (numeroTrabajo == 1) {
            struct TrabajoImpresion* trabajoAEliminar = *colaImpresion;
            *colaImpresion = trabajoAEliminar->siguiente;
            free(trabajoAEliminar);
            printf("Trabajo eliminado con exito.\n");
        } else {
            struct TrabajoImpresion* actual = *colaImpresion;
            int i = 1;
            while (i < numeroTrabajo - 1 && actual->siguiente != NULL) {
                actual = actual->siguiente;
                i++;
            }
            if (actual->siguiente == NULL) {
                printf("Numero de trabajo no valido.\n");
            } else {
                struct TrabajoImpresion* trabajoAEliminar = actual->siguiente;
                actual->siguiente = trabajoAEliminar->siguiente;
                free(trabajoAEliminar);
                printf("Trabajo eliminado con exito.\n");
            }
        }
    }
}

// Funcion para mostrar el menu
void MostrarMenu() {
    printf("\nMenu:\n");
    printf("1. Enviar Impresion\n");
    printf("2. Imprimir\n");
    printf("3. Eliminar Impresion\n");
    printf("4. Salir\n");
}

int main() {
    struct TrabajoImpresion* colaImpresion = NULL;
    int opcion;
    char nombreUsuario[100];
    char programa[100];
    int numeroTrabajo;

    while (1) {
        MostrarMenu();
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                getchar();
                printf("Ingrese el nombre de usuario: ");
                fgets(nombreUsuario, sizeof(nombreUsuario), stdin);
                printf("Ingrese el programa: ");
                scanf("%s", programa);
                EnviarImpresion(&colaImpresion, nombreUsuario, programa);
                break;
            case 2:
                ImprimirTrabajo(&colaImpresion);
                break;
            case 3:
                printf("Ingrese el numero del trabajo a eliminar: ");
                scanf("%d", &numeroTrabajo);
                EliminarImpresion(&colaImpresion, numeroTrabajo);
                break;
            case 4:
                // Liberar memoria y salir
                while (colaImpresion != NULL) {
                    struct TrabajoImpresion* temp = colaImpresion;
                    colaImpresion = colaImpresion->siguiente;
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

