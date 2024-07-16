#include <stdio.h>

int main() {
	int mes;
    float vivienda, alimentacion, energia, vestuario, transporte;
    float total_trimestre1 = 0, total_trimestre2 = 0, total_trimestre3 = 0, total_trimestre4 = 0;
    float total_anual, porcentaje_vivienda, porcentaje_alimentacion, porcentaje_energia, porcentaje_vestuario, porcentaje_transporte;

    for (mes = 1; mes <= 12; mes++) {
        printf("Ingrese el gasto en vivienda del mes %d: ", mes);
        scanf("%f", &vivienda);
        
        printf("Ingrese el gasto en alimentacion del mes %d: ", mes);
        scanf("%f", &alimentacion);
        printf("Ingrese el gasto en energia del mes %d: ", mes);
        scanf("%f", &energia);
        printf("Ingrese el gasto en vestuario del mes %d: ", mes);
        scanf("%f", &vestuario);
        printf("Ingrese el gasto en transporte del mes %d: ", mes);
        scanf("%f", &transporte);

        if (mes <= 3) {
            total_trimestre1 += vivienda + alimentacion + energia + vestuario + transporte;
        } else if (mes <= 6) {
            total_trimestre2 += vivienda + alimentacion + energia + vestuario + transporte;
        } else if (mes <= 9) {
            total_trimestre3 += vivienda + alimentacion + energia + vestuario + transporte;
        } else {
            total_trimestre4 += vivienda + alimentacion + energia + vestuario + transporte;
        }
    }

    total_anual = total_trimestre1 + total_trimestre2 + total_trimestre3 + total_trimestre4;

    porcentaje_vivienda = (vivienda / total_anual) * 100;
    porcentaje_alimentacion = (alimentacion / total_anual) * 100;
    porcentaje_energia = (energia / total_anual) * 100;
    porcentaje_vestuario = (vestuario / total_anual) * 100;
    porcentaje_transporte = (transporte / total_anual) * 100;

    printf("Gasto total del trimestre 1: %.2f\n", total_trimestre1);
    printf("Gasto total del trimestre 2: %.2f\n", total_trimestre2);
    printf("Gasto total del trimestre 3: %.2f\n", total_trimestre3);
    printf("Gasto total del trimestre 4: %.2f\n", total_trimestre4);
    printf("Gasto total anual: %.2f\n", total_anual);
    printf("Porcentaje de gasto en vivienda: %.2f%%\n", porcentaje_vivienda);
    printf("Porcentaje de gasto en alimentacion: %.2f%%\n", porcentaje_alimentacion);
    printf("Porcentaje de gasto en energia: %.2f%%\n", porcentaje_energia);
    printf("Porcentaje de gasto en vestuario: %.2f%%\n", porcentaje_vestuario);
    printf("Porcentaje de gasto en transporte: %.2f%%\n", porcentaje_transporte);

    return 0;
}
