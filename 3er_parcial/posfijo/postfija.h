#include "lista_doble.h"
#include "pila_dinamica.h"

#define TRUE 1
#define FALSE 0

void convierteIP( char *expresion ){

	NODOLDE infija = NULL, postfija = NULL, p;
	
	/* Creamos lista infija con los elementos de la expresion */
	char *token = strtok( expresion, " " );
	while( token != NULL ) {
    	inserta_lista( &infija, token ); 
    	token = strtok( NULL, " " );
	}
    
    /* Convertimos infija a expresion postfija */
    for( p = infija; p != NULL; p = p -> der ){
    	if( esNumero( p -> elemento ) ){ // Es operando
    		inserta_lista( &postfija, p -> elemento );
    	}else{
    		if( strcmp( p->elemento, ")" ) == 0 ){ // Token igual a ")"
    			while( strcmp( get(), "(") != 0 && !esVaciapd() ){
    				inserta_lista( &postfija, get() );
    				pop();
    			}
    			pop(); // Removemos el parentesis.
    		}else{
    			if( !esVaciapd() ){
    				push( p->elemento, obtenerPrioridadDe( p->elemento ) );
    			}else{
    				if( obtenerPrioridadDe( p->elemento ) >  prioridadTopePila() ){
    					push( p->elemento, obtenerPrioridadDe( p->elemento ) );
    				}else{
    					inserta_lista( &postfija, get() );
    					pop();	
    				}
    			}
    		}
    	}
    }
    while( !esVaciapd() ){
    	inserta_lista( &postfija, get() );
    	pop();		
    }
    /* Imprimimos listas */
    imprimirLista( infija, "infija" );
    imprimirLista( postfija, "postfija" );
    
    /* Vaciamos listas para liberar memoria */
    vaciaLista( &infija );
    vaciaLista( &postfija );
}

/* Regresa la prioridad del operador op */
int obtenerPrioridadDe( char *op ){
	if( strstr("*/", op ) != NULL ) return 2;	
	if( strstr("+-", op ) != NULL )	return 1;	
	if( strstr("(", op ) != NULL )	return 0;	
	return -1;
}

/* Regresa verdadero si la cadena n es un numero entero o flotante */
int esNumero( char *n ){
	if( strcmp( n, "+" ) != 0 && strcmp( n, "-" ) != 0 && strcmp( n, "/" ) != 0 && strcmp( n, "*" ) != 0 && strcmp( n, "(" ) != 0 && strcmp( n, ")" ) != 0 ){
		return TRUE;
	}else{
		return FALSE;
	}
}
