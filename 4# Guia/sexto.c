#include <stdio.h>

int main() {
    int valorInicial, valorFinal,i;

    printf("Ingrese el valor inicial: ");
    scanf("%d", &valorInicial);

    printf("Ingrese el valor final: ");
    scanf("%d", &valorFinal);
    
    printf("Numeros en forma ascendente:\n");
    for (i = valorInicial; i <= valorFinal; i++) {
        printf("%d ", i);
    }
        printf("\n");
        printf("Numeros en forma descendente:\n");
    for (i = valorFinal; i >= valorInicial; i--) {
        printf("%d ", i);
    }
    return 0;
}

