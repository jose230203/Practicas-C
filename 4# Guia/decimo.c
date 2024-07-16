#include <stdio.h>

int main() {
    int N,i;
    int pesoTotal = 0;
    int alturaTotal = 0;
    int contadorPersonas = 0;
    int peso, altura;
    char sexo;
    float promedioAltura;
     float promedioPeso;

    printf("Ingrese la cantidad de personas: ");
    scanf("%d", &N);

    for (i = 1; i <= N; i++) {
        printf("\nDatos de la persona %d:\n", i);

        printf("Ingrese el peso (en kg): ");
        scanf("%d", &peso);

        printf("Ingrese la altura (en cm): ");
        scanf("%d", &altura);

        printf("Ingrese el sexo (M/F): ");
        scanf(" %c", &sexo);

        // Solo se toman en cuenta los datos si el sexo es 'M' o 'F'
        if (sexo == 'M' || sexo == 'F') {
            pesoTotal += peso;
            alturaTotal += altura;
            contadorPersonas++;
        }
    }

    promedioPeso = (float)pesoTotal / contadorPersonas;
    promedioAltura = (float)alturaTotal / contadorPersonas;

    printf("\nPromedio del peso: %.2f kg\n", promedioPeso);
    printf("Promedio de la altura: %.2f cm\n", promedioAltura);

    return 0;
}

