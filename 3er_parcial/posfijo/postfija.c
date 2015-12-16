#include <stdio.h>
#include "postfija.h"

int main( int argc, char **argv ){
    
    char expresion[201];
    printf("\n\n\t* Programa que convierte una expresion INFIJA a su notacion POSTFIJA. *\n\n");
    printf("* Teclee expresion infija, separando cada elemento por un espacio: ");
    gets( expresion );
    
    convierteIP( expresion );
    return 0;
    
}
