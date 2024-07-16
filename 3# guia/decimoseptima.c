#include <stdio.h>
int main(){
	int a,b;
	char f;
	float c;
	printf("Ingrese la clasificacion A)Estudiante B)Empleado C)Empleador: ");
    scanf(" %c", &f);

    printf("Ingrese el numero de dias de retraso: ");
    scanf("%d", &a);

    printf("Ingrese el numero de libros prestados: ");
    scanf("%d", &b);
    switch(f)
{
    case 'A' : case 'a': 
if (a<=10)
    {
       c = (a*b) * 4.0 ;
	}
	else
	{
		c= (a*b) * 15.0;
	}
    break;
    case 'B' : case 'b': 
    if (a<=10)
    {
       c = (a*b) * 5.0 ;
	}
	else
	{
		c= (a*b) * 15.0;
	}
    break;
    case 'C' : case 'c':
	if (a<=10)
    {
       c = (a*b) * 7.0 ;
	}
	else
	{
		c= (a*b) * 15.0;
	}
    break;
}
    printf("La cantidad a pagar es de %.2f",c);
    return 0;
}
