#include<stdio.h>
#include<conio.h>
int i;
int main (){
    printf("cuantas veces desea repetir\n");
    scanf("%d",&i);
    do
    {
    printf("Hola mundo\n");
i=i-1;
    } while (i>0);
    getch();
}