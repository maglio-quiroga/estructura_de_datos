#include"grafo_nd.h"

int main()
{
    grafo* mi_grafo = crear_grafo();

    agregar_vertice(mi_grafo, 1);
    agregar_vertice(mi_grafo, 2);
    agregar_vertice(mi_grafo, 3);

    generar_adyacencia(mi_grafo, 1, 2);
    generar_adyacencia(mi_grafo, 1, 3);
    generar_adyacencia(mi_grafo, 2, 3);

    imprimir_grafo(mi_grafo);

    return 1;
}