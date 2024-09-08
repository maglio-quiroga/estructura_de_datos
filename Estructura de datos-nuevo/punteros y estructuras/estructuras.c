#include<stdio.h>
#include<stdlib.h>

typedef struct estructura{
    //propiedades de la estructura...
    int dato1;
    float dato2;

}estructura;

void imprimirEstructura(estructura e);
void imprimirEstructura(estructura e) {
    printf("Dato1: %d\n", e.dato1);
    printf("Dato2: %.2f\n", e.dato2);
}

void modificarEstructura(estructura *e, int nuevoDato1, float nuevoDato2);
void modificarEstructura(estructura *e, int nuevoDato1, float nuevoDato2) {
    e->dato1 = nuevoDato1;
    e->dato2 = nuevoDato2;
}

int main() {

    estructura var1;
    estructura *var2;

    /* Acceder a las propiedades de un struct con una variable del struct*/
    var1.dato1 = 3 ; var1.dato2 = 3.33;

    /* Acceder a las propiedades de un struct con una puntero del struct*/

    //var2->dato1 = 4 ; var2->dato2 = 4.44;

    /* Funciones malloc y free */

    var2 = (estructura *)malloc(sizeof(estructura)); // reservo memoria del tamaño de estructura y hago un forzado de tipo
    if (var2 == NULL){
        //no se pudo reservar espacio en memoria, manejar el error
    }
    free(var2); //libero de memoria a var2

    imprimirEstructura(var1);
    modificarEstructura(&var1 , 2 , 2.22);
    imprimirEstructura(var1);

    return 1;
}