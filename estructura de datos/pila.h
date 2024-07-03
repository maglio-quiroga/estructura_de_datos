#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int dato;
    struct nodo* siguiente;
}nodo;

typedef struct pila {
    nodo* tope;
}pila;

nodo* crearnodo(int dato);
void destruirnodo(nodo* nodo);
void insertar(pila* pila, int dato_nuevo);
void eliminar(pila* pila);
int valor_tope(pila* pila);
pila* crearpila();
void eliminar_pila(pila* pila);
void mostrar_pila(pila* pila);

nodo* crearnodo(int dato) {
    nodo* nodo_nuevo = (nodo *)malloc(sizeof(nodo));
    nodo_nuevo->dato = dato;
    nodo_nuevo->siguiente = NULL;
    return nodo_nuevo;
}

void destruirnodo(nodo* nodo) {
    nodo->siguiente = NULL;
    nodo->dato = NULL;
    free(nodo);
}

void insertar(pila* pila, int dato_nuevo) {
    nodo* nodo_nuevo = crearnodo(dato_nuevo);
    nodo_nuevo->siguiente = pila->tope;
    pila->tope = nodo_nuevo;
}

void eliminar(pila* pila) {
    if (pila->tope != NULL) {
        nodo* objetivo = pila->tope;
        pila->tope = pila->tope->siguiente;
        destruirnodo(objetivo);
    }
}

int valor_tope(pila* pila) {
    if (pila->tope == NULL) {
        return -1; 
    } else {
        return pila->tope->dato;
    }
}

pila* crearpila() {
    pila* pila_nueva = (pila *)malloc(sizeof(pila));
    pila_nueva->tope = NULL;
    return pila_nueva;
}

void eliminar_pila(pila* pila) {
    while (pila->tope != NULL) {
        eliminar(pila);
    }
    free(pila);
}

void mostrar_pila(pila* pila)
{
    nodo* iterador = pila->tope;
    int i=0;
    printf("LOS DATOS DE LA PILA SON LOS SIGUIENTES:\n");
    for( ; iterador!=NULL ; iterador=iterador->siguiente)
    {
         printf("%d\n", iterador->dato);
         i++;
    }
    printf("LA LONGITUD DE LA PILA ES: %d\n",i);  
    free(iterador);
}