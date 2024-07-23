#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
int c=0;
int s=0;
char cent[5];


typedef struct peliculas peliculas;
typedef struct socio socio;

struct peliculas {
    int codigo;
    char nombre[50];
    char estadoCinta[20];
    bool sticker;
    char fecha[10];
    int historial;
    int demora;
};

struct socio
{
   char name[30];
   char numcedula[20];
   int codS;
   int abonos;
   int historial[50];
};
void registrarNuevoSocio(socio *new);
void ingresarpeliculas(peliculas *nueva);
void solicitarPelicula(peliculas *pelis,socio *user );
void devolverPelicula(socio *socios, peliculas *pelicula);
void generarListadoPeliculasExtraidas(peliculas *pelicula, int);
void generarListadoSociosDemorados(socio *socios, int,int,peliculas *pelicula);
void generarRankingPeliculasAlquiladas(socio *socios, int,int,peliculas *pelicula);



int main(){
    bool exit=true;
    int i,cant,cantS;
    int men;
    FILE *Archivo;
    
  peliculas pelicula[50]={};
  socio socios[50]={};
    for (i = 0; i < 50; i++) 
    {
    socios[i].codS = 0;
    }
    pelicula[0].codigo=1001;
  strcpy(pelicula[0].nombre, "Titanic");
   strcpy(pelicula[0].estadoCinta, "Buen estado");
   pelicula[0].sticker= false;
    pelicula[1].codigo=1002;
    strcpy(pelicula[1].nombre, "El senior de los anillos");
    strcpy(pelicula[1].estadoCinta, "Mal estado");
    pelicula[1].sticker= false;
    pelicula[2].codigo=1003;
    strcpy(pelicula[2].nombre, "Matrix");
    strcpy(pelicula[2].estadoCinta, "Buen estado");
    pelicula[2].sticker= false;
    pelicula[3].codigo=1004;
  strcpy(pelicula[3].nombre, "v de vendetta");
   strcpy(pelicula[3].estadoCinta, "Buen estado");
    pelicula[3].sticker= false;
    pelicula[4].codigo=1005;
  strcpy(pelicula[4].nombre, "El Gato Con Botas");
   strcpy(pelicula[4].estadoCinta, "Buen estado");
    pelicula[4].sticker= false;
    pelicula[5].codigo=1006;
  strcpy(pelicula[5].nombre, "La Sirenita");
   strcpy(pelicula[5].estadoCinta, "Buen estado");
    pelicula[5].sticker= false;
    pelicula[6].codigo=1007;
  strcpy(pelicula[6].nombre, "Pinocho de Guillermo del Toro");
   strcpy(pelicula[6].estadoCinta, "Buen estado");
    pelicula[6].sticker= false;
      pelicula[7].codigo=1008;
  strcpy(pelicula[7].nombre, "AVATAR");
   strcpy(pelicula[7].estadoCinta, "Buen estado");
    pelicula[7].sticker= false;
      pelicula[8].codigo=1009;
  strcpy(pelicula[8].nombre, "El Titere");
   strcpy(pelicula[8].estadoCinta, "Buen estado");
    pelicula[8].sticker= false;
      pelicula[9].codigo=1010;
  strcpy(pelicula[9].nombre, "Pacific Rim 1");
   strcpy(pelicula[9].estadoCinta, "Buen estado");
    pelicula[9].sticker= false;
    
    do
    {
        printf("\tM  E  N  U  \n");
        printf("\t1)Comprar Peliculas o Verificar su estado\n");//Listo
        printf("\t2)Registrar Nuevos Socios\n");//listo
        printf("\t3)Un Socio quiere alquilar\n");//Listo
        printf("\t4)Socio devuelve el alquiler\n");//listo
        printf("\t5)Terminar Dia\n");//En proceso
        scanf("%d",&men);
        switch (men)
        {
        case 1:
           ingresarpeliculas(&pelicula[0]);
            break;
        case 2:
          registrarNuevoSocio(&socios[0]);
            break;
        case 3:
        printf("Tenemos la siguiente cartelera");
         for (int i = 0; i < 10+c; i++) {
        printf("Nombre: %s\t", pelicula[i].nombre);
        printf("Codigo: %d\n",pelicula[i].codigo);
        printf("\n");
    }
        solicitarPelicula(&pelicula[0],&socios[0]);
            break;
        case 4:
        devolverPelicula(&socios[0],&pelicula[0]);
            break;
        case 5:
        cant=c+10;
        cantS=s;
            generarListadoPeliculasExtraidas(&pelicula[0],cant);
            generarListadoSociosDemorados(&socios[0],cantS,cant,&pelicula[0]);
            generarRankingPeliculasAlquiladas(&socios[0],cantS,cant,&pelicula[0]);

        exit=false;
            break;        
        default:
            break;
        case 6 :
        for ( i = 0; i < 2; i++)
        {
            printf("%s\n",socios[i].name);
            printf("%d\n",socios[i].codS);
            printf("%s\n",socios[i].numcedula);
            printf("%d\n",socios[i].abonos);
        }
        
        break;
        }

     } while (exit);
    
}
void ingresarpeliculas(peliculas *nueva)
{
    int aux;
    char estado[30] = {"Buen estado"};
    bool existe = false;
    int indice = 0; // Variable para rastrear la posición en el arreglo

    do
    {

        printf("Ingrese el codigo de la pelicula: ");
        scanf("%d", &aux);

        for (indice = 0; indice < 50; indice++) // Iterar hasta 50 en lugar de 49
        {
            if (nueva[indice].codigo == aux)
            {
                existe = true;
                printf("La cinta ya existe y su estado es: %s\n", nueva[indice].estadoCinta);
                
                if (strcmp(nueva[indice].estadoCinta, estado) == 0)
                {
                    printf("La cinta esta en buen estado y se encuentra en el catálogo, así que no se comprara.\n");
                    break;
                }
                else
                {
                    printf("Se cambiará la cinta por la nueva en buen estado.\n");
                    strcpy(nueva[indice].estadoCinta, "Buen estado");
                    break;
                }
            }
        }

        if (existe)
        {
            break;
        }

        for (indice = 0; indice < 50; indice++)
        {
            if (nueva[indice].codigo == 0)
            {
                nueva[indice].codigo = aux;
                printf("Ingrese el nombre de la pelicula: ");
                scanf(" %20s", nueva[indice].nombre);
                fflush(stdin);
                printf("Ingrese el estado de la pelicula: ");
                gets(nueva[indice].estadoCinta);

                break;
            }
        }
    
     printf("Desea Comprar mas peliculas? \n");
     scanf(" %2s", cent);
     c++;
    
    } while (strcmp(cent, "NO") != 0 && strcmp(cent, "no") != 0 && strcmp(cent, "No") != 0);
}
void registrarNuevoSocio(socio *new)
{
    bool leave=true;
    int preciounit=50,cobro,cant,i;
    float cambio;

    while (leave)
    {
    printf("Cobrar minimo 10 abonos para la suscripcion el Precio de cada abono es de : %d y cuantos bonos comprara ",preciounit);
    scanf("%d %d",&cobro,&cant);
    cambio = cobro-(cant*preciounit);
    if (cobro>=500)
    {
        printf("El cambio a entregar es de : %.2f\n",cambio);
        leave=false;
        for ( i = 0; i < 50; i++)
        {
        if (new[i].codS == 0)
        {
        printf("Ingrese el numero de cedula : ");
        scanf(" %20s",new[i].numcedula);
        printf("Ingrese el nombre de el Socio  ");
        scanf(" %s",new[i].name);
        new[i].abonos = cant;
        new[i].codS = 100+i;
        s++;
        break;
        }
        }
    }
    else{
         printf("Cantidad invalida\n");
    }
    }
}
void solicitarPelicula(peliculas *pelis,socio *user )
{
    int codigoPelicula;
    int codigoSocio,cobro,cant,cambio;
    int i, j,k,opc;
    int try=3;

    printf("Ingrese el codigo de la pelicula que desea alquilar: ");
    scanf("%d", &codigoPelicula);

  
    for (i = 0; i < 50; i++)
    {
        if (pelis[i].codigo == codigoPelicula)
        {
            // Verificar si la película está disponible para alquilar
            if (strcmp(pelis[i].estadoCinta, "Buen estado") == 0 && pelis[i].sticker == false)
            {
                printf("La pelicula '%s' esta disponible para alquilar.\n", pelis[i].nombre);

                do{
                printf("Ingrese el codigo del socio: ");
                scanf("%d", &codigoSocio);

                
                for (j = 0; j < 50; j++)
                {
                    if (user[j].codS == codigoSocio)
                    {
                        // Registrar el alquiler en el historial del socio
                        for (k = 0; k < 50; k++)
                        {
                            if (user[j].historial[k] == 0)
                            {
                                user[j].historial[k] = codigoPelicula;
                                break;
                            }
                        }

                        
                        pelis[i].sticker = true;
                        strcpy(pelis[i].estadoCinta, "Alquilada");
                        while(1)
                        {
                        if (user[j].abonos==0)
                        {
                            printf("Usted no tiene mas bonos puede comprar nuevos bonos o pagar unicamente el alquiler  1)Comprar nuevos abonos 2)Pagar con 50$");
                            scanf("%d",&opc);
                            if (opc==1)
                            {
                                printf("dinero ingresado y cantidad de abonos a pagar");
                                scanf("%d %d",&cobro,&cant);
                                cambio= cobro-(cant*50);
                                if (cambio>=0)
                                {
                                printf("Su cambio es de : %d",cambio);
                                user[j].abonos=cant;
                                break;
                                }
                                else
                                {
                                    printf("No ingreso la cantidad correcta para pagar esa cantidad de abonos");
                                }
                            }else if (opc==2)
                            {
                                printf("Ingrese la cantidad de 50$");
                                scanf("%d",&cobro);
                                cambio=cobro-50;
                                if (cambio>=0)
                                {
                                    printf("Su cambio es de : %d",cambio);
                                    break;
                                }else
                                printf("Ingreso una cantidad menor a 50$");
                                
                            }
                            
                            
                        }else
                        {
                            user[j].abonos--;
                            break;
                        }
                        }
                        printf("Ingrese la fecha de alquiler dd/mm/aa");
                        scanf(" %10s",pelis[i].fecha);
                        printf("Alquiler registrado correctamente.\n");
                        return;
                    }
                }
                try--;
                printf("No se encontro un socio con el codigo ingresado. tienes %d intentos\n",try);
                
            }while(try != 0);
                return;
            }
            else
            {
                printf("La película no está disponible para alquilar.\n");
                return;
            }
        }
    }

    printf("No se encontró una película con el código ingresado.\n");
}   
void devolverPelicula(socio *socios, peliculas *pelicula)
{
    int codigoPelicula;
    int codigoSocio,tiempo;
    int i, j,penalizacion,cobro;

    printf("Ingrese el cóodigo de la pelicula que desea devolver: ");
    scanf("%d", &codigoPelicula);

    printf("Ingrese el codigo del socio que está devolviendo la pelicula: ");
    scanf("%d", &codigoSocio);
    printf("Cuanto tiempo tuvo la cinta (En horas)");
    scanf("%d",&tiempo);

    // Buscar la película en el arreglo de películas
    for (i = 0; i < 50; i++)
    {
        if (pelicula[i].codigo == codigoPelicula)
        {
            // Verificar si la película está alquilada
            if (strcmp(pelicula[i].estadoCinta, "Alquilada") == 0 && pelicula[i].sticker == true)
            {
                printf("La pelicula '%s' fue alquilada el dia %s\n",pelicula[i].nombre, pelicula[i].fecha);
                printf("La película '%s' ha sido devuelta.\n", pelicula[i].nombre);

                // Buscar el socio en el arreglo de socios
                for (j = 0; j < 50; j++)
                {
                    if (socios[j].codS == codigoSocio)
                    {
                        if (tiempo>=24)
                        {
                            penalizacion=tiempo/24;
                            pelicula[i].demora+= penalizacion;
                            if (socios[j].abonos>0)
                            {
                                printf("Se cobaran un total de %d abonos por los dias tardados en devolver la cinta ",penalizacion);
                            socios[j].abonos -= penalizacion;
                            }
                            else
                            {
                                printf("Por cada 24 horas se cobrara un alquiler\n");
                                printf("Se cobrara un total de : %d abonos\n",penalizacion);
                                while(1)
                                {
                                printf("Usted tiene que pagar un total de : %d $\n",penalizacion * 50);
                                scanf("%d",&cobro);
                                if (cobro < penalizacion * 50)
                                {
                                    printf("Ingreso una cantidad incorrecta\n");
                                }else
                                {
                                    printf("Pago correcto su cambio es de %d \n",cobro-(penalizacion * 50));
                                    break;
                                }
                                }
                                
                            }
                            
                        }
                        else
                        printf("No se llego a 24 horas por consecuencia no hay penalizacion\n");
                        
                        // Actualizar el estado de la película
                        pelicula[i].sticker = false;
                        strcpy(pelicula[i].estadoCinta, "Buen estado");

                        printf("Devolucion realizada correctamente.\n");
                        return;
                    }
                }

                printf("No se encontro un socio con el codigo ingresado.\n");
                return;
            }
            else
            {
                printf("La pelicula no se encuentra alquilada.\n");
                return;
            }
        }
    }

    printf("No se encontro una pelicula con el codigo ingresado.\n");
}
void generarListadoPeliculasExtraidas(peliculas *pelicula, int numPeliculas)
{
    printf("Listado de peliculas extraidas:\n");

    for (int i = 0; i < numPeliculas; i++)
    {
        if (strcmp(pelicula[i].estadoCinta, "Alquilada") == 0 && pelicula[i].sticker == true)
        {
            printf("Pelicula: %s\n", pelicula[i].nombre);
        }
    }
}
void generarListadoSociosDemorados(socio *socios, int numsocios,int numPeliculas,peliculas *pelicula)
{
  int diasDemora,codigoPelicula,k;
    printf("Listado de socios con peliculas demoradas por mas de una semana:\n");

    for (int i = 0; i < numsocios; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            if (socios[i].historial[j] != 0)
            {
                 codigoPelicula = socios[i].historial[j];
                for ( k = 0; k < numPeliculas; k++)
                {
                    if (codigoPelicula == pelicula[k].codigo)
                    {
                       diasDemora=pelicula[k].demora;
                    }
                    
                }
                if (diasDemora >= 7)
                {
                    printf("Socio: %s, Pelicula: %20s, Dias de demora: %d\n", socios[i].name,pelicula[k].nombre, diasDemora);
                }
            }
        }
    }

}
void generarRankingPeliculasAlquiladas(socio *socios, int numsocios,int numPeliculas,peliculas *pelicula)
{
    printf("Ranking de peliculas mas alquiladas:\n");

    // Contador de alquileres por película
    int contadorAlquileres[50] = {0};

    // Contar alquileres por película
    for (int i = 0; i < numsocios; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            if (socios[i].historial[j] != 0)
            {
                contadorAlquileres[socios[i].historial[j] - 1001]++;
            }
        }
    }

    // Ordenar películas en base al contador de alquileres (Bubble sort)
    for (int i = 0; i < 49; i++)
    {
        for (int j = 0; j < 49 - i; j++)
        {
            if (contadorAlquileres[j] < contadorAlquileres[j + 1])
            {
                int temp = contadorAlquileres[j];
                contadorAlquileres[j] = contadorAlquileres[j + 1];
                contadorAlquileres[j + 1] = temp;
            }
        }
    }

    // Mostrar ranking
    for (int i = 0; i < numPeliculas; i++)
    {
        if (contadorAlquileres[i] > 0)
        {
            printf("Pelicula: %s, Alquileres: %d\n", pelicula[i].nombre, contadorAlquileres[i]);
        }
    }
}
