#include "operaciones.h"

void inicializar(struct nodo *cabecera)
{
	cabecera->sig = NULL;
	cabecera->ant = NULL;
}

void insertar_al_principio(struct nodo *cabecera, int valor_nuevo)
{
	struct nodo *nuevo;

	nuevo = (struct nodo*) malloc(sizeof(struct nodo) * 1);
	nuevo->val = valor_nuevo;

	nuevo->sig = cabecera->sig;
	nuevo->ant = cabecera;

	if (cabecera->sig =! NULL) {
		cabecera->sig->ant = nuevo;
		// La anterior linea es igual a las siguientes dos inscruciones
		// tmp = cabecera->sig;
		// tmp->ant = nuevo;
	}

	cabecera->sig = nuevo;
}

void borrar_lista(struct nodo *cabecera)
{
	struct nodo *actual;
	struct nodo *borrar;

	/* Si es diferente de nulo borrar lista */
	if (cabecera->sig != NULL) {
		actual = cabecera->sig;
		borrar = cabecera->sig;
		/* Mientras el siguiente sea diferente de nulo */
		while ( actual->sig != NULL) {
			actual = actual->sig;
			free(borrar);
			borrar = actual;
		}
		free(borrar);
		cabecera->sig = NULL;
	}
}

void ordenar_burbuja(struct nodo *cabecera)
{
	struct nodo *actual;
	float auxiliar;
	int   esta_ordenado = 0;

	if (cabecera->sig != NULL) {
		while ( ! esta_ordenado ) {
			esta_ordenado = 1;
			actual = cabecera->sig;
			while ( actual->sig != NULL ) {
				if (actual->val > actual->sig->val) {
					auxiliar = actual->val;
					actual->val = actual->sig->val;
					actual->sig->val = auxiliar;
					esta_ordenado = 0;
				}
				actual = actual->sig;
			}
		}
	}
}



