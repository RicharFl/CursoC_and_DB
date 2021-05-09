#include <stdio.h>
#include <stdlib.h>

typedef struct _NODO
{
    int dato;
    struct _NODO *sig;

} nodo;

nodo *Reservar(int dato)
{
    nodo *box = NULL; 
    box = (nodo *)malloc(sizeof(int));
    if (box != NULL)
    {
        box->dato = dato;
        box->sig = NULL;
        return box;
    }
}

nodo *Alta(int dato, nodo *cima)
{
    nodo *aux = NULL;
    aux = Reservar(dato);

    if (cima == NULL)
    {
        cima = aux;
        return cima;
    }
    else
    {
        aux->sig = cima;
        return aux;
    }
}

void mostrar(nodo *cima)
{
    int i = 0;
    if (cima == NULL)
    {
        printf("La PIla esta vacia \n");
    }

    else
    {
        while (cima->sig != NULL)
        {
            printf("ELEMTO [%d] : %d \n", i, cima->dato);
            cima = cima->sig;
            i++;
        }
        printf("ELEMTO [%d] : %d \n", i, cima->dato);
    }
    system ("pause");
}

nodo * Eliminar (nodo *cima)
{
 nodo *aux =NULL;
    if (cima==NULL)
    {
        printf ("La pila esta vacia, ya no se puede eliminar maas \n");

    }
    else{
        aux=cima ->sig;
        free(cima);
        cima=aux;
        return aux;
    }
     return cima;
}


int main(void)
{
    nodo * cima =NULL;
    char iter = 'S';
    int ops = 0;
    int dato=0;
    while (iter == 'S')
    {
        system("cls");
        printf("Bienvenidos  a la creacion de Pilas\n");
        printf("1- Ingresa un dato \n");
        printf("2- Elimins un dato \n");
        printf("3- Mostrar Datos  \n");
        scanf("%d", &ops);
        switch (ops)
        {
        case 1:
        system("cls");
        printf("INGRESE EL DATO: \n");
        scanf("%d",&dato);
        cima=Alta(dato,cima);
        printf("\n Dato Ingreado Correctamente");
        system ("pause");


            break;
        case 2:
        printf("eliminando \n");
            cima=Eliminar(cima);
            system ("pause");

            break;
        case 3:
            mostrar(cima);
            system ("pause");
            break;

        default:
            break;
        }
    }
}
