#include <stdio.h>
#include <stdlib.h>

typedef struct _Nodo
{
    int dato;
    struct _Nodo *sig;
} nodo;

nodo *reservar(int dato)
{
    nodo *espacio;
    espacio = (nodo *)malloc(sizeof(int));
    if (espacio != NULL)
    {
        espacio->dato = dato;
        espacio->sig = NULL;
        return espacio;
    }
}

//ALTA FINAL

nodo *altaF(int dato, nodo *cima)
{
    nodo *nuevo, *aux;
    nuevo = reservar(dato);
    if (cima == NULL)
    {
        return nuevo;
    }
    else
    {
        aux = cima;
        while (aux->sig != NULL)
        {
            aux = aux->sig;
        }

        aux->sig = nuevo;
        return cima;
    }
}

//ALTAS AL INICIO

nodo *altaI(int dato, nodo *cima)
{
    nodo *box;
    box = reservar(dato);
    if (cima != NULL)
    {
        box->sig = cima;
    }
    return box;
}

// ALTA POR POSICION

nodo *altaPos(nodo *intermedio, int dato, int pos)
{
    nodo *aux;
    nodo *nuevo;
    int i, tam = 0;
    nuevo = reservar(dato);
    if (intermedio == NULL)
    {
        return nuevo;
    }
    else
    {
        aux = intermedio;
        tam = contar(intermedio);
        if (pos > tam)
        {
            printf("Se sale del rango");
        }
        else if (pos < 0)
        {
            printf("No hay rango");
        }
        else if (pos == 0)
        {
            printf("Est�s insertando al inicio");
            intermedio = altaI(dato, intermedio);
        }
        else if (pos == tam)
        {
            printf("Est�s insertando al final");
            intermedio = altaF(dato, intermedio);
        }
        else
        {
            for (i = 0; i < (pos - 1); i++)
            {

                aux = aux->sig;
            }
            nuevo->sig = aux->sig;
            aux->sig = nuevo;
        }
        return intermedio;
    }
}
// ALTA DATA

nodo *altaD(nodo *intermedio, int dato, int dato_lista)
{

    nodo *aux;
    nodo *nuevo;
    int encontrado;
    nuevo = reservar(dato);
    aux = intermedio;
    if (intermedio == NULL)
    {
        return intermedio;
    }
    else
    {

        while (aux->sig != NULL && encontrado != 1)
        {

            if (aux->dato == dato_lista)
            {

                nuevo->sig = aux->sig;
                aux->sig = nuevo;
                encontrado = 1;
            }
            else
            {

                aux = aux->sig;
            }
        }
    }

    return intermedio;
}

// BAJA INICIO

nodo *bajaI(nodo *cima)
{
    nodo *aux = NULL;
    if (cima != NULL)
    {
        aux = cima;
        cima = cima->sig;
        free(aux);
    }
    return cima;
}

// BAJA FINAL

nodo *bajaF(nodo *cima, int LogNod)
{
    int i = 0;
    nodo *aux, *borrar;
    if (cima != NULL)
    {
        aux = cima;
        if (LogNod != 1)
        {
            for (i = 0; i < LogNod - 2; i++)
            {
                aux = aux->sig;
            }
            borrar = aux->sig;
            free(borrar);
        }
        else
        {
            cima = bajaI(cima);
        }
    }
    return cima;
}

// BAJA POR POSICION

nodo *BajaPo(nodo *frente, int tam, int pos)
{
    nodo *aux;
    nodo *borrar;
    int i;
    if (pos > tam || pos < 1)
    {
        printf("ERROR");
    }
    else
    {
        if (frente != NULL)
        {
            aux = frente;
            if (tam != 1)
            {
                for (i = 0; i < (pos - 1); i++)
                {
                    aux = aux->sig;
                }
                borrar = aux->sig;
                aux->sig = borrar->sig;
                free(borrar);
            }
            else
                frente = bajaI(frente);
        }
    }
    return frente;
}

// BAJA POR DATO

nodo *BajaDato(nodo *frente, int dato_lista)
{

    nodo *actual;
    nodo *anterior;
    nodo *ultimo;
    ultimo = NULL;
    int encontrado;

    actual = frente;

    if (frente != NULL)
    {

        while (actual != NULL && encontrado != 1)
        {

            if (actual->dato == dato_lista)
            {
                if (actual == frente)
                {
                    frente = frente->sig;
                }
                else if (actual == ultimo)
                {
                    anterior->sig = NULL;
                    ultimo = anterior;
                }
                else
                {
                    anterior->sig = actual->sig;
                }
                printf("E L I M I N A N D O\n");
                encontrado = 1;
            }
            anterior = actual;
            actual = actual->sig;
        }
        if (encontrado == 0)
        {
            printf("La lista no contiene ese dato\n");
        }
        else
        {
            free(anterior);
        }
    }
    else
    {
        printf("La lista est� vac�a\n");
    }
    return frente;
}

// MODIFICAR DATS

