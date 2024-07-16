#include <stdio.h>
#include <stdlib.h>

struct Contenedor {
    int codigo;
    struct Contenedor* siguiente;
};

struct Almacen {
    struct Contenedor* cima;
};

struct Contenedor* CrearContenedor(int codigo) {
    struct Contenedor* nuevo = (struct Contenedor*)malloc(sizeof(struct Contenedor));
    nuevo->codigo = codigo;
    nuevo->siguiente = NULL;
    return nuevo;
}

void Push(struct Almacen* almacen, int codigo) {
    struct Contenedor* nuevo = CrearContenedor(codigo);
    nuevo->siguiente = almacen->cima;
    almacen->cima = nuevo;
    printf("Contenedor con codigo %d empujado en la pila.\n", codigo);
}

int PopPorCodigo(struct Almacen* almacen, int codigo) {
    struct Contenedor* actual = almacen->cima;
    struct Contenedor* anterior = NULL;
    
    while (actual != NULL) {
        if (actual->codigo == codigo) {
            if (anterior == NULL) {
                almacen->cima = actual->siguiente;
            } else {
                anterior->siguiente = actual->siguiente;
            }
            
            int codigoRetirado = actual->codigo;
            free(actual);
            printf("Contenedor con codigo %d retirado de la pila.\n", codigo);
            return codigoRetirado;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    
    printf("Contenedor con codigo %d no encontrado en el almacen.\n", codigo);
    return -1;
}

void MostrarAlmacen(struct Almacen* almacen) {
    struct Contenedor* actual = almacen->cima;
    printf("Contenedores en el almacen:\n");
    while (actual != NULL) {
        printf("Codigo: %d\n", actual->codigo);
        actual = actual->siguiente;
    }
}

int main() {
    struct Almacen almacen;
    almacen.cima = NULL;

    int opcion;
    int codigo;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Agregar contenedor\n");
        printf("2. Quitar contenedor por codigo\n");
        printf("3. Mostrar almacen\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el codigo del contenedor a agregar: ");
                scanf("%d", &codigo);
                Push(&almacen, codigo);
                break;
            case 2:
                printf("Ingrese el codigo del contenedor a quitar: ");
                scanf("%d", &codigo);
                PopPorCodigo(&almacen, codigo);
                break;
            case 3:
                MostrarAlmacen(&almacen);
                break;
            case 4:
                while (almacen.cima != NULL) {
                    PopPorCodigo(&almacen, almacen.cima->codigo);
                }
                return 0;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
                break;
        }
    }

    return 0;
}

