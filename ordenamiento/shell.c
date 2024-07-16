#include <stdio.h>

void shellSort(int arr[], int n) {
    int gap, i, j, temp;
    
    // Selecciona el tamaño del salto (gap) inicialmente
    for (gap = n/2; gap > 0; gap /= 2) {
        // Aplica inserción directa para cada subarreglo
        for (i = gap; i < n; i++) {
            temp = arr[i];
            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            
            arr[j] = temp;
        }
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = 5;
    int i;
    printf("Arreglo original:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    shellSort(arr, n);

    printf("Arreglo ordenado en orden ascendente:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

