//programa1
#include<stdio.h>
#include<process.h>

int main(){
	int a,b;
	float c;
	
	printf("ingrese los 2 digitos\n");
	scanf("%d%d",&a,&b);
	printf("la suma es :%d\n",a+b);
	printf("el producto es :%d\n",a*b);
	printf("la diferencia de a y b es :%d\n",a-b);
	c=a%b;
	printf("modulo es :%.2	f\n",c);
	
	return 0;
}
