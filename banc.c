//banco
#include <stdio.h>

int main(){
	float in,d,i,f,t;
	
	printf("cual es su capital inicial?\n");
	scanf("%f",&in);
	printf("cuanto dinero depositara\n");
	scanf("%f",&d);
	printf("cual es su tipo de interes\n");
	scanf("%f",&i);
	
	f=in+d;
	t=f*(i/100);
	
	printf("su cantidad total es %.2f\n",f);
	printf("sus intereses son: %.2f\n",t);
	
}
