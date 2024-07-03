#include"lista.h"

int main()
{
    lista* mi_lista = crearlista();
    insertar(mi_lista, 4);
    insertar(mi_lista, 1);
    insertar(mi_lista, 3);
    insertar(mi_lista, 2);
    mostrarlista(mi_lista);
    eliminar(mi_lista,1);
    mostrarlista(mi_lista);
    eliminar2(mi_lista);
    mostrarlista(mi_lista);
    eliminarlista(mi_lista);

    lista* nueva_lista = crearlista();
    insertar_asc(nueva_lista,3);
    insertar_asc(nueva_lista,1);
    insertar_asc(nueva_lista,5);
    insertar_asc(nueva_lista,4);
    insertar_asc(nueva_lista,8);
    mostrarlista(nueva_lista);
    eliminarlista(nueva_lista);

    lista* otra_lista = crearlista();
    insertar_desc(otra_lista,1);
    insertar_desc(otra_lista,6);
    insertar_desc(otra_lista,5);
    insertar_desc(otra_lista,9);
    insertar_desc(otra_lista,3);
    mostrarlista(otra_lista);
    eliminarlista(otra_lista);

    return 1;
}