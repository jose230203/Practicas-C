#include <stdio.h>

int main() {
    float nota;
    int nota_entera;
    printf("Ingrese la nota del examen: ");
    scanf("%f", &nota);
    
    // Redondeamos la nota a un entero para utilizar el switch
    nota_entera = (int) nota;
    
    switch (nota_entera) {
        case 0 ... 49:  // Equivalente a nota_entera < 50
            printf("Suspenso\n");
            break;
        case 50 ... 69:
            printf("Aprobado\n");
            break;
        case 70 ... 89:
            printf("Notable\n");
            break;
        case 90 ... 99:
            printf("Sobresaliente\n");
            break;
        case 100:
            printf("Matrícula de honor\n");
            break;
        default:
            printf("Nota inválida\n");
            break;
    }
    
    return 0;
}
