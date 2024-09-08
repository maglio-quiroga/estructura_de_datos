#include<stdio.h>
#include<stdlib.h>

typedef struct nodoPila
{
    int data;
    struct nodoPila* sig;
}nodoPila;

typedef struct Pila
{
    int longitud;
    nodoPila* tope;
    
}Pila;

nodoPila* crearnodo(int dato);
void destruirnodo(nodoPila* nodo);
Pila* crearpila();
void insertar(Pila* pila, int dato_nuevo);
void eliminar(Pila* pila);
void mostrarPila1(Pila* pila);
int len(Pila* pila);
void destruirPila(Pila* pila);

nodoPila* crearnodo(int dato){
    nodoPila* nuevoNodo = (nodoPila*)malloc(sizeof(nodoPila));
    if (nuevoNodo == NULL) {
        printf("Error al pedir espacio en memoria\n");
        return NULL; 
    }
    nuevoNodo->sig = NULL; nuevoNodo->data = dato;
    return nuevoNodo;
}

void destruirnodo(nodoPila* nodo){
    if (nodo != NULL) {
        nodo->sig = NULL;
        free(nodo);
    }
}

Pila* crearpila(){
    Pila* pila = (Pila*)malloc(sizeof(Pila));
    pila->tope = NULL; pila->longitud = 0;
    return pila;
}

void insertar(Pila* pila, int dato_nuevo){
    nodoPila* nuevoNodo = crearnodo(dato_nuevo);
    nuevoNodo->sig = pila->tope; 
    pila->longitud ++;
    pila->tope = nuevoNodo;
}

void eliminar(Pila* pila){
    if (pila->tope != NULL){
        nodoPila* temp = pila->tope;
        pila->tope = pila->tope->sig;
        pila->longitud --;
        destruirnodo(temp);
    } else {
        printf("La pila esta vacia\n");
        return;
    }
}

void mostrarPila1 (Pila* pila){
    Pila* tempPila1 = crearpila();
    Pila* tempPila2 = crearpila();

    while(pila->tope != NULL) {
        printf("valor de la pila : %d\n", pila->tope->data);
        insertar(tempPila1 , pila->tope->data);
        eliminar(pila);
    }
    while(tempPila1->tope != NULL){
        insertar(tempPila2 , tempPila1->tope->data);
        eliminar(tempPila1);
    }
    while(tempPila2->tope != NULL){
        insertar(pila , tempPila2->tope->data);
        eliminar(tempPila2);
    }
    free(tempPila1) ; free(tempPila2) ;
}

int len(Pila* pila){
    return pila->longitud;
}

void destruirPila(Pila* pila){
    while(pila->tope != NULL){
        eliminar(pila);
    }
    free(pila);
}