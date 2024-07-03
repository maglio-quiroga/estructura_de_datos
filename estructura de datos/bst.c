#include"bst.h"

int main()
{
    nodo* arbol = NULL;
    insertar(&arbol , 6);
    insertar(&arbol , 5);
    insertar(&arbol , 4);
    insertar(&arbol , 7);
    int a = 10;
    if(existe_nodo(arbol , a))
        printf("SI EXISTE ESTE ELEMENTO %d",a);
    else
        printf("NO EXISTE ESTE ELEMENTO %d",a);
    return 1;
}