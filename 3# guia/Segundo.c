#include <stdio.h>

int main() {
    int a,b,c;
    float d = 0.0;

        printf("Ingrese el tipo de llamada 1=Internacional, 2=Nacional, 3=Local \n");
        scanf("%d", &a);
        
        printf("Cuantas llamadas ah hecho?\n");
        scanf("%d", &c);

        printf("Ingrese la duración de la llamada en minutos:\n");
        scanf("%d", &b);

        switch (a) {
            case 1: // Internacional
                if (b <= 3) {
                    d += 7.59;
                } else {
                    d += 7.59 + (b - 3) * 3.03;
                }
                break;
            case 2: // Nacional
                if (b <= 3) {
                    d += 1.20;
                } else {
                    d += 1.20 + (b - 3) * 0.48;
                }
                break;
            case 3: // Local
                if (c >= 50)
				 {
                    d += 0.60;
                 }
				 else
				  {
    
                  }
                break;
            default:
                printf("Tipo de llamada no válido.\n");
                break;
        }

    printf("El costo total de las llamadas es: $%.2f\n", d);
getch();
    return 0;
}
