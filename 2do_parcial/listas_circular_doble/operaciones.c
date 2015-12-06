#include "operaciones.h"

void inicializar(struct nodo *cabecera)
{
	cabecera->sig = cabecera;
	cabecera->ant = cabecera;
}

void insertar_al_principio(struct nodo *cabecera, int valor_nuevo)
{
	struct nodo *nuevo;

	nuevo = (struct nodo*) malloc(sizeof(struct nodo) * 1);
	nuevo->val = valor_nuevo;

	nuevo->sig = cabecera->sig;
	nuevo->ant = cabecera;

	cabecera->sig->ant = nuevo;
	cabecera->sig = nuevo;
}

void insertar_al_final(struct nodo *cabecera, int valor_nuevo)
{
	struct nodo *nuevo;
	struct nodo *actual;

	actual = cabecera;
	nuevo = (struct nodo*) malloc(sizeof(struct nodo) *1);
	nuevo->val = valor_nuevo;
	actual = actual->ant;

	nuevo->sig = actual->sig;
	nuevo->ant = actual;
	nuevo->sig->ant = nuevo;
	actual->sig= nuevo;
}
void insertar_despues_de(struct nodo *cabecera, int valor_nuevo, int valor_antes)
{
	struct nodo *nuevo;
	struct nodo *actual;

	nuevo = (struct nodo*) malloc(sizeof(struct nodo)*1);
	nuevo->val = valor_nuevo;
	actual = cabecera;

	while(actual->sig != cabecera){
		actual = actual->sig;
		if(actual->val == valor_antes){
			nuevo->sig = actual->sig;
			nuevo->ant = actual;
			actual->sig = nuevo;
			nuevo->sig->ant = nuevo;
		}
	}
}

void imprimir_lista(struct nodo * cabecera)
{
	struct nodo *actual;

	actual = cabecera;

	while(actual->sig != cabecera){
		actual = actual->sig;
		printf("%d, \n ",actual->val);
	}
}

void borrar_lista(struct nodo *cabecera)
{
	struct nodo *actual;
	struct nodo *borrar;

	/* Si es diferente de nulo borrar lista */
	if (cabecera->sig != cabecera) {
		actual = cabecera->sig;
		borrar = cabecera->sig;
		/* Mientras el siguiente sea diferente de nulo */
		while ( actual->sig != cabecera) {
			actual = actual->sig;
			free(borrar);
			borrar = actual;
		}
		free(borrar);
		cabecera->sig = cabecera;
		cabecera->ant = cabecera;
	}
}

void borrar_elemento(struct nodo *cabecera, int valor_borrar)
{

	struct nodo *actual;
	struct nodo *borrar;

	actual = cabecera;
	borrar = cabecera;

	borrar->val = valor_borrar;

	while(actual->sig != cabecera){
		borrar = borrar->sig;
		if(borrar->val == valor_borrar){
			actual->sig = borrar->sig;
			actual->sig->ant = actual;
			free(borrar);
		}
		actual = actual->sig;
	}
}
