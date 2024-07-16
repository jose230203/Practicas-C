//horas etc
#include <stdio.h>

int main(){
	int h,m,s,t;
	
	printf("ingrese que hora es ingresando por partes Hora Minuto y Segundo\n");
	scanf("%d%d%d",&h,&m,&s);
 t=h*3600;	
 t=t+m*60;
 t=t+s;	
	
	printf("han pasado un total de: %d segundos",t);
	
	return 0;
}
