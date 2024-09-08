#include<stdio.h>
#include<stdlib.h>

typedef struct nodoLista{
    int data;
    struct nodoLista* ant;
    struct nodoLista* sig;
    
}nodoLista;

typedef struct Lista{
    int longitud;
    nodoLista* cabeza;
}Lista;

nodoLista* crearnodo(int dato);
void destruirnodo(nodoLista* nodo);
Lista* crearlista();
void insertar_asc(Lista* lista, int dato);
void insertar_desc(Lista* lista, int dato);
void eliminar(Lista* lista , int objetivo);
void mostrarLista(Lista* lista);
int len(Lista* lista);
void nodoActual(Lista* lista);
void destruirLista(Lista* lista);

nodoLista* crearnodo(int dato){
    nodoLista* nuevoNodo = (nodoLista*)malloc(sizeof(nodoLista));
    nuevoNodo->ant = nuevoNodo->sig = NULL;
    nuevoNodo->data = dato;
    return nuevoNodo;
}

void destruirnodo(nodoLista* nodo){
    nodo->ant = nodo->sig = NULL;
    free(nodo);
}

Lista* crearlista(){
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->cabeza = NULL ; lista->longitud = 0 ;
    return lista;
}

void mostrarLista(Lista* lista){
    nodoLista* iterador = lista->cabeza;
    for( ; iterador != NULL ; iterador = iterador->sig){
        printf("valor de la lista: %d\n", iterador->data);
    }
}

void insertar_asc(Lista* lista, int dato)
{
    nodoLista* nodo_nuevo = crearnodo(dato);
    if (lista->cabeza == NULL) // La lista está vacía
    {
        lista->cabeza = nodo_nuevo;
        lista->longitud ++;
    }
    else
    {
        nodoLista* actual = lista->cabeza;
        nodoLista* previo = NULL;

        // Encuentra la posición correcta para insertar el nuevo nodo
        while (actual != NULL && actual->data < dato)
        {
            previo = actual;
            actual = actual->sig;
        }

        if (previo == NULL) // Insertar al inicio
        {
            nodo_nuevo->sig = lista->cabeza;
            lista->cabeza->ant = nodo_nuevo;
            lista->cabeza = nodo_nuevo;
            lista->longitud ++;
        }
        else if (actual == NULL) // Insertar al final
        {
            previo->sig = nodo_nuevo;
            nodo_nuevo->ant = previo;
            lista->longitud ++;
        }
        else // Insertar entre dos nodos
        {
            previo->sig = nodo_nuevo;
            nodo_nuevo->ant = previo;
            nodo_nuevo->sig = actual;
            actual->ant = nodo_nuevo;
            lista->longitud ++;
        }
    }
}

void insertar_desc(Lista* lista, int dato)
{
    nodoLista* nodo_nuevo = crearnodo(dato);
    if (lista->cabeza == NULL) // La lista está vacía
    {
        lista->cabeza = nodo_nuevo;
        lista->longitud ++;
    }
    else
    {
        nodoLista* actual = lista->cabeza;
        nodoLista* previo = NULL;

        // Encuentra la posición correcta para insertar el nuevo nodo
        while (actual != NULL && actual->data > dato)
        {
            previo = actual;
            actual = actual->sig;
        }

        if (previo == NULL) // Insertar al inicio
        {
            nodo_nuevo->sig = lista->cabeza;
            lista->cabeza->ant = nodo_nuevo;
            lista->cabeza = nodo_nuevo;
            lista->longitud ++;
        }
        else if (actual == NULL) // Insertar al final
        {
            previo->sig = nodo_nuevo;
            nodo_nuevo->ant = previo;
            lista->longitud ++;
        }
        else // Insertar entre dos nodos
        {
            previo->sig = nodo_nuevo;
            nodo_nuevo->ant = previo;
            nodo_nuevo->sig = actual;
            actual->ant = nodo_nuevo;
            lista->longitud ++;
        }
    }
}

void eliminar(Lista* lista , int objetivo){
    if(lista->cabeza == NULL){
        printf("La lista esta vacia \n");
    }else{
         nodoLista* actual = lista->cabeza;
    
    while (actual != NULL && actual->data != objetivo) {
        actual = actual->sig;
    }
    //caso1 (un solo elemento)
    if(actual->ant == NULL && actual->sig == NULL)
    {
        lista->cabeza = NULL;
    }
    //caso2 (extremo izquierdo el nodo)
    if(actual->ant == NULL && actual->sig != NULL)
    {
        lista->cabeza = actual->sig;
        lista->cabeza->ant = NULL;
    }
    //caso3 (extremo derecho el nodo)
    if(actual->ant != NULL && actual->sig == NULL)
    {
        lista->cabeza = actual->ant;
        lista->cabeza->sig = NULL;
    }
    //caso4 (entre dos nodos)
    if(actual->ant != NULL && actual->sig != NULL)
    {
        actual->ant->sig = actual->sig;
        actual->sig->ant = actual->ant;
    }
    //caso5
    if(actual == NULL)
    {
        return;
    }
    destruirnodo(actual);
    lista->longitud --;
    }
    
}

int len(Lista* lista){
    return lista->longitud;
}

void nodoActual(Lista* lista){
    if(lista->cabeza != NULL) printf("valor del nodo actual: %d\n", lista->cabeza->data);
}

void destruirLista(Lista* lista){
    nodoLista* actual = lista->cabeza;
    while (actual != NULL)
    {
        nodoLista* siguiente = actual->sig;  
        destruirnodo(actual);                
        actual = siguiente; 
    }
    free(lista);
}