#include"bst.h"

int main()
{
    nodo* arbol = NULL;

    // Insertar algunos nodos en el árbol
    insertar(&arbol, 50);
    insertar(&arbol, 30);
    insertar(&arbol, 20);
    insertar(&arbol, 40);
    insertar(&arbol, 70);
    insertar(&arbol, 60);
    insertar(&arbol, 80);

    // Recorridos del árbol
    printf("Recorrido en preorden:\n");
    preorden(arbol);
    printf("\n");

    printf("Recorrido en inorden:\n");
    inorden(arbol);
    printf("\n");

    printf("Recorrido en postorden:\n");
    postorden(arbol);
    printf("\n");

    // Verificar si existen ciertos nodos
    int busqueda = 40;
    if (existe_nodo(arbol, busqueda))
        printf("El nodo con valor %d existe en el árbol.\n", busqueda);
    else
        printf("El nodo con valor %d NO existe en el árbol.\n", busqueda);

    busqueda = 90;
    if (existe_nodo(arbol, busqueda))
        printf("El nodo con valor %d existe en el árbol.\n", busqueda);
    else
        printf("El nodo con valor %d NO existe en el árbol.\n", busqueda);

    // Eliminar algunos nodos
    printf("\nEliminando el nodo con valor 20\n");
    eliminar(arbol, 20);

    printf("\nEliminando el nodo con valor 30\n");
    eliminar(arbol, 30);

    printf("\nEliminando el nodo con valor 50\n");
    eliminar(arbol, 50);

    // Recorridos del árbol después de eliminar nodos
    printf("\nRecorrido en preorden después de eliminar nodos:\n");
    preorden(arbol);
    printf("\n");

    printf("Recorrido en inorden después de eliminar nodos:\n");
    inorden(arbol);
    printf("\n");

    printf("Recorrido en postorden después de eliminar nodos:\n");
    postorden(arbol);
    printf("\n");

    return 1;
}