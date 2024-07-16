#include <stdio.h>

#define IMPUESTO 0.1
#define LIMITE_EXENTO 1000

int main() {
    int horas_trabajadas, tipo_trabajador,i;
    float sueldo_hora, sueldo_bruto, impuesto, sueldo_neto;
    float total_trabajadores = 0, total_empleados = 0;

    for (i = 1; i <= 25; i++) {
        printf("Trabajador %d:\n", i);
        printf("Ingrese las horas trabajadas: ");
        scanf("%d", &horas_trabajadas);
        printf("Ingrese el sueldo por hora: ");
        scanf("%f", &sueldo_hora);
        printf("Ingrese el tipo de trabajador (1 - Obrero, 2 - Empleado): ");
        scanf("%d", &tipo_trabajador);

        sueldo_bruto = horas_trabajadas * sueldo_hora;

        if (tipo_trabajador == 1) {
            impuesto = sueldo_bruto < LIMITE_EXENTO ? 0 : sueldo_bruto * IMPUESTO;
            sueldo_neto = sueldo_bruto - impuesto;
            total_trabajadores += sueldo_neto;
        } else if (tipo_trabajador == 2) {
            impuesto = sueldo_bruto < LIMITE_EXENTO ? 0 : sueldo_bruto * IMPUESTO;
            sueldo_neto = sueldo_bruto - impuesto;
            total_empleados += sueldo_neto;
        } else {
            printf("Tipo de trabajador inválido. Intente nuevamente.\n");
            i--;
            continue;
        }

        printf("Pago a realizar: %.2f\n\n", sueldo_neto);
    }

    printf("Total a pagar a los trabajadores: %.2f\n", total_trabajadores);
    printf("Total a pagar a los empleados: %.2f\n", total_empleados);

    return 0;
}

