#include <stdio.h>

int main() {
    int numPacientes;
    int edad,i;
    float indice,edadMediaOperados,edadMedia,edadMediaIngresados;
    int totalPacientes = 0;
    int totalIngresados = 0;
    int totalOperados = 0;
    int sumaEdades = 0;
    int sumaEdadesIngresados = 0;
    int sumaEdadesOperados = 0;

    printf("Ingrese el numero de pacientes: ");
    scanf("%d", &numPacientes);

    for (i = 1; i <= numPacientes; i++) {
        printf("Paciente %d:\n", i);
        printf("Ingrese la edad: ");
        scanf("%d", &edad);
        printf("Ingrese el indice: ");
        scanf("%f", &indice);

        sumaEdades += edad;

        if (indice > 0.6) {
            sumaEdadesIngresados += edad;
            totalIngresados++;

            if (indice > 0.9) {
                sumaEdadesOperados += edad;
                totalOperados++;
            }
        }

        printf("\n");
    }

    if (numPacientes > 0) {
      edadMedia = (float)sumaEdades / numPacientes;
      edadMediaIngresados = (float)sumaEdadesIngresados / totalIngresados;
      edadMediaOperados = (float)sumaEdadesOperados / totalOperados;

        printf("Edad media de los pacientes analizados: %.2f\n", edadMedia);
        printf("Edad media de los pacientes ingresados: %.2f\n", edadMediaIngresados);
        printf("Edad media de los pacientes operados: %.2f\n", edadMediaOperados);
    } else {
        printf("No se han ingresado pacientes.\n");
    }

    return 0;
}

