#include <stdio.h>

float calcularSalario(int horasTrabajadas, float salarioHora) {
    float salarioTotal;

    if (horasTrabajadas <= 40) {
        salarioTotal = horasTrabajadas * salarioHora;
    } else {
        int horasExtras = horasTrabajadas - 40;
        salarioTotal = (40 * salarioHora) + (horasExtras * salarioHora * 1.5);
    }

    return salarioTotal;
}

int main() {
    int horasTrabajadas;
    float salarioHora;

    printf("Ingrese el numero de horas trabajadas: ");
    scanf("%d", &horasTrabajadas);

    printf("Ingrese el salario por hora: ");
    scanf("%f", &salarioHora);

    float salario = calcularSalario(horasTrabajadas, salarioHora);

    printf("El salario total es: %.2f\n", salario);

    return 0;
}

