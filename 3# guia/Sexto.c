#include <stdio.h>

int main() {
    int A, B, C;
    printf("Introduce el valor de A: ");
    scanf("%d", &A);
    printf("Introduce el valor de B: ");
    scanf("%d", &B);

    if (A > B) 
	{
        C = B;
    } else if (A == B) 
	{
        C = A + B;
    } else 
	{
        C = A;
    }

    printf("El valor de C es: %d\n", C);

    return 0;
}
