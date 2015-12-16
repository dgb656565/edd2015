#include <stdlib.h>
#include <string.h>

/****************** OPERACIONES DE LISTA **********************/
/*                Lista doblemente enlazada                   */

struct nodo_lde{
    char elemento[20];
    struct nodo_lde *izq;
    struct nodo_lde *der;
};
typedef struct nodo_lde *NODOLDE;
NODOLDE ref_lista = NULL;

void inserta_lista( NODOLDE *lista, char *token ){
     NODOLDE q, nuevo_nodo = ( NODOLDE ) malloc( sizeof( struct nodo_lde ) );
     strcpy( nuevo_nodo -> elemento , token );
     if( *lista == NULL ){
         *lista = nuevo_nodo;
         (*lista) -> der = NULL;
     }else{
     	 for( q = *lista; q -> der != NULL; q = q -> der );
         q -> der = nuevo_nodo;
         nuevo_nodo -> izq = q;
         nuevo_nodo -> der = NULL;
     }    
     (*lista) -> izq = NULL;     
}

void elimina( NODOLDE *lista ){
	 if( ref_lista == *lista ){
		 *lista = (*lista) -> der;
		 if( *lista != NULL ) (*lista) -> izq = NULL;
	 }else{
		 if( ref_lista -> der == NULL )
		     ref_lista -> izq -> der = NULL;
		 else{
		      ref_lista -> izq -> der = ref_lista -> der;
		      ref_lista -> der -> izq = ref_lista -> izq;
		 }
	 }
	 free( ref_lista );
}

void vaciaLista( NODOLDE *lista ){
	NODOLDE p = *lista;
	while( p != NULL ){
		ref_lista = p;
		p = p -> der;
		elimina( lista );
	}
}

void imprimirLista( NODOLDE lista, char *tipo ){
    printf("\nLista %s: ", tipo );
    for( ref_lista = lista; ref_lista != NULL; ref_lista = ref_lista -> der ){
         // Alguna otra accion con cada token. Usar ( ref_lista -> elemento ) */
         printf("%s ", ref_lista -> elemento );
    }     
	printf("\n");
}

