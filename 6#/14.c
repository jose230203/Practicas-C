#include <stdio.h>

int esAnioBisiesto(int anio) {
    if ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int esFechaValida(int dia, int mes, int anio) {
    if (anio < 0 || mes < 1 || mes > 12) {
        return 0;
    }

    int diasEnMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (mes == 2 && esAnioBisiesto(anio)) {
        diasEnMes[1] = 29;
    }

    if (dia < 1 || dia > diasEnMes[mes - 1]) {
        return 0;
    }

    return 1;
}

void mostrarFecha(int dia, int mes, int anio) {
    if (esFechaValida(dia, mes, anio)) {
        printf("La fecha es: %04d/%02d/%02d\n", anio, mes, dia);
    } else {
        printf("La fecha ingresada no es válida.\n");
    }
}

int main() {
    int dia, mes, anio;

    printf("Ingrese el numero de dia: ");
    scanf("%d", &dia);

    printf("Ingrese el numero de mes: ");
    scanf("%d", &mes);

    printf("Ingrese el numero de año: ");
    scanf("%d", &anio);

    mostrarFecha(dia, mes, anio);

    return 0;
}

