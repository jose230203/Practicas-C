//azucar y cafe
#include <stdio.h>
#define KA 2
#define KC 3

int main(){
	float r,e,a,c;
	
	printf("Cuantos euros tienes\n");
	scanf("%f",&e);
	
	a=(e/2)/KA;
	c=(e/3)/KC;
	r=e/4;
	
	printf("se compro %.2f de azucar\n",a);
	printf("se compro %.2f de cafe\n",c);
	printf("el restante es de %.2f\n",r);
	
	return 0;
}
