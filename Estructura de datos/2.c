#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct para representar una Persona
struct Persona {
    char nombre[50];
    char apellido[50];
    int edad;
    struct Persona* siguiente;
};

// Función para crear una nueva Persona
struct Persona* crearPersona(char nombre[], char apellido[], int edad) {
    struct Persona* nuevaPersona = (struct Persona*)malloc(sizeof(struct Persona));
    strcpy(nuevaPersona->nombre, nombre);
    strcpy(nuevaPersona->apellido, apellido);
    nuevaPersona->edad = edad;
    nuevaPersona->siguiente = NULL;
    return nuevaPersona;
}

// struct para representar una Cola de Personas
struct Cola {
    struct Persona* frente;
    struct Persona* final;
};

// Funcion para inicializar una Cola vacia
struct Cola* inicializarCola() {
    struct Cola* nuevaCola = (struct Cola*)malloc(sizeof(struct Cola));
    nuevaCola->frente = NULL;
    nuevaCola->final = NULL;
    return nuevaCola;
}

// Funcion para agregar una Persona a la Cola
void agregarPersona(struct Cola* cola, struct Persona* persona) {
    if (cola->final == NULL) {
        cola->frente = persona;
        cola->final = persona;
    } else {
        cola->final->siguiente = persona;
        cola->final = persona;
    }
}

// Funcion para eliminar y liberar la memoria de la Persona en el frente de la Cola
void eliminarPersona(struct Cola* cola) {
    if (cola->frente == NULL) {
        printf("La cola de personas está vacía.\n");
        return;
    }
    struct Persona* personaEliminada = cola->frente;
    cola->frente = cola->frente->siguiente;
    free(personaEliminada);
    printf("Persona eliminada de la cola.\n");
}

// Funcion para mostrar una Persona
void mostrarPersona(struct Persona* persona) {
    printf("Nombre: %s\n", persona->nombre);
    printf("Apellido: %s\n", persona->apellido);
    printf("Edad: %d\n", persona->edad);
}

// Funcion para mostrar todas las Personas en la Cola
void mostrarCola(struct Cola* cola) {
    struct Persona* actual = cola->frente;
    if (actual == NULL) {
        printf("La cola de personas está vacia.\n");
        return;
    }
    printf("Personas en la cola:\n");
    while (actual != NULL) {
        mostrarPersona(actual);
        actual = actual->siguiente;
    }
}

// Funcion para mostrar Personas por rango de edades
void mostrarPorRango(struct Cola* cola, int rangoMin, int rangoMax) {
    struct Persona* actual = cola->frente;
    if (actual == NULL) {
        printf("La cola de personas está vacia.\n");
        return;
    }
    printf("Personas en el rango de edades ");
    switch (rangoMin) {
        case 0:
            printf("Infantes");
            break;
        case 7:
            printf("Ninios");
            break;
        case 13:
            printf("Jovenes");
            break;
        case 24:
            printf("Adultos");
            break;
        case 51:
            printf("Ancianos");
            break;
        default:
            printf("Desconocido");
            break;
    }
    printf(":\n");
    
    while (actual != NULL) {
        if ((rangoMin == 0 && actual->edad >= rangoMin && actual->edad <= rangoMax) ||
            (rangoMin == 7 && actual->edad >= rangoMin && actual->edad <= rangoMax) ||
            (rangoMin == 13 && actual->edad >= rangoMin && actual->edad <= rangoMax) ||
            (rangoMin == 24 && actual->edad >= rangoMin && actual->edad <= rangoMax) ||
            (rangoMin == 51 && actual->edad >= rangoMin)) {
            mostrarPersona(actual);
        }
        actual = actual->siguiente;
    }
}

int main() {
    struct Cola* cola = inicializarCola();
    int opcion;
    
    do {
        printf("\nMenu:\n");
        printf("1- Ingresar Persona\n");
        printf("2- Mostrar Persona\n");
        printf("3- Eliminar Persona\n");
        printf("4- Personas por rango de edades\n");
        printf("5- Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1: {
                char nombre[50];
                char apellido[50];
                int edad;
                
                printf("Ingrese el nombre: ");
                scanf("%s", nombre);
                printf("Ingrese el apellido: ");
                scanf("%s", apellido);
                printf("Ingrese la edad: ");
                scanf("%d", &edad);
                
                struct Persona* nuevaPersona = crearPersona(nombre, apellido, edad);
                agregarPersona(cola, nuevaPersona);
                printf("Persona agregada a la cola.\n");
                break;
            }
            case 2: {
                mostrarCola(cola);
                break;
            }
            case 3: {
                eliminarPersona(cola);
                break;
            }
            case 4: {
                int opcionRango;
                printf("Seleccione el rango de edades:\n");
                printf("1- Infantes (0-6 anios)\n");
                printf("2- Ninos (7-12 anios)\n");
                printf("3- Jovenes (13-23 anios)\n");
                printf("4- Adultos (24-50 anios)\n");
                printf("5- Ancianos (51+ anios)\n");
                printf("Ingrese una opcion: ");
                scanf("%d", &opcionRango);
                
                switch (opcionRango) {
                    case 1:
                        mostrarPorRango(cola, 0, 6);
                        break;
                    case 2:
                        mostrarPorRango(cola, 7, 12);
                        break;
                    case 3:
                        mostrarPorRango(cola, 13, 23);
                        break;
                    case 4:
                        mostrarPorRango(cola, 24, 50);
                        break;
                    case 5:
                        mostrarPorRango(cola, 51, 1000);  // use 1000 como un valor alto para representar "mayor que 50".
                        break;
                    default:
                        printf("Opcion no valida. Por favor, seleccione una opción valida.\n");
                        break;
                }
                break;
            }
            case 5: {
                printf("Saliendo del programa.\n");
                break;
            }
            default: {
                printf("Opcion no valida. Por favor, seleccione una opcion valida.\n");
                break;
            }
        }
    } while (opcion != 5);

    // Liberar la memoria de las Personas restantes en la Cola
    while (cola->frente != NULL) {
        eliminarPersona(cola);
    }

    // Liberar la memoria de la Cola
    free(cola);

    return 0;
}

