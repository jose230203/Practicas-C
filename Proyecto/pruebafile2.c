#include <stdio.h>
 typedef struct prueba prueba;
 struct prueba
 {
    int cod;
    char name[30];
 };

int main(){
    int i;
    FILE *Archivo;
    prueba prueba[5]={0};
    Archivo= fopen("Prueba.txt", "r");
    fread(&prueba,sizeof(struct prueba), 5 ,Archivo);
    for ( i = 0; i < 5; i++)
    {
        printf("Nombre: %s  Codigo: %d\n",prueba[i].name,prueba[i].cod);    
    }
    
    
}