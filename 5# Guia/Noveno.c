#include <stdio.h>

int main() {
    int opcion;
    float numero1, numero2, resultado;

    do {
    	while(1){
		
        printf("Menu:\n");
        printf("1. Sumar dos numeros.\n");
        printf("2. Restar dos numeros.\n");
        printf("3. Multiplicar dos numeros.\n");
        printf("4. Dividir dos numeros.\n");
        printf("5. Salir.\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);
        if(opcion>=1 && opcion<=5)
        {
        	break;
		}
		else
		{
			printf("Opcion invalida\n");
		}
        }
       
        switch (opcion) {
            case 1:
                printf("Ingrese dos numeros a sumar:\n");
                printf("Numero 1: ");
                scanf("%f", &numero1);
                printf("Numero 2: ");
                scanf("%f", &numero2);
                resultado = numero1 + numero2;
                printf("El resultado de la suma es: %.2f\n", resultado);
                break;

            case 2: 
                printf("Ingrese dos numeros a restar:\n");
                printf("Numero 1: ");
                scanf("%f", &numero1);
                printf("Numero 2: ");
                scanf("%f", &numero2);
                resultado = numero1 - numero2;
                printf("El resultado de la resta es: %.2f\n", resultado);
                break;

            case 3:
                printf("Ingrese dos numeros a multiplicar:\n");
                printf("Numero 1: ");
                scanf("%f", &numero1);
                printf("Numero 2: ");
                scanf("%f", &numero2);
                resultado = numero1 * numero2;
                printf("El resultado de la multiplicación es: %.2f\n", resultado);
                break;

            case 4:
                printf("Ingrese dos numeros a dividir:\n");
                printf("Numero 1: ");
                scanf("%f", &numero1);
                printf("Numero 2: ");
                scanf("%f", &numero2);
                if (numero2 != 0) {
                    resultado = numero1 / numero2;
                    printf("El resultado de la división es: %.2f\n", resultado);
                } else {
                    printf("ERROR: No se puede dividir entre cero.\n");
                }
                break;

            case 5:
                printf("Saliendo del programa...\n");
                break;
        }
    } while (opcion != 5);

    return 0;
}

