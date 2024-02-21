#include <stdio.h>
#include <stdlib.h>
#include "filaSE.h"

void criaFila(FILASE *fila){
	fila->frente=NULL;
	fila->re=NULL;
}

int insere(FILASE *fila, DADO dado){
	Nodo *pNodo;
	
	pNodo = (Nodo *) malloc (sizeof(Nodo));
	
	if(pNodo==NULL){
		return FALTOU_MEMORIA;
	} else {
		pNodo->info=dado;
		pNodo->prox=NULL;
		if(fila->re==NULL){
			fila->frente = pNodo;
		} else {
			fila->re->prox = pNodo;	
		}
		fila->re = pNodo;
		return SUCESSO;
	}
}

int retira(FILASE *fila, DADO *dado){
	Nodo *pNodo;
	
	if(fila->frente==NULL){
		return FILA_VAZIA;
	} else {
		pNodo=fila->frente;
		*dado=pNodo->info;
		if(fila->frente==fila->re){
			fila->re=NULL;
		}
		fila->frente=pNodo->prox;
		
		free(pNodo);
		return SUCESSO;
	}
}

int estaVazia(FILASE fila){
	if(fila.frente == NULL){
		return 1;
	} else {
		return 0;
	}
}

int consulta(FILASE fila, DADO *dado){
		if(fila.frente == NULL){
		return FILA_VAZIA;
	} else {
		*dado = fila.frente->info;
		return SUCESSO;
	}
}

void quantidadeDeNodos(FILASE fila){
	Nodo *pNodo;
	int c=0;
	
	for(pNodo = fila.frente; pNodo!=NULL; pNodo = pNodo->prox){
		c++;
	}
	return c;
}		
	
void exibe(FILASE fila){
	Nodo *pNodo;
	printf("Exibindo fila\n");
	for(pNodo = fila.frente; pNodo != NULL; pNodo = pNodo->prox){
		printf("End: %p Codigo: %d, Peso: %.2f  Prox: %p\n", pNodo, pNodo->info.cod, pNodo->info.peso, pNodo->prox);
	}
}
	
