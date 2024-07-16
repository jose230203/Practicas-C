#include <stdio.h>
#include <math.h>

int main() {
    int opcion;
    double num, resultado;

    printf("MENU PRINCIPAL DE CALCULOS\n");
    printf("1. Seno\n");
    printf("2. Coseno\n");
    printf("3. Tangente\n");
    printf("4. Logaritmo Natural\n");
    printf("5. e elevado a una potencia\n");
    printf("6. Base elevada a un exponente\n");
    printf("7. Valor Absoluto\n");
    printf("8. Logaritmo neperiano de un número\n");
    printf("9. Raiz Cuadrada\n");
    printf("0. Salir\n");

    while (1) {
        printf("\nIngrese una opcion: ");
        scanf("%d", &opcion);

        if (opcion == 0) {
            printf("Saliendo del programa...\n");
            break;
        }

        printf("Ingrese un numero: ");
        scanf("%lf", &num);

        switch (opcion) {
            case 1:
                resultado = sin(num);
                printf("El seno de %.2lf es %.2lf\n", num, resultado);
                break;
            case 2:
                resultado = cos(num);
                printf("El coseno de %.2lf es %.2lf\n", num, resultado);
                break;
            case 3:
                resultado = tan(num);
                printf("La tangente de %.2lf es %.2lf\n", num, resultado);
                break;
            case 4:
                resultado = log(num);
                printf("El logaritmo natural de %.2lf es %.2lf\n", num, resultado);
                break;
            case 5:
                resultado = exp(num);
                printf("e elevado a la potencia %.2lf es %.2lf\n", num, resultado);
                break;
            case 6:
                resultado = pow(num, 2);
                printf("%.2lf elevado al cuadrado es %.2lf\n", num, resultado);
                break;
            case 7:
                resultado = fabs(num);
                printf("El valor absoluto de %.2lf es %.2lf\n", num, resultado);
                break;
            case 8:
                resultado = log(num);
                printf("El logaritmo neperiano de %.2lf es %.2lf\n", num, resultado);
                break;
            case 9:
                resultado = sqrt(num);
                printf("La raiz cuadrada de %.2lf es %.2lf\n", num, resultado);
                break;
            default:
                printf("Opcion no valida. Intente nuevamente.\n");
                break;
        }
    }

    return 0;
}

