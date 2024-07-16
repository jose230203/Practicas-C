#include <stdio.h>

int main() {
    char a;

    printf("Ingrese la inicial del día de la semana (use 'x' para miércoles): ");
    scanf(" %c", &a);

    switch(a) {
        case 'l':  case 'L':
            printf("Lunes\n");
            break;
        case 'm':   case 'M':
            printf("Martes\n");
            break;
        case 'x':     case 'X':
            printf("Miércoles\n");
            break;
        case 'j':  case 'J':
            printf("Jueves\n");
            break;
        case 'v':  case 'V':

            printf("Viernes\n");
            break;
        case 's': case 'S':
            printf("Sábado\n");
            break;
        case 'd': case 'D':
            printf("Domingo\n");
            break;
        default:
            printf("Inicial inválida\n");
    }

    return 0;
}

