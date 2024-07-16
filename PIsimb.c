//PI simbolica
#include <stdio.h>
#define PI 3.1416

int main(){
	float r,c;
	
	printf("digite el radio\n");
	scanf("%f",&r);
	
	c=2*PI*r;
	
	printf("su circunferencia es de: %.2f\n",c);
	
	return 0;
}
