#include<stdio.h>
#include<stdlib.h>

typedef struct nodo_lista
{
    int adyacencia;
    struct nodo_lista* siguiente;
}nodo_lista;

typedef struct lista{
    nodo_lista* cabeza;
}lista;

typedef struct vertice{
    int clave;
    lista* list_ady;
    struct vertice* siguiente;
}vertice;

typedef struct grafo{
    vertice* ultimo_vertice;
    int numero_vertices;
}grafo;

nodo_lista* crear_nodo_lista(int dato);
lista* crear_lista();
vertice* crear_vertice(int dato);
grafo* crear_grafo();
void agregar_vertice(grafo* graf , int dato_nuevo);
void generar_adyacencia(grafo* graf , int vertice_clave1 , int vertice_clave2);

nodo_lista* crear_nodo_lista(int dato)
{
    nodo_lista* nuevo_nodo = (nodo_lista*)malloc(sizeof(nodo_lista));
    nuevo_nodo->adyacencia = dato;
    nuevo_nodo->siguiente =  NULL;
    return nuevo_nodo;
}

lista* crear_lista()
{
    lista* lista_nueva = (lista* )malloc(sizeof(lista));
    lista_nueva->cabeza = NULL;
    return lista_nueva;
}

vertice* crear_vertice(int dato)
{
    vertice* nuevo_vertice = (vertice* )malloc(sizeof(vertice));
    nuevo_vertice->clave = dato;
    nuevo_vertice->list_ady = crear_lista();
    nuevo_vertice->siguiente = NULL;
    return nuevo_vertice;
}

grafo* crear_grafo()
{
    grafo* nuevo_grafo = (grafo* )malloc(sizeof(grafo));
    nuevo_grafo->numero_vertices = 0;
    nuevo_grafo->ultimo_vertice = NULL;
    return nuevo_grafo;
}

/*---------------------------------------------------------*/

void agregar_vertice(grafo* graf , int dato_nuevo)
{
    vertice* nuevo_vertice = crear_vertice(dato_nuevo);
    nuevo_vertice->siguiente = graf->ultimo_vertice;
    graf->ultimo_vertice = nuevo_vertice;
    graf->numero_vertices++;
}

void generar_adyacencia(grafo* graf , int vertice_clave1 , int vertice_clave2)
{
    vertice* v1 = NULL;
    vertice* v2 = NULL;
    vertice* iterador = graf->ultimo_vertice;

    while (iterador != NULL)
    {
        if(iterador->clave == vertice_clave1)
        {
            v1 = iterador;
        }
        if(iterador->clave == vertice_clave2)
        {
            v2 = iterador;
        }

        iterador = iterador->siguiente;
    }

    if (v1 != NULL  && v2 != NULL)
    {
        nodo_lista* nodo_v1 = crear_nodo_lista(vertice_clave2);   
        nodo_lista* nodo_v2 = crear_nodo_lista(vertice_clave1);

        nodo_v1->siguiente = v1->list_ady->cabeza;
        v1->list_ady->cabeza = nodo_v1;
        nodo_v2->siguiente = v2->list_ady->cabeza;
        v2->list_ady->cabeza = nodo_v2;
    }   
}

void imprimir_grafo(grafo* graf)
{
    vertice* iterador_vertice = graf->ultimo_vertice;
    while (iterador_vertice != NULL)
    {
        printf("Vertice %d: ", iterador_vertice->clave);
        nodo_lista* iterador_ady = iterador_vertice->list_ady->cabeza;
        while (iterador_ady != NULL)
        {
            printf("estos son sus vertices adyacentes: %d- ", iterador_ady->adyacencia);
            iterador_ady = iterador_ady->siguiente;
        }
        printf("\n");
        iterador_vertice = iterador_vertice->siguiente;
    }
}
