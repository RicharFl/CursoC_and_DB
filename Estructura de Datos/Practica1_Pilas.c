#include <stdio.h>
#include <stdlib.h>

typedef struct _NODO
{
    int dato;          /* Este es dato que se encuentra en mi nodo*/
    struct _NODO *sig; /*Este es el apuntador con el que estaremos uniendo nodos */

}nodo;

/* Esta funcion Reservar memoria para ese nodo  1   int  =5555555555555 */
nodo * reservar(int d)
{
   nodo *tamano =NULL;
   tamano=(nodo *)malloc (sizeof(int));

   if (tamano!=NULL)
   {
       tamano-> dato =d;
       tamano ->sig =NULL;
        return tamano;
   }
   else 
   {
       return NULL;

   }

}


nodo * Alta (int dato, nodo * cima)
{
 
 
  nodo * aux=NULL;
  aux = reservar(dato);
  if (cima != NULL)
  {
      aux ->sig=cima;
      return aux;
  }
  else {
      return aux;
  }

}

void mostrar ( nodo *cima)
{
    int i =0;
    if ( cima ==NULL)
    {
        printf("La  Pila esta Vacia");
    }
    else{
        while (cima != NULL)
        {
         printf ("ELEMNTO [%d] : %d \n",i,cima->dato);
         
         cima =cima ->sig;
         i++;
        }
        
    }
}

int main(void)

{

    nodo * Pila = NULL;
    char menu = 's';
    int ops = 0,dato=0;
    while (menu == 's')
    {
        printf("\n BIENVENIDO ESCOJE ALGUNA DE NUESTRA OPCIONES\n \n");
        printf("1.-  INGRESAR NODO\n");
        printf("2.- ELIMINAR NODO \n");
        printf("3.- MOSTRAR PILA\n ");
        scanf("%i", &ops);
        switch (ops)
        {
        case 1:
        system("cls");
        printf("Ingresa tu dato\n ");
        scanf ("%d",&dato);
            Pila=Alta(dato,Pila);
        printf("El dato a sido ingresado Correctamente \n \n");
        system ("pause");

            break;
        case 2:
            break;
        case 3:
        system("cls");
        mostrar(Pila);
         system ("pause");
            break;
        

        default:
            break;
        }
    }
}


int suma (int a, int b)
{

}