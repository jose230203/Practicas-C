#include <stdio.h>
#define PI 3.14159

int main() {
    int radio;

    for (radio = 1; radio <= 5; radio++) {
        double area = PI * radio * radio;
        printf("El area de la circunferencia de radio %d es: %.2f\n", radio, area);
    }

    return 0;
}

