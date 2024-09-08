#include<stdio.h>
#include<stdlib.h>

typedef struct nodoCola
{
    int data;
    struct nodoCola* sig;
}nodoCola;

typedef struct Cola
{
    int longitud;
    nodoCola* i;
    nodoCola* f;

}Cola;

nodoCola* crearnodo(int dato);
void destruirnodo(nodoCola* nodo);
Cola* crearcola();
void insertar(Cola* cola, int dato_nuevo);
void eliminar(Cola* cola);
void mostrarCola1(Cola* cola);
int len(Cola* cola);
void destruirCola(Cola* cola);
int primero(Cola* cola);
int ultimo(Cola* cola);

nodoCola* crearnodo(int dato){
    nodoCola* nuevoNodo = (nodoCola*)malloc(sizeof(nodoCola));
    if (nuevoNodo == NULL) {
        printf("Error al pedir espacio en memoria\n");
        return NULL; 
    }
    nuevoNodo->data = dato;
    nuevoNodo->sig = NULL;
    return nuevoNodo;
}

void destruirnodo(nodoCola* nodo){
    if (nodo != NULL) {
        nodo->sig = NULL;
        free(nodo);
    }
}

Cola* crearcola(){
    Cola* cola = (Cola*)malloc(sizeof(Cola));
    cola->longitud = 0;
    cola->i = cola->f = NULL;
    return cola;
}

void insertar(Cola* cola, int dato_nuevo){
    nodoCola* nodo = crearnodo(dato_nuevo);
    if(cola->i == NULL){
        cola->i = cola->f = nodo;
        cola->longitud ++;

    }else {
        cola->f->sig = nodo;
        cola->f = nodo;
        cola->longitud ++;
    }
}

void eliminar(Cola* cola){
    if (cola->i != NULL) {
        nodoCola* temp = cola->i;
        cola->i = cola->i->sig;
        cola->longitud --;
        destruirnodo(temp);
        if(cola->i == NULL) cola->f = NULL;

    }else {
        printf("La cola esta vacia\n");
        return;
    }
}

void mostrarCola1(Cola* cola){
    Cola* tempCola = crearcola();
    while (cola->i != NULL)
    {
        printf("valor de la cola : %d\n", cola->i->data);
        insertar(tempCola , cola->i->data);
        eliminar(cola);
    }
    while(tempCola->i != NULL){
        insertar(cola , tempCola->i->data);
        eliminar(tempCola);
    }
    free(tempCola);
}

int len(Cola* cola){
    return cola->longitud;
}

void destruirCola(Cola* cola){
    while (cola->i != NULL){
        eliminar(cola);
    }
    free(cola);
}

int primero(Cola* cola){
     if (cola->i != NULL) return cola->i->data;
}

int ultimo(Cola* cola){
    if (cola->f != NULL) return cola->f->data;
}