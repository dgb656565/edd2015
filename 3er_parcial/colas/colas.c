#include "operaciones.h"

void inicializar(struct nodo *elemento)
{
	elemento->sig = NULL;
}

void push(struct nodo *elemento, int valor_nuevo)
{
	struct nodo *nuevo;
	struct nodo *actual;

	actual = elemento;
	nuevo = (struct nodo*) malloc(sizeof(struct nodo) * 1);
	nuevo->val = valor_nuevo;

	while(actual->sig != NULL){
        actual = actual->sig;
	}

	nuevo->sig = actual->sig;
	actual->sig= nuevo;
}

void pop(struct nodo *elemento)
{
	struct nodo *actual;
	struct nodo *borrar;

	if (elemento->sig != NULL) {
		actual = elemento->sig;
		borrar = elemento->sig;

		actual = actual->sig;
		free(borrar);
		
    	}
}

void tope(struct nodo * elemento)
{
	struct nodo *actual;

	actual = elemento;

	while(actual->sig != NULL){
		actual = actual->sig;
	}

	printf("El tope es: %d, \n ",actual->val);
}

