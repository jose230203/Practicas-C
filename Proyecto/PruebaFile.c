#include <stdio.h>
 FILE *Archivo;
 typedef struct prueba prueba;
 struct prueba
 {
    int cod;
    char name[30];
 };


 int main (){
    prueba prueba[5];
    int i;
    fflush(Archivo);
    for ( i = 0; i < 5; i++)
    {
        printf("Ingrese el nombre de el prueba %d ",i);
        scanf("%s",prueba[i].name);
        printf("Ingrese el codigo de : %d ",i);
        scanf("%d",&prueba[i].cod);
    }
        Archivo = fopen("Prueba.txt","w");
        if (Archivo)
        {
           fwrite(prueba,sizeof(struct prueba),5,Archivo);
           fflush(Archivo);
           fclose(Archivo);
        }
        else
        if (Archivo==NULL)
        {
            perror("Error en la creacion de archivo\n\n");
        }
       
        
        

    return 0;
 }