#include <stdio.h>

int main() {
    int a;
    
    printf("Ingrese el numero de serie: ");
    scanf("%d", &a);
    
    switch (a) {
        case 14681 ... 15681:
        case 70001 ... 79999:
        case 88888 ... 111111:
            printf("El numero de serie es DEFECTUOSO.\n");
            break;
        default:
            printf("El numero de serie NO es defectuoso.\n");
            break;
    }
    
    return 0;
}

