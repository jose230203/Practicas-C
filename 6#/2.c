#include <stdio.h>
#include <math.h>
int main (){
	float a;
	printf("Digite el numero a elevar a el cubo ");
	scanf("%f",&a);
	
	printf("El numero a %.2f elevado a el cubo es : %.2f",a,pow(a,3));
}
