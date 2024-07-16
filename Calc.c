//Jose Ramon Figueroa roa Ing. computacion
#include<stdio.h>
#include<conio.h>
int g,i;
float a,b,c;
int main(){
  do
  {
    printf("Jose230203\n");
    printf("que desea hacer\n");
    printf("1)Suma\n");
    printf("2)Resta\n");
    printf("3)Multiplicacion\n");
    printf("4)Division\n");
    printf("5)Salir\n");
    scanf("%d",&g);
    if (g<5||g>5)
 {
     printf("digite un numero\n");
 scanf("%f", &a);
 printf("digite el segundo numero\n");
 scanf("%f",&b);
 switch (g)
 {
 case 1:
  c=a+b;
   break;
 case 2:
 c=a-b;
  break;
 case 3:
 c=a*b;
  break;
 case 4:
 if (b==0)
 {
  printf("");
 }
 else
 {
   c=a/b;
 }
 break;
   case 5:
   printf("\n");
   break;
 default:
 printf("Ingreso un numero incorrecto\n");
    break;
 }
    if(g==4&&b==0)
    {
        printf("No se puede dividir 0\n");
        for ( i = 0; i < 21; i++)
{
  printf("\n");
}
}
else
{
    printf("el resultado de su ecuacion es : %0.2f\n",c);
    for ( i = 0; i < 21; i++)//intento de limpiar pantalla :V
{
  printf("\n");
}
}
 }
 else
 {
 printf("adios\n");
 }
  } while(g<5);
 getch();//pausa en el programa
}