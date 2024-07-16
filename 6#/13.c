#include <stdio.h>

char complementoCaracter(char c) {
    if (islower(c)) {
        char caracterMayuscula = toupper(c);
        printf("El caracter en mayuscula es: %c\n", caracterMayuscula);
    } else if (isupper(c)) {
        char caracterMinuscula = tolower(c);
        printf("El caracter en minuscula es: %c\n", caracterMinuscula);
    } else {
        printf("El caracter ingresado no es una letra.\n");
    }
}

int main() {
    char caracter;

    printf("Ingrese un caracter alfabetico ('.' para terminar): ");

    while ((caracter = getchar()) != '.') {
        if ((caracter >= 'a' && caracter <= 'z') || (caracter >= 'A' && caracter <= 'Z')) {
            caracter = complementoCaracter(caracter);
        }

        putchar(caracter);
    }

    printf("\n");

    return 0;
}

