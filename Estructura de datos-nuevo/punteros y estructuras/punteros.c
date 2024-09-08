#include<stdio.h>

void punteroSimple();
void punteroSimple (int* parametro){
    return ;
}

void punteroDoble();
void punteroDoble(int ** parametro){
    return ;
}

int main() {
     
    int x , *y ;

    x = 5 ; y = &x;

     /*           Puntero simple             */

    printf("valor de variable x : %d\n", x);
    printf("direccion de memoria de variable x : %p\n", &x);
    printf("direccion de memoria de puntero y : %p\n", &y);
    printf("direccion de memoria apuntado por y (direccion de memoria de x): %p\n", y);
    printf("valor de direccion de memoria apuntado por y (valor de x): %d\n\n", *y); //paso por referencia

    /*           Puntero doble             */
    int a = 10 , *b , **c;
    b = &a ; c = &b ;

    printf("valor de variable a : %d\n", a);
    printf("direccion de memoria de variable a : %p\n", &a);
    printf("direccion de memoria de puntero b : %p\n", &b);
    printf("direccion de memoria apuntada por b (direccion de memoria de a) : %p\n", b);
    printf("lo que apunta c (direccion de memoria de b): %p\n", *c);
    printf("lo apuntado por c , apuntado por b (valor de a): %d\n", **c); //paso por referencia
    
    /*     Enviar como argumento un puntero simple     */

    int arg1 = 55;
    punteroSimple(&arg1);

    /*     Enviar como argumento un puntero doble     */

    int *arg2;
    punteroDoble(&arg2); 

    return 1;
}