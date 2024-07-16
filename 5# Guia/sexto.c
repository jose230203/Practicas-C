#include <stdio.h>
#define PI 3.14159

int main() {
    int i,radio,numero=1;

    for (i = 1; i <= 5; i++) {
        printf("%d ", i);
        printf("%d ", -i);
    }
    printf("\n");
     for (radio = 1; radio <= 5; radio++) {
        double area = PI * radio * radio;
        printf("El area de la circunferencia de radio %d es: %.2f\n", radio, area);
    }
    printf("\n");
    
    for (i = -101; i <= -81; i += 2) {
        printf("%d ", i);
    }
    printf("\n");
    
      for (i = 64; i >= 44; i -= 4) {
        printf("%d ", i);
    }
    printf("\n");
    
     for (i = 1; i <= 5; i++) {
        printf("%d ", numero);
        numero *= 10;
    }
    
    return 0;
}
