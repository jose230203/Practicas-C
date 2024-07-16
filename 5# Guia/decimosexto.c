#include <stdio.h>

int main() {
    int n,i,voto;
    int favor = 0, contra = 0, abstencion = 0;

    printf("Ingrese el numero total de diputados: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("Ingrese el voto del diputado %d (1 - A favor, 2 - En contra, 3 - Abstencion): ", i);
        scanf("%d", &voto);

        switch (voto) {
            case 1:
                favor++;
                break;
            case 2:
                contra++;
                break;
            case 3:
                abstencion++;
                break;
            default:
                printf("Opción invalida. Intente nuevamente.\n");
                i--; 
                break;
        }
    }

    float porcentaje_favor = (favor * 100.0) / n;
    float porcentaje_contra = (contra * 100.0) / n;
    float porcentaje_abstencion = (abstencion * 100.0) / n;

    printf("\nResultados de la encuesta:\n");
    printf("Porcentaje de diputados a favor: %.2f%%\n", porcentaje_favor);
    printf("Porcentaje de diputados en contra: %.2f%%\n", porcentaje_contra);
    printf("Porcentaje de diputados que se abstienen de opinar: %.2f%%\n", porcentaje_abstencion);

    return 0;
}

