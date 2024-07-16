#include <stdio.h>

int main(){
    int x[10]={1,2,3,4,5,6,7,8,9,10};
    printf("%8s  %9s %11s %13s \n","Numero Ruc","pieza","cant noches","Costo final");
    for (int i = 0; i < 5; i++)
    {
        printf("%d %8s",x[i]," ");
    }
    

}