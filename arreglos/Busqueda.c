#include <stdio.h>
/*
Las ventajas de la b�squeda secuencial son las siguientes:

Simplicidad: La b�squeda secuencial es un algoritmo muy simple de implementar y entender. No requiere estructuras de datos adicionales ni un ordenamiento previo de los elementos.

Flexibilidad: La b�squeda secuencial se puede aplicar en cualquier tipo de lista o arreglo, independientemente de si los elementos est�n ordenados o no.

Sin embargo, la b�squeda secuencial tambi�n tiene algunas desventajas:

Eficiencia: En el peor de los casos, cuando el elemento buscado est� en la �ltima posici�n o no se encuentra en la lista, la b�squeda secuencial tiene una complejidad de tiempo O(n), donde n es el tama�o de la lista. Esto significa que la b�squeda secuencial puede volverse ineficiente en listas grandes.

No aprovecha el ordenamiento: Si la lista est� ordenada, la b�squeda secuencial no aprovecha esta informaci�n y sigue recorriendo todos los elementos de manera secuencial.

En resumen, la b�squeda secuencial es una opci�n sencilla y flexible para buscar elementos en una lista, pero puede volverse ineficiente en casos donde el tama�o de la lista sea grande o cuando se dispone de una lista ordenada. En esos casos, algoritmos m�s eficientes, como la b�squeda binaria, pueden ser preferibles.*/
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
            return i;  // Se encontr� la clave en la posici�n i
        }
    }
    return -1;  
