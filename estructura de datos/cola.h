#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int dato;
    struct nodo* siguiente;
    
}nodo;

typedef struct cola
{
    nodo* primero;
    nodo* ultimo;
}cola;

nodo* crearnodo(int dato);
void destruirnodo(nodo* nodo);
cola* crearcola();
void eliminarcola(cola* cola);
void insertar(cola* cola,int dato_nuevo);
void eliminar(cola* cola);
int primero(cola* cola);
int ultimo(cola* cola);
void mostrarcola(cola* cola);

nodo* crearnodo(int dato)
{
    nodo* nodo_nuevo = (nodo *)malloc(sizeof(nodo));
    nodo_nuevo->dato = dato;
    nodo_nuevo->siguiente = NULL;
    return nodo_nuevo;
}

void destruirnodo(nodo* nodo)
{
    nodo->siguiente = NULL;
    free(nodo);
}

cola* crearcola()
{
    cola* cola_nueva = (cola* )malloc(sizeof(cola));
    cola_nueva->primero = cola_nueva->ultimo = NULL;
    return cola_nueva;
}

void insertar(cola* cola,int dato_nuevo)
{
    nodo* nodo_nuevo = crearnodo(dato_nuevo);
    if(cola->primero == NULL)
    {
        cola->primero = cola->ultimo = nodo_nuevo;
    }
    else
    {
        cola->ultimo->siguiente = nodo_nuevo;
        cola->ultimo = nodo_nuevo;
    }
}

int primero(cola* cola)
{
    if(cola->primero != NULL)
    {
        return cola->primero->dato;
    }
}
int ultimo(cola* cola)
{
    if(cola->ultimo != NULL)
    {
        return cola->ultimo->dato;
    }
}

void eliminar(cola* cola)
{
    if(cola->primero != NULL)
    {
        nodo* objetivo = cola->primero;
        cola->primero = cola->primero->siguiente;
        destruirnodo(objetivo);
        if(cola->primero == NULL)
            cola->ultimo = NULL;
    }
}

void eliminarcola(cola* cola)
{
    while(cola->primero != NULL)
    {
        eliminar(cola);
    }
    free(cola);
}

void mostrarcola(cola* cola)
{
    nodo* iterador = cola->primero;
    int i=0;
    printf("LOS DATOS DE LA COLA SON LOS SIGUIENTES:\n");
    for(; iterador!=NULL ;iterador = iterador->siguiente)
    {
        printf("%d\n", iterador->dato);
        i++;
    }
    printf("LA LONGITUD DE LA COLA ES: %d\n",i);
    free(iterador);
}