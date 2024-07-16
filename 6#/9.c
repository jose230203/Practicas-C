#include <stdio.h>
#include <stdbool.h>

bool esDigito(char c) {
    return (c >= '0' && c <= '9');
}

int main() {
    char caracter;

    printf("Ingrese un caracter: ");
    scanf("%c", &caracter);

    if (esDigito(caracter)) {
        printf("El caracter ingresado es un digito.\n");
    } else {
        printf("El caracter ingresado no es un digito.\n");
    }
    getch();
    return 0;
}

