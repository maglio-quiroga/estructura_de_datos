#include"pila.h"

int main(){

    Pila* miPila = crearpila();

    insertar(miPila, 10);
    insertar(miPila, 20);
    insertar(miPila, 30);

    printf("Mostrando elementos de la pila:\n");
    mostrarPila1(miPila);

    printf("Mostrando longitud de la pila\n");
    int l = len(miPila);
    printf("longitud:%d\n", l);

    /* Liberamos la memoria usada al termino  del programa */
    
    destruirPila(miPila);
    free(&l);

    return 1;
}