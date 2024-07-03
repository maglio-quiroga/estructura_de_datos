#include"pila.h"

int main()
{
    pila* pila = crearpila();
    insertar(pila,1);
    insertar(pila,2);
    insertar(pila,3);
    insertar(pila,4);
    insertar(pila,5);
    int cabeza = valor_tope(pila);
    printf("El numero de la cabeza de la pila es: %d \n",cabeza);
    mostrar_pila(pila);
    eliminar(pila);
    mostrar_pila(pila);
    return 1;
}