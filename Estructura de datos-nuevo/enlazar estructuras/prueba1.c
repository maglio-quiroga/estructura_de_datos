#include"prueba1.h"

int main()
{
    reinas* pila = crearpila_reinas();
    
    
    insertar_reina(pila,'Reina1' , 1, 0);
    insertar_hormiga(pila->tope->lista_hormigas, 1, 1);
    insertar_hormiga(pila->tope->lista_hormigas, 2, 1);

    insertar_reina(pila, 'Reina2', 2, 0);
    insertar_hormiga(pila->tope->lista_hormigas, 3, 1);
    insertar_hormiga(pila->tope->lista_hormigas, 4, 1);
    insertar_hormiga(pila->tope->lista_hormigas, 5, 1);
    insertar_hormiga(pila->tope->lista_hormigas, 6, 1);

    determinar_fero(pila);
    mostrar_reinas(pila);
    return 1;
}