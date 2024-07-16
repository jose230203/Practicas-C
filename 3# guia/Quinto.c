#include <stdio.h>

int main() 
{
float CAL;
const float TD = 1.08;
const float TS = 1.66; float T;
int D;
int AC;
    
    printf("Seleccione una actividad:\n");
    printf("1. Dormir\n");
    printf("2. en reposo\n");
    scanf("%d", &AC	);

    switch (AC) {
        case 1:
            T = TD;
            break;
        case 2:
            T = TS;
            break;
        default:
            printf("ERROR: Actividad no VAlida.\n");
            return 1;
    }


    printf("Ingrese la duracion en minutos:\n");
    scanf("%d", &D);

  
     CAL = T * D * 70;

    
    printf("Calorias consumidas: %.2f\n", CAL);

    return 0;
}

