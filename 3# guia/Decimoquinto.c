#include <stdio.h>

int main() {
    int a, c;
    char b;
    
    printf("Introduce tu edad: ");
    scanf("%d", &a);
    
    printf("Introduce tu sexo (f/m): ");
    scanf(" %c", &b);
    
    if (b == 'f') {
        c = (220 - a) / 10;
    } else if (b == 'm') {
        c = (210 - a) / 10;
    } else {
        printf("Sexo no v�lido.\n");
        return 1;
    }
    
    printf("El n�mero de pulsaciones por cada 10 segundos de ejercicio aer�bico es: %d\n", c);
    
    return 0;
}

