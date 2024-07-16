#include <stdio.h>

int main() {
    int dia, mes, anio, dias_mes;

    printf("Ingrese la fecha en formato dia, mes, año: ");
    scanf("%d %d %d", &dia, &mes, &anio);

    
    if (mes < 1 || mes > 12) {
        printf("FECHA INCORRECTA\n");
        return 0;
    }


    switch (mes) {
        case 2:
            dias_mes = (anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0)) ? 29 : 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            dias_mes = 30;
            break;
        default:
            dias_mes = 31;
            break;
    }

    if (dia < 1 || dia > dias_mes) {
        printf("FECHA INCORRECTA\n");
        return 0;
    }

 
    printf("FECHA CORRECTA\n");
    return 0;
}
