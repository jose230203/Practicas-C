//Primero
#include <stdio.h>

int main() {
    int a;

    printf("Elija una opción (1-9):\n");
    printf("1. Mercurio\n");
    printf("2. Venus\n");
    printf("3. Tierra\n");
    printf("4. Marte\n");
    printf("5. Jupiter\n");
    printf("6. Saturno\n");
    printf("7. Urano\n");
    printf("8. Neptuno\n");
    printf("9. Pluton \n");
    scanf("%d", &a);

    switch (a) {
        case 1:
            printf("Este planeta se encuentra a 59 Millones de kilometros de distancia de el sol.\n");
            break;
        case 2:
            printf("Este planeta se encuentra a 108 Millones de kilometros de distancia de el sol.\n");
            break;
        case 3:
             printf("Este planeta se encuentra a 150 Millones de kilometros de distancia de el sol.\n");
            break;
             case 4:
             printf("Este planeta se encuentra a 228 Millones de kilometros de distancia de el sol.\n");
            break;
             case 5:
             printf("Este planeta se encuentra a 750 Millones de kilometros de distancia de el sol.\n");
            break;
             case 6:
             printf("Este planeta se encuentra a 1431 Millones de kilometros de distancia de el sol.\n");
            break;
             case 7:
             printf("Este planeta se encuentra a 2877 Millones de kilometros de distancia de el sol.\n");
            break;
             case 8:
             printf("Este planeta se encuentra a 4509 Millones de kilometros de distancia de el sol.\n");
            break;
             case 9:
             printf("Este planeta se encuentra a 5916 Millones de kilometros de distancia de el sol.\n");
            break;
        default:
            printf("ERROR: <%d>no está asociado a ningún planeta.\n",a);
            break;
    }

    return 0;
}

