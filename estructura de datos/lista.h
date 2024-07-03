#include<stdio.h>
#include<stdlib.h>

typedef struct nodo
{
    int dato;
    struct nodo* siguiente;
    struct nodo* anterior;
}nodo;

typedef struct lista
{
    nodo* cabeza;
}lista;

nodo* crearnodo(int valor);
void destruirnodo(nodo* nodo);
lista* crearlista();
void insertar(lista* lista, int dato_nuevo);
void eliminar(lista* lista, int objetivo);
void mostrarlista(lista* lista);
void eliminar2(lista* lista);
void insertar_asc(lista* lista, int dato_nuevo);
void insertar_desc(lista* lista, int dato_nuevo);

nodo* crearnodo(int valor)
{
    nodo* nuevo_nodo = (nodo* )malloc(sizeof(nodo));
    nuevo_nodo->dato = valor;
    nuevo_nodo->siguiente = NULL;
    nuevo_nodo->anterior = NULL;
    return  nuevo_nodo;
}

void destruirnodo(nodo* nodo)
{
    //nodo->dato = NULL;
    nodo->anterior = nodo->siguiente = NULL;
    free(nodo);
}

lista* crearlista()
{
    lista* lista_nueva = (lista* )malloc(sizeof(lista));
    lista_nueva->cabeza = NULL;
    return lista_nueva;
}

void insertar(lista* lista, int dato_nuevo)
{
    nodo* nodo_nuevo = crearnodo(dato_nuevo);
    if(lista->cabeza == NULL)
    {
        lista->cabeza = nodo_nuevo;
    }
    else
    {
        nodo* actual = lista->cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nodo_nuevo;
        nodo_nuevo->anterior = actual;
    }
}

void eliminar(lista* lista, int objetivo)
{
    nodo* actual = lista->cabeza;
    
    while (actual != NULL && actual->dato != objetivo) {
        actual = actual->siguiente;
    }
    //caso1
    if(actual->anterior == NULL && actual->siguiente == NULL)
    {
        lista->cabeza = NULL;
    }
    //caso2
    if(actual->anterior == NULL && actual->siguiente != NULL)
    {
        lista->cabeza = actual->siguiente;
        lista->cabeza->anterior = NULL;
    }
    //caso3
    if(actual->anterior != NULL && actual->siguiente == NULL)
    {
        lista->cabeza = actual->anterior;
        lista->cabeza->siguiente = NULL;
    }
    //caso4
    if(actual->anterior != NULL && actual->siguiente != NULL)
    {
        actual->anterior->siguiente = actual->siguiente;
        actual->siguiente->anterior = actual->anterior;
    }
    //caso5
    if(actual == NULL)
    {
        return;
    }
    destruirnodo(actual);
}

void mostrarlista(lista* lista)
{
    nodo* iterador = lista->cabeza;
    int i=0;
    printf("LOS DATOS DE LA LISTA SON LOS SIGUIENTES:\n");
    for(; iterador!=NULL ;iterador = iterador->siguiente)
    {
        printf("%d\n", iterador->dato);
        i++;
    }
    printf("LA LONGITUD DE LA LISTA ES: %d\n",i);
    free(iterador);
}

void eliminar2(lista* lista)
{
    if(lista->cabeza != NULL)
    {
        nodo* objetivo = lista->cabeza;
        lista->cabeza = lista->cabeza->siguiente;
        if (lista->cabeza != NULL)
        {
            lista->cabeza->anterior = NULL;
        }
        destruirnodo(objetivo);
    }
}

void eliminarlista(lista* lista)
{
    while (lista->cabeza != NULL)
    {
        nodo* objetivo = lista->cabeza;
        lista->cabeza = lista->cabeza->siguiente;
        if (lista->cabeza != NULL)
        {
            lista->cabeza->anterior = NULL;
        }
        destruirnodo(objetivo);
    }
}

void insertar_asc(lista* lista, int dato_nuevo)
{
    nodo* nodo_nuevo = crearnodo(dato_nuevo);
    if (lista->cabeza == NULL) // La lista está vacía
    {
        lista->cabeza = nodo_nuevo;
    }
    else
    {
        nodo* actual = lista->cabeza;
        nodo* previo = NULL;

        // Encuentra la posición correcta para insertar el nuevo nodo
        while (actual != NULL && actual->dato < dato_nuevo)
        {
            previo = actual;
            actual = actual->siguiente;
        }

        if (previo == NULL) // Insertar al inicio
        {
            nodo_nuevo->siguiente = lista->cabeza;
            lista->cabeza->anterior = nodo_nuevo;
            lista->cabeza = nodo_nuevo;
        }
        else if (actual == NULL) // Insertar al final
        {
            previo->siguiente = nodo_nuevo;
            nodo_nuevo->anterior = previo;
        }
        else // Insertar entre dos nodos
        {
            previo->siguiente = nodo_nuevo;
            nodo_nuevo->anterior = previo;
            nodo_nuevo->siguiente = actual;
            actual->anterior = nodo_nuevo;
        }
    }
}

void insertar_desc(lista* lista, int dato_nuevo)
{
    nodo* nodo_nuevo = crearnodo(dato_nuevo);
    if (lista->cabeza == NULL) // La lista está vacía
    {
        lista->cabeza = nodo_nuevo;
    }
    else
    {
        nodo* actual = lista->cabeza;
        nodo* previo = NULL;

        // Encuentra la posición correcta para insertar el nuevo nodo
        while (actual != NULL && actual->dato > dato_nuevo)
        {
            previo = actual;
            actual = actual->siguiente;
        }

        if (previo == NULL) // Insertar al inicio
        {
            nodo_nuevo->siguiente = lista->cabeza;
            lista->cabeza->anterior = nodo_nuevo;
            lista->cabeza = nodo_nuevo;
        }
        else if (actual == NULL) // Insertar al final
        {
            previo->siguiente = nodo_nuevo;
            nodo_nuevo->anterior = previo;
        }
        else // Insertar entre dos nodos
        {
            previo->siguiente = nodo_nuevo;
            nodo_nuevo->anterior = previo;
            nodo_nuevo->siguiente = actual;
            actual->anterior = nodo_nuevo;
        }
    }
}
