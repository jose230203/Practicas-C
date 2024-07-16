#include <stdio.h>

int main() {
    int x;
    printf("Introduce un entero: ");
    scanf("%d", &x);
    
    switch (x) {
        case -1000 ... -1:
            printf("X menor 0\n");
            break;
        case 0 ... 100:
            printf("se encuentra entre 0 y 100\n");
            break;
        case 101 ... 1000:
            printf("X es mayor que 100\n");
            break;
        default:
            printf("El numero introducido no está dentro de ninguna categoría definida.\n");
            break;
    }
    
    return 0;
}

