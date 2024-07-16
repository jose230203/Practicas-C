#include <stdio.h>
#include <math.h>

void convertirCoordenadas(float r, float theta) {
	  float coordenadaX, coordenadaY;
    coordenadaX = r * cos(theta);
    coordenadaY = r * sin(theta);
    printf("Las coordenadas cartesianas son: x = %.2f, y = %.2f\n", coordenadaX, coordenadaY);
}

int main() {
    float radio, angulo, coordenadaX, coordenadaY;

    printf("Ingrese el radio (r): ");
    scanf("%f", &radio);

    printf("Ingrese el angulo (en radianes, J): ");
    scanf("%f", &angulo);

    convertirCoordenadas(radio, angulo);

    return 0;
}

