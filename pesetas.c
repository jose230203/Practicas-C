//pesetas
#include <stdio.h>
#define CAM 166.386
int main(){
	int p;
	float e;
	
	printf("ingrese sus pesetas");
	scanf("%d",&p);
		
	e=CAM/p;
	
	printf("sus pesetas convertidas a euros son: %.2f",e);
	
}
