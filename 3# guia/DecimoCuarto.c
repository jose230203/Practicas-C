#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int a;
    float b, c, d;
 srand(time(NULL));
 a= rand() % 200;
    printf("Su numero azar es : %d\n",a);
    
    printf("Introduce el total de la compra: ");
    scanf("%f", &b);

    if (a < 74) {
        c = 0.15; 
    } else {
        c = 0.20;
    }

  
    d = b * c;

   
    printf("El descuento es de %.2f euros.\n", d);

    return 0;
}

