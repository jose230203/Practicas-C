#include <stdio.h>

int main(){
    int i,n;
float a[n],b[n];

    printf("Cuantos numeros ingresara? ");
    scanf("%d",&n);

    for(i=0;i<=n-1;i++)
    {
        printf("Ingrese el digito %d  ",i);
        scanf("%f",&a[i]);
        b[i]= a[i]*5;
    }
    for (i=0;i<=n-1;i++)
    {
    printf("el numero en la casilla %d es : %.2f y este numero multiplicado por 5 es : %.2f\n",i,a[i],b[i]);
    }

}