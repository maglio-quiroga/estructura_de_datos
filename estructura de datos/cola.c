#include"cola.h"

int main()
{
    cola* cola = crearcola();
    insertar(cola,1);
    insertar(cola,2);
    insertar(cola,3);
    insertar(cola,4);
    insertar(cola,5);
    int prim,ult;
    prim = primero(cola);
    ult = ultimo(cola);
    printf("EL PRIMERO ES %d Y EL ULTIMO ES %d \n",prim,ult);
    mostrarcola(cola);
    eliminar(cola);
    mostrarcola(cola);
    return 1;
}