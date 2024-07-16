#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del libro
struct Libro {
    int codigo;
    char titulo[100];
    float precio;
    struct Libro* siguiente;
};

// Función para agregar un nuevo libro al final de la lista
void agregarLibro(struct Libro** lista, int codigo, char titulo[], float precio) {
    struct Libro* nuevoLibro = (struct Libro*)malloc(sizeof(struct Libro));
    nuevoLibro->codigo = codigo;
    strcpy(nuevoLibro->titulo, titulo);
    nuevoLibro->precio = precio;
    nuevoLibro->siguiente = NULL;

    if (*lista == NULL) {
        *lista = nuevoLibro;
    } else {
        struct Libro* temp = *lista;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoLibro;
    }
}

// Función para buscar un libro por el código
struct Libro* buscarLibroPorCodigo(struct Libro* lista, int codigo) {
    struct Libro* temp = lista;
    while (temp != NULL) {
        if (temp->codigo == codigo) {
            return temp;
        }
        temp = temp->siguiente;
    }
    return NULL;
}

// Función para mostrar la suma de todos los precios
float sumaDePrecios(struct Libro* lista) {
    float suma = 0;
    struct Libro* temp = lista;
    while (temp != NULL) {
        suma += temp->precio;
        temp = temp->siguiente;
    }
    return suma;
}

// Función para mostrar los libros con precio menor al ingresado
void mostrarLibrosMenoresAPrecio(struct Libro* lista, float precioLimite) {
    struct Libro* temp = lista;
    printf("Libros con precio menor a %.2f:\n", precioLimite);
    while (temp != NULL) {
        if (temp->precio < precioLimite) {
            printf("Codigo: %d, Titulo: %s, Precio: %.2f\n", temp->codigo, temp->titulo, temp->precio);
        }
        temp = temp->siguiente;
    }
}

// Función para eliminar libros en un rango de códigos
void eliminarLibrosEnRango(struct Libro** lista, int codigoInicio, int codigoFinal) {
    struct Libro* temp = *lista;
    struct Libro* prev = NULL;

    while (temp != NULL) {
        if (temp->codigo >= codigoInicio && temp->codigo <= codigoFinal) {
            if (prev == NULL) {
                *lista = temp->siguiente;
            } else {
                prev->siguiente = temp->siguiente;
            }
            free(temp);
        } else {
            prev = temp;
        }
        temp = temp->siguiente;
    }
}

// Función para liberar toda la lista
void eliminarLista(struct Libro** lista) {
    struct Libro* temp;
    while (*lista != NULL) {
        temp = (*lista)->siguiente;
        free(*lista);
        *lista = temp;
    }
}

int main() {
    struct Libro* lista = NULL;
    int opcion;
    int codigo, codigoInicio, codigoFinal;
    char titulo[100];
    float precio;

    do {
        printf("\nMENU PRINCIPAL\n");
        printf("1. Agregar un nuevo libro al final de la Lista\n");
        printf("2. Buscar un libro por el codigo\n");
        printf("3. Mostrar la suma de todos los precios\n");
        printf("4. Mostrar el listado de libros que sean menores a un precio ingresado\n");
        printf("5. Eliminar los libros en un rango de codigos\n");
        printf("6. Salir de la aplicación eliminando la lista por completo\n");
        printf("Ingrese la opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el codigo del libro: ");
                scanf("%d", &codigo);
                printf("Ingrese el titulo del libro: ");
                scanf(" %99[^\n]", titulo);
                printf("Ingrese el precio del libro: ");
                scanf("%f", &precio);
                agregarLibro(&lista, codigo, titulo, precio);
                break;
            case 2:
                printf("Ingrese el codigo a buscar: ");
                scanf("%d", &codigo);
                struct Libro* libroEncontrado = buscarLibroPorCodigo(lista, codigo);
                if (libroEncontrado != NULL) {
                    printf("Libro encontrado:\n");
                    printf("Codigo: %d, Titulo: %s, Precio: %.2f\n", libroEncontrado->codigo, libroEncontrado->titulo, libroEncontrado->precio);
                } else {
                    printf("Libro no encontrado.\n");
                }
                break;
            case 3:
                printf("La suma de todos los precios es: %.2f\n", sumaDePrecios(lista));
                break;
            case 4:
                printf("Ingrese el precio limite: ");
                scanf("%f", &precio);
                mostrarLibrosMenoresAPrecio(lista, precio);
                break;
            case 5:
                printf("Ingrese el codigo de inicio del rango: ");
                scanf("%d", &codigoInicio);
                printf("Ingrese el codigo final del rango: ");
                scanf("%d", &codigoFinal);
                eliminarLibrosEnRango(&lista, codigoInicio, codigoFinal);
                break;
            case 6:
                eliminarLista(&lista);
                printf("La lista ha sido eliminada.\n");
                break;
            default:
                printf("Opcion no valida. Por favor, seleccione una opcion valida.\n");
        }
    } while (opcion != 6);

    return 0;
}

