#include <stdio.h>

int mcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

void simplificar(int a, int b) {
    int divisor = mcd(a, b);
    int num1,num2;

   num1 = a / divisor;
    num2 = b / divisor;
    
    
    printf("El primer numero simplificado es: %d\n", num1);
    printf("El segundo numero simplificado es: %d\n", num2);

}

int main() {
    int num1, num2;

    printf("Ingrese el primer numero entero: ");
    scanf("%d", &num1);

    printf("Ingrese el segundo numero entero: ");
    scanf("%d", &num2);

    simplificar(num1, num2);

    return 0;
}

