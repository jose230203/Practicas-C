#include <stdio.h>

int main() {
    char a;

    printf("Ingrese la inicial del d�a de la semana (use 'x' para mi�rcoles): ");
    scanf(" %c", &a);

    switch(a) {
        case 'l':  case 'L':
            printf("Lunes\n");
            break;
        case 'm':   case 'M':
            printf("Martes\n");
            break;
        case 'x':     case 'X':
            printf("Mi�rcoles\n");
            break;
        case 'j':  case 'J':
            printf("Jueves\n");
            break;
        case 'v':  case 'V':

            printf("Viernes\n");
            break;
        case 's': case 'S':
            printf("S�bado\n");
            break;
        case 'd': case 'D':
            printf("Domingo\n");
            break;
        default:
            printf("Inicial inv�lida\n");
    }

    return 0;
}

