#include <stdio.h>

int main(){
	int hab;
	do
	{
	printf("En cual Habitacion desea quedarse?\n");
	printf("1)Azul\n");
	printf("2)Roja\n");
	printf("3)Verde\n");
	printf("4)Rosa\n");
	printf("5)Gris\n");
	printf("6)Salir\n");
	scanf("%d",&hab);
	
	switch(hab)
	{
		case 1 :
			printf("la habitacion Azul se encuentra en la primera planta  y tiene 2 camas\n");
			break;
		case 2 :
			printf("la habitacion Roja se encuentra en la primera planta x y tiene 1 camas\n");
			break;
		case 3 :
			printf("la habitacion Verde se encuentra en la segunda planta y tiene 3 camas\n");
			break;
		case 4 :
			printf("la habitacion Rosa se encuentra en la segunda planta y tiene 2 camas\n");
			break;
		case 5 :
			printf("la habitacion Gris se encuentra en la tercera planta y tiene 1 camas\n");
			break;
		case 6 :
			printf("Salio de el ciclo");
			break;
		default :
		printf("ERROR: <%d> no esta asociado a ninguna habitación.\n",hab);
		break;
	}
    }while(hab!=6);
    return 0;
}
