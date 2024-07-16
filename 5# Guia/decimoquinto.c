#include <stdio.h>

int main() {
    int n,i,huevos;
    float peso, altura, calidad;
    float precio_kilo_huevo;
    float promedio_calidad = 0.0;
    int total_gallinas = 0;

    printf("Ingrese el numero de gallinas en la granja: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("Ingrese el peso de la gallina %d: ", i);
        scanf("%f", &peso);

        printf("Ingrese la altura de la gallina %d: ", i);
        scanf("%f", &altura);

        printf("Ingrese el numero de huevos que pone la gallina %d: ", i);
        scanf("%d", &huevos);

        calidad = (peso * altura) / huevos;
        promedio_calidad += calidad;
        total_gallinas++;
    }

    if (total_gallinas > 0) {
        promedio_calidad /= total_gallinas;



        if (promedio_calidad >= 15) {
            precio_kilo_huevo = 1.2 * promedio_calidad;
        } else if (promedio_calidad > 8 && promedio_calidad < 15) {
            precio_kilo_huevo = 1.0 * promedio_calidad;
        } else {
            precio_kilo_huevo = 0.8 * promedio_calidad;
        }

        printf("\nEl promedio de calidad de las gallinas es: %.2f\n", promedio_calidad);
        printf("El precio por kilo de huevo es: %.2f\n", precio_kilo_huevo);
    } else {
        printf("No se ingresaron gallinas en la granja.\n");
    }

    return 0;
}