void modificardato(nodo *Lista)
{

    int dato;
    int nuevo;
    int pos, i;

    printf("Ingrese el dato que desea cambiar: \n");
    scanf("%d", &dato);

    pos = Buscar(Lista, dato);

    if (pos == 0)
        printf("\nDato no encontrado\n");
    else
    {

        for (i = 1; i < pos; i++)
            Lista = Lista->sig;

        printf("\nIngrese el nuevo dato= \n");
        scanf("%d", &nuevo);

        Lista->dato = nuevo;

        printf("\nSe ha cambiado correctamente");
    }
}

// BUSCAR

int Buscar(nodo *frente, int dato)
{

    int posicion = 0;

    while (frente != NULL)
    {

        posicion++;
        if (frente->dato == dato)
            break;

        frente = frente->sig;
    }

    if (frente == NULL)
        posicion = 0;

    return posicion;
}

// MOSTRAR

void mostrar(nodo *cima)
{
    int i = 0;
    if (cima == NULL)
        printf("la Fila esta vacia");
    else
    {
        while (cima != NULL)
        {
            printf("elemento [%d]: %i\n", i, cima->dato);
            cima = cima->sig;
            i++;
        }
    }
}

// MOSTRAR
int contar(nodo *cima)
{
    int x = 0;
    if (cima == NULL)
    {
        printf("la Fila esta vacia");
        return x;
    }
    else
    {
        while (cima != NULL)
        {
            x++;
            cima = cima->sig;
        }
        return x;
    }
}

int main()
{
    nodo *admin = NULL;
    int menu = 0, altas = 0, bajas = 0, modificar = 0;
    int dato, posicion, largo;
    char volver = 's';

    while (volver == 's')
    {
        system("cls");
        printf("\n\t      .: BIENVENIDO, INGRESA LOS DATOS QUE DESEES GUARDAR :. \n\n");
        printf("  1) ALTAS DE DATOS\n\n");
        printf("  2) BAJAS DE DATOS \n\n");
        printf("  3) MOSTRAR \n\n");
        printf("  4) MODIFCAR DATOS \n");
        scanf("%i", &menu);
        switch (menu)
        {
        case 1:
        {
            system("CLS");

            printf("\n\t\n\n        .: LISTA:. \n\n\n");

            mostrar(admin);

            printf("\n\t\n\n\n\n        .: ALTAS :. \n\n\n");
            printf("    1)   INICIO \n\n");
            printf("    2)   FINAL  \n\n\n");
            printf("    3)   POSICION  \n\n");
            printf("    4)   DATO \n\n");
            scanf("%d", &altas);
            switch (altas)
            {
            case 1:
                system("cls");
                printf("   \n\n INGRESE EL DATO :    \n\n");
                scanf("%d", &dato);
                admin = altaI(dato, admin);
                break;
            case 2:
                system("cls");
                printf("   \n\n INGRESE EL DATO :    \n\n");
                scanf("%d", &dato);
                admin = altaF(dato, admin);
                break;
            case 3:
                system("cls");
                mostrar(admin);
                printf("   \n\n INGRESE POSICION DE ELEMENTO  :    \n\n");
                scanf("%d", &posicion);
                system("pause");
                printf("   \n\n INGRESE EL DATO :    \n\n");
                scanf("%d", &dato);
                admin = altaPos(admin, dato, posicion);
                break;
            case 4:
                system("cls");
                mostrar(admin);
                printf("   \n\n DIGITE EL DATO DE LA LISTA   :    \n\n");
                scanf("%d", &posicion);
                printf("   \n\n INGRESE EL DATO PARA SU INSERCION:    \n\n");
                scanf("%d", &dato);
                admin = altaD(admin, dato, posicion);
                break;
            }
        }
        break;
        case 2:
            system("CLS");

            printf("\n\t\n\n        .: LISTA:. \n\n\n");

            mostrar(admin);
            printf("\n\t\n\n        .: BAJAS :. \n\n\n");
            printf("    1)   INICIO \n\n");
            printf("    2)   FINAL  \n\n\n");
            printf("    3)   POSICION  \n\n");
            printf("    4)   DATO \n\n");

            scanf("%d", &bajas);
            switch (bajas)
            {
            case 1:
                system("cls");
                admin = bajaI(admin);
                break;
            case 2:
                system("cls");
                largo = contar(admin);
                admin = bajaF(admin, largo);
                break;
            case 3:
                system("cls");
                system("CLS");

                printf("\n\t\n\n        .: LISTA:. \n\n\n");
                mostrar(admin);
                printf("   \n\n INGRESE POSICION DE ELEMENTO  :    \n\n");
                scanf("%d", &posicion);
                largo = contar(admin);
                admin = BajaPo(admin, largo, posicion);
                break;
            case 4:

                system("CLS");

                printf("\n\t\n\n        .: LISTA:. \n\n\n");
                mostrar(admin);
                printf("   \n\n INGRESE DATO DEL ELEMENTO DE LA LISTA   :    \n\n");
                scanf("%d", &posicion);
                admin = BajaDato(admin, posicion);
                break;
            }

            break;
        case 3:
            mostrar(admin);
            system("pause");
            system("cls");
            break;
        case 4:
            modificardato(admin);

            break;
        }
    }

    system("pause");
    return 0;
}
