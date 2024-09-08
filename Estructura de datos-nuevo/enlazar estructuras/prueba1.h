#include<stdio.h>
#include<stdlib.h>

typedef struct nodo_hormigas
{
    int id,estado;
    struct nodo_hormigas* siguiente;
    struct nodo_hormigas* anterior;
}nodo_hormigas;

typedef struct hormigas
{
    struct nodo_hormigas* cabeza;
}hormigas;


typedef struct nodo_reinas{
    char nombre[20];
    int id, feromonas;
    hormigas* lista_hormigas;
    struct nodo_reinas* siguiente;
}nodo_reinas;

typedef struct reinas
{
    nodo_reinas* tope;
}reinas;

/*-----------FUNCIONES PARA LAS HORMIGAS-------------*/
nodo_hormigas* crearnodo1(int id, int estado);
void destruirnodo1(nodo_hormigas* nodo);
hormigas* crearlista_hormigas();
void insertar_hormiga(hormigas* lista, int id_nuevo, int estado_nuevo);
void eliminar_hormiga(hormigas* lista);

nodo_hormigas* crearnodo1(int id, int estado)
{
    nodo_hormigas* nuevo_nodo = (nodo_hormigas* )malloc(sizeof(nodo_hormigas));
    nuevo_nodo->id = id;
    nuevo_nodo->estado = estado;
    nuevo_nodo->anterior = nuevo_nodo->siguiente = NULL;
    return nuevo_nodo;
}

void destruirnodo1(nodo_hormigas* nodo)
{
    nodo->anterior = nodo->siguiente = NULL;
    free(nodo);
}

hormigas* crearlista_hormigas()
{
    hormigas* lista = (hormigas* )malloc(sizeof(hormigas));
    lista->cabeza = NULL;
    return lista;
}

void insertar_hormiga(hormigas* lista, int id_nuevo, int estado_nuevo)
{
    nodo_hormigas* nuevo_nodo = crearnodo1(id_nuevo , estado_nuevo);
    nodo_hormigas* iterador = lista->cabeza;
    for( ; iterador != NULL; iterador = iterador->siguiente)
    {
       if (iterador->id == id_nuevo) return;
    }
    free(iterador);
    if(lista->cabeza == NULL) lista->cabeza = nuevo_nodo;
    else
    {
        nodo_hormigas* actual = lista->cabeza;
        while (actual->siguiente != NULL)
        {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo_nodo;
        nuevo_nodo->anterior = actual;
    }
}

void eliminar_hormiga(hormigas* lista)
{
    nodo_hormigas* actual = lista->cabeza;
    while (actual != NULL)
    {
        nodo_hormigas* siguiente = actual->siguiente;
        if (actual->estado == 0)
         {
            if (actual->anterior == NULL && actual->siguiente == NULL)
            {
                lista->cabeza = NULL;
            }
            else if (actual->anterior == NULL)
            {
                lista->cabeza = actual->siguiente;
                lista->cabeza->anterior = NULL;
            } 
            else if (actual->siguiente == NULL) 
            {
                actual->anterior->siguiente = NULL;
            }
            else 
            {
                actual->anterior->siguiente = actual->siguiente;
                actual->siguiente->anterior = actual->anterior;
            }
            destruirnodo1(actual);
        }
        actual = siguiente;
    }
}

/*-----------FUNCIONES PARA LAS REINAS-------------*/
nodo_reinas* crearnodo2(char nombre , int id , int fero);
void destruirnodo2(nodo_reinas* reina);
reinas* crearpila_reinas();
void insertar_reina(reinas* reina, char nombre , int id , int fero);
void mostrar_reinas(reinas* pila);
int calcular_fibonacci(int n);
void determinar_fero(reinas* pila);

nodo_reinas* crearnodo2(char nombre , int id , int fero)
{
    nodo_reinas* nuevo_nodo = (nodo_reinas* )malloc(sizeof(nodo_reinas));
    nuevo_nodo->feromonas = fero;
    nuevo_nodo->id = id;
    nuevo_nodo->siguiente = NULL;
    return nuevo_nodo;
}

void destruirnodo2(nodo_reinas* reina)
{
    reina->siguiente = NULL;
    free(reina);
}

reinas* crearpila_reinas()
{
    reinas* pila = (reinas* )malloc(sizeof(reinas));
    pila->tope = NULL;
    return pila;
}

void insertar_reina(reinas* reina, char nombre , int id , int fero)
{
    nodo_reinas* nuevo_nodo = crearnodo2(nombre , id , fero);
    nuevo_nodo->lista_hormigas = crearlista_hormigas();
    nuevo_nodo->siguiente = reina->tope;
    reina->tope = nuevo_nodo;
}

void mostrar_reinas(reinas* pila)
{
    nodo_reinas* iterador = pila->tope;
    while (iterador != NULL)
    {
        printf("Reina Nombre: %s, ID: %d, Feromonas: %d\n", iterador->nombre, iterador->id, iterador->feromonas);
        iterador = iterador->siguiente;
    }
}

int calcular_fibonacci(int n)
{
    if (n <= 1) 
        return n;
    return calcular_fibonacci(n-1) + calcular_fibonacci(n-2);
}

void determinar_fero(reinas* pila)
{
    nodo_reinas* iterador_reinas = pila->tope;
    while(iterador_reinas != NULL)
    {
        nodo_hormigas* iterador_hormigas = iterador_reinas->lista_hormigas->cabeza;
        int num_hormigas = 0;
        while (iterador_hormigas != NULL)
        {
            if (iterador_hormigas->estado != 0)
            {
                num_hormigas++;
            }
            iterador_hormigas = iterador_hormigas->siguiente;
        }
        int num_fero = calcular_fibonacci(num_hormigas);
        iterador_reinas->feromonas = num_fero;
        iterador_reinas = iterador_reinas->siguiente;
    }
}