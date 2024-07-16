#include <stdio.h>

int main() {
    int edad;
    char salud;

    printf("Ingrese la edad del trabajador: ");
    scanf("%d", &edad);

    printf("Ingrese el estado de salud del trabajador (E = Excelente, B = Buena, R = Regular, M = Mala): ");
    scanf(" %c", &salud);
    if(edad>=65) printf("Jubilacion inmediata");
    else
    {
    	if(edad<=64 && edad>=60)
    	{
		
    	switch(salud)
    	{
    		
                case 'E': case 'e':
                    printf("Reporte Normal.\n");
                    break;
                case 'B':  case 'b':
                    printf("Vacaciones.\n");
                    break;
                case 'R':  case 'r':
                    printf("Descanso hasta Jubilación.\n");
                    break;
                case 'M':   case 'm':
                    printf("Solicitar evaluación médica para Jubilación - Incapacidad.\n");
                    break;
                default:
                    printf("Estado de salud inválido.\n");
                    break;
            
		}
	}
	else printf("Es muy joven para la jubilacion");
    }
	getch();
	return 0;
	}
