#include<stdio.h>
#include<conio.h>

int a,b,c;
int main (){
 printf("digite un numero\n");//escrir pseint
 scanf("%d", &a);//leer entero
 printf("digite el segundo numero\n");//escribir \n es para bajar 1 linea
 scanf("%d",&b);//escribir entero
 c=a+b;
 printf("\nla suma de sus digitos es : %d",a+b);//suma ahora toca probar como sumar antes xD
 printf("\n%d",a);
 printf("\nla suma de sus digitos es : %d",c);//aqui ya descubri como hacer la suma y mostrarla xD
    getch(); //Pausa 
}