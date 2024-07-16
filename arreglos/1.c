#include <stdio.h>

int main(){
int i;
float a[5];
    for(i=0;i<=4;i++)
    {
        printf("Ingrese el digito %d  ",i);
        scanf("%f",&a[i]);
    }

    for (i=0;i<=4;i++)
    printf("el numero en la casilla %d es : %.2f\n",i,a[i]); 
    return 0;
}