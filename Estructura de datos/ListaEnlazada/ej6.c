/* Ejercicio 6
La Tienda “Compra Feliz”, desea registrar la información 
de sus productos (código, descripción, precio). 
Para ello ha solicitado un programa que presente
las siguientes opciones:
Ingresar Productos
Mostrar Productos
Producto con mayor precio
Producto con menor precio
Salir
El usuario debe poder ingresar tantos productos 
como necesite (n productos).
Cuando seleccione mostrar que presente 
la lista de todos los productos (código,
descripción, precio) en funcion del comportamiento LIFO
Primero en Entrar Primero en Salir (PILA) 
en la lista de productos. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
 
struct Data
{
    int codigo;              
    char  descripcion[50];
    float precio;
};

struct Node
{
    struct Data data;
    struct Node* next;      
};
 
void push(struct Node **top, struct Data x)       
{

    struct Node* node = NULL;
    node = (struct Node*)malloc(sizeof(struct Node));
    
    if (!node)
    {
        printf("\nDesbordamiento");
        exit(1);
    }
 
    printf("\nInsercion correcta\n");
    node->data = x;
    node->next = *top;
    *top = node;
    getch();
    system("cls");  
}
 
int isEmpty(struct Node* top) {
    return top == NULL;
}
 

struct Data peek(struct Node *top)
{

    if (!isEmpty(top)) {
        return top->data;
    }
    else {
        exit(EXIT_FAILURE);
    }
}
 

void pop(struct Node** top)     
{
    struct Node *node;
 
    system("cls");
    if (*top == NULL)
    {
        printf("\nDesbordamiento de la Pila");
        exit(1);
    }
 
    printf("Eliminando %d\n", peek(*top));
 
    node = *top;
 
    *top = (*top)->next;
 
    free(node);
}


void MostrarProductos(struct Node *top)
{

    system("cls");  
	printf("Lista de Productos\n");
	while (!isEmpty(top))
    {
        printf("Codigo: %d\n",top->data.codigo);
        printf("Descripcion: %s\n",top->data.descripcion);
        printf("Precio: %.2f\n\n",top->data.precio);
        top = top->next;
    }
    getch();
    system("cls");  
}

void PrecioMasAlto(struct Node *top)
{
    struct Node *temp = top;

    system("cls");  
	while (!isEmpty(temp))
    {
   
        if(top->data.precio < temp->data.precio) top = temp;

        temp = temp->next;
    }


    printf("Codigo: %d\n",top->data.codigo);
    printf("Descripcion: %s\n",top->data.descripcion);
    printf("Precio: %.2f\n",top->data.precio);
    getch();
    system("cls");  

}

 

void PrecioBajo(struct Node *top)
{
    struct Node *temp = top;
    
	system("cls");
    while (!isEmpty(temp))
    {
        if(top->data.precio > temp->data.precio) top = temp;
        temp = temp->next;
    }
    printf("Codigo: %d\n",top->data.codigo);
    printf("Descripcion: %s\n",top->data.descripcion);
    printf("Precio: %.2f\n",top->data.precio);   
    getch();
    system("cls");  
}

int main()
{
    struct Node* top = NULL;
    int val;

    while(1){	
        printf("\nTIENDA COMPRA FELIZ");
		printf("\n1. Ingresar producto");
        printf("\n2. Mostrar productos");
        printf("\n3. Producto con mayor precio");
        printf("\n4. Producto con menor precio");
        printf("\n5. Salir ");
        printf("\nSeleccione la opcion ");
        scanf("%d",&val);

        if(val==1){
            struct Data a;
            
            system("cls");
            printf("\n\nIntroducir codigo: ");
            scanf("%d",&a.codigo);
            printf("\nIntroducir descripcion: ");
            scanf(" %[^\n]%*c",a.descripcion);
            printf("\nIntroducir precio: ");
            scanf("%f",&a.precio);
            push(&top, a);
        }
        else if(val==2){
            MostrarProductos(top);
        }
        else if(val==3){
            PrecioMasAlto(top);
        }
        else if(val==4){
            PrecioBajo(top);
        }
        else{
            break;
        }
    }
    return 0;
}

