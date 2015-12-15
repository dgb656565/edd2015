#ifndef _OPERACIONES_H_
#define _OPERACIONES_H_

#include "nodo.h"

void inicializar(struct nodo *elemento);

void push(struct nodo *elemento, int valor_nuevo);

void pop(struct nodo *elemento, int valor_borrar);

void tope(struct nodo *elemento);

#endif
