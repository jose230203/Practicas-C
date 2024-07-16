#include <stdio.h>

int main() {
    int a;
    printf("Lista de colores del semaforo:\n");
    printf("1. Rojo\n2. Verde\n3. Amarillo\n");
    printf("Introduce el numero asociado a un color: ");
    scanf("%d", &a);

    switch (a) {
        case 1:
            printf("El color rojo significa \"No pasar\"\n");
            break;
        case 2:
            printf("El color verde significa \"Adelante\"\n");
            break;
        case 3:
            printf("El color amarillo significa \"Precaución\"\n");
            break;
        default:
            printf("ERROR: <%d> no está asociado a ningún color.\n", a);
            break;
    }

    return 0;
}
