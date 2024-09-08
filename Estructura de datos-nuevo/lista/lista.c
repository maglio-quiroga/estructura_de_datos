#include"lista.h"

int main(){

    Lista* nueva_lista = crearlista();
    insertar_asc(nueva_lista,3);
    insertar_asc(nueva_lista,1);
    insertar_asc(nueva_lista,5);
    insertar_asc(nueva_lista,4);
    insertar_asc(nueva_lista,8);
    mostrarLista(nueva_lista);

    int l = len(nueva_lista);
    printf("longitud: %d\n",l);
    eliminar(nueva_lista , 5);
    l = len(nueva_lista);
    printf("longitud: %d\n",l);

    mostrarLista(nueva_lista);

    nodoActual(nueva_lista);
    destruirLista(nueva_lista);

    Lista* lista = crearlista();
    insertar_desc(lista,3);
    insertar_desc(lista,1);
    insertar_desc(lista,5);
    insertar_desc(lista,4);
    insertar_desc(lista,8);
    mostrarLista(lista);
    destruirLista(lista);

    return 1;
}