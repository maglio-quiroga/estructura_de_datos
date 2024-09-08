#include"cola.h"

int main(){

    Cola* miCola = crearcola();  

    printf("Insertando elementos en la cola...\n");
    insertar(miCola, 10);
    insertar(miCola, 20);
    insertar(miCola, 30);

    printf("Mostrando la cola:\n");
    mostrarCola1(miCola);

    printf("El primer elemento de la cola es: %d\n", primero(miCola));
    printf("El último elemento de la cola es: %d\n", ultimo(miCola));

    printf("Eliminando un elemento...\n");
    eliminar(miCola);

    printf("Mostrando la cola después de eliminar un elemento:\n");
    mostrarCola1(miCola);

    printf("La longitud actual de la cola es: %d\n", len(miCola));

    destruirCola(miCola);

    return 1;
}