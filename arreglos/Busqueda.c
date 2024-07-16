#include <stdio.h>
/*
Las ventajas de la búsqueda secuencial son las siguientes:

Simplicidad: La búsqueda secuencial es un algoritmo muy simple de implementar y entender. No requiere estructuras de datos adicionales ni un ordenamiento previo de los elementos.

Flexibilidad: La búsqueda secuencial se puede aplicar en cualquier tipo de lista o arreglo, independientemente de si los elementos están ordenados o no.

Sin embargo, la búsqueda secuencial también tiene algunas desventajas:

Eficiencia: En el peor de los casos, cuando el elemento buscado está en la última posición o no se encuentra en la lista, la búsqueda secuencial tiene una complejidad de tiempo O(n), donde n es el tamaño de la lista. Esto significa que la búsqueda secuencial puede volverse ineficiente en listas grandes.

No aprovecha el ordenamiento: Si la lista está ordenada, la búsqueda secuencial no aprovecha esta información y sigue recorriendo todos los elementos de manera secuencial.

En resumen, la búsqueda secuencial es una opción sencilla y flexible para buscar elementos en una lista, pero puede volverse ineficiente en casos donde el tamaño de la lista sea grande o cuando se dispone de una lista ordenada. En esos casos, algoritmos más eficientes, como la búsqueda binaria, pueden ser preferibles.*/
int busquedaSecuencial(int [],int,int );

int main() {
    int arreglo[] = {1, 2, 3, 4, 5};
    int clave = 3;
    int resultado = busquedaSecuencial(arreglo, 4, clave);
    if (resultado == -1) {
        printf("La clave no se encontro en el arreglo.\n");
    } else {
        printf("La clave se encontro en la posicion %d.\n", resultado);
    }
    return 0;
}

int busquedaSecuencial(int arr[], int n, int clave) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == clave) {
            return i;  // Se encontró la clave en la posición i
        }
    }
    return -1;  
