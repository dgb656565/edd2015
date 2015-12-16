#define TRUE 1
#define FALSE 0

/****************** OPERACIONES DE PILA **********************/
/*                	   Pila dinamica 		                 */

struct pilad{
	char valorpd[20];
	int prioridad;
	struct pilad *sig;
};

typedef struct pilad *PILAPTR;
PILAPTR tope = NULL;

int esVaciapd(){
	return ( tope == NULL ) ? TRUE : FALSE;
}
void push( char *operador, int prioridad ){
	PILAPTR nuevo_elemento = (PILAPTR) malloc( sizeof( struct pilad ) );
	nuevo_elemento -> sig = esVaciapd() ? NULL : tope;
	strcpy( nuevo_elemento -> valorpd, operador );
	nuevo_elemento -> prioridad = prioridad;
	tope = nuevo_elemento;
}
void pop(){
	if( !esVaciapd() ){
		PILAPTR temp_elemento = tope;
		tope = tope -> sig;
		free( temp_elemento );
	}
}
char *get(){
	return esVaciapd() ? "" : tope -> valorpd;
}

int prioridadTopePila(){
	return esVaciapd() ? -1 : tope -> prioridad;
}
