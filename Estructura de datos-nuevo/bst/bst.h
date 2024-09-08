#include<stdio.h>
#include<stdlib.h>

typedef struct nodo
{
    int dato;
    struct nodo* izquierda;
    struct nodo* derecha;
    struct nodo* padre;
}nodo;

nodo* crearnodo(int dato_nuevo, nodo* padre);
void destruirnodo(nodo* objetivo);
void insertar_subarbol(nodo** arbol, int dato_nuevo, nodo* padre);
void insertar(nodo** arbol , int dato_nuevo);
int existe_nodo(nodo* arbol, int objetivo);
void preorden(nodo* arbol);
void inorden(nodo* arbol);
void postorden(nodo* arbol);
nodo* obtener_nodo(nodo* arbol , int objetivo);
void remplazar_nodos(nodo* arbol , nodo* remplazo);
void eliminar(nodo* arbol, int objetivo);
nodo* minimo_nodo(nodo* arbol);
void eliminar_nodo(nodo* arbol);

nodo* crearnodo(int dato_nuevo, nodo* padre)
{
    nodo* nuevo_nodo = (nodo* )malloc(sizeof(nodo));
    nuevo_nodo->dato = dato_nuevo;
    nuevo_nodo->izquierda = nuevo_nodo->derecha = NULL;
    nuevo_nodo->padre = padre;
    return nuevo_nodo;
}

void destruirnodo(nodo* objetivo)
{
    objetivo->izquierda = objetivo->derecha = NULL;
    free(objetivo);
}

void insertar_subarbol(nodo** arbol, int dato_nuevo, nodo* padre)
{
    if(*arbol == NULL)
    {
        *arbol = crearnodo(dato_nuevo, padre);
    }
    else
    {
        int raiz = (*arbol)->dato;
        if(dato_nuevo < raiz)
        {
            insertar_subarbol(&(*arbol)->izquierda,dato_nuevo,*arbol);
        }
        else
        {
            insertar_subarbol(&(*arbol)->derecha,dato_nuevo,*arbol);
        }
    }
}

void insertar(nodo** arbol , int dato_nuevo)
{
    insertar_subarbol(arbol, dato_nuevo , NULL);
}

int existe_nodo(nodo* arbol, int objetivo)
{
    if(arbol == NULL) 
        return 0;
    else if(arbol->dato == objetivo)
        return 1;
    else if(objetivo < arbol->dato)
        return existe_nodo(arbol->izquierda , objetivo);
    else
        return existe_nodo(arbol->derecha , objetivo);
}

void preorden(nodo* arbol)
{
    printf("VALORES DEL ARBOL EN RECORRIDO PREORDEN\n");
    if(arbol == NULL)
    {
        printf("\n");
    }
    else
    {
        printf("- %d -",arbol->dato);
        preorden(arbol->izquierda);
        preorden(arbol->derecha);
    }
}

void inorden(nodo* arbol)
{
    printf("VALORES DEL ARBOL EN RECORRIDO INORDEN\n");
    if(arbol == NULL)
    {
        printf("\n");
    }
    else
    {
        inorden(arbol->izquierda);
        printf("- %d -",arbol->dato);
        inorden(arbol->derecha);
    }
}

void postorden(nodo* arbol)
{
    printf("VALORES DEL ARBOL EN RECORRIDO POSTORDEN\n");
    if(arbol == NULL)
    {
        printf("\n");
    }
    else
    {
        postorden(arbol->izquierda);
        postorden(arbol->derecha);
        printf("- %d -",arbol->dato);
    }
}

nodo* obtener_nodo(nodo* arbol , int objetivo)
{
    if(arbol == NULL)
        return NULL;
    else if (arbol->dato == objetivo)
        return arbol;
    else if(objetivo < arbol->dato)
        return obtener_nodo(arbol->izquierda , objetivo);
    else
        return obtener_nodo(arbol->derecha , objetivo);
}

void remplazar_nodos(nodo* arbol , nodo* remplazo)
{
    if(arbol->padre != NULL)
    {
        if(arbol->dato == arbol->padre->izquierda->dato)
            arbol->padre->izquierda = remplazo;
        else if(arbol->dato == arbol->padre->derecha->dato)
            arbol->padre->derecha = remplazo;
    }
    if(remplazo != NULL)
    {
        remplazo->padre = arbol->padre;
    }
}

nodo* minimo_nodo(nodo* arbol)
{
    if(arbol == NULL) return NULL;
    else if(arbol->izquierda == NULL) return arbol;
    else return minimo_nodo(arbol->izquierda);
}

void eliminar_nodo(nodo* arbol)
{
    if(arbol->izquierda!= NULL && arbol->derecha!= NULL)
        {
            nodo* minimo = minimo_nodo(arbol->derecha);
            arbol->dato = minimo->dato;
            eliminar_nodo(minimo);
        }
        else if(arbol->izquierda!= NULL)
        {
            remplazar_nodos(arbol , arbol->izquierda);
            destruirnodo(arbol);
        }
        else if(arbol->derecha!= NULL)
        {
            remplazar_nodos(arbol , arbol->derecha);
            destruirnodo(arbol);
        }
        else
        {
            remplazar_nodos(arbol , NULL);
            destruirnodo(arbol);
        }
}

void eliminar(nodo* arbol, int objetivo)
{
    if(arbol ==  NULL)
        return;
    else if(objetivo < arbol->dato)
        eliminar(arbol->izquierda , objetivo);
    else if(objetivo > arbol->dato)
        eliminar(arbol->derecha , objetivo);
    else
    {
        eliminar_nodo(arbol);
    }
}
