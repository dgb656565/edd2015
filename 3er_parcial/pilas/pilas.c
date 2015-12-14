#include "operaciones.h"

void inicializar(struct nodo *elemento)
{
	elemento->sig = NULL;
}

void push(struct nodo *elemento, int valor_nuevo)
{
	struct nodo *nuevo;

	nuevo = (struct nodo*) malloc(sizeof(struct nodo) * 1);
	nuevo->val = valor_nuevo;

	nuevo->sig = elemento->sig;
	elemento->sig = nuevo;
}

void tope(struct nodo *elemento)
{
	struct nodo *actual;

	actual = elemento;

	printf("%d, \n ", actual->val);
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
		borrar = actual;
		
    	}
}

