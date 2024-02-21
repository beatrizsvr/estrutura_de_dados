#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void criaLista(LISTACF *lista){
	lista->n=0;
}
     
int incluiNoFim(LISTACF *lista, DADO dado){
    if(lista->n==MAX_NODOS){
		return LISTA_CHEIA;
    } else {
		lista->v[lista->n]=dado;
		lista->n++;
		return SUCESSO;
    }
}

void exibe(LISTACF lista){
	int i;
	for(i=0;i<=lista.n;i++){
		int i;
		printf("Nodo %d - Cod: %d\nPeso: %d\n", i+1, lista.v[i].cod, lista.v[i].peso);
}
	
int quantidadeDeNodos(LISTACF lista){
	return lista.n;
}

int estaCheia(LISTACF lista){
	if(lista.n==MAX_NODOS){
		return 1;
	} else {
		return 0;
	}
	
int estaVazia(LISTACF lista){
	if(lista.n==0){
		return 1;
	} else {
		return 0;
	}
	
int excluiDoFim(LISTACF *lista, DADO *dado){
	if(lista->n==0){
		return LISTA_VAZIA;
	} else {
		*dado=lista.v[lista->n-1];
		lista->n--;
		return SUCESSO;
	}
	
int incluiNoInicio(LISTACF *lista, DADO *dado){
	int i;
	if(lista->n==MAX_NODOS){
		return LISTA_CHEIA;
	} else {
		for(i=lista->n;i>0;i--){
			lista->v[i]=lista->v[i-1];
		}
		lista->v[0]=dado;
		lista->n++;
		return SUCESSO;
	}
}

int excluiDoInicio(LISTACF *lista, DADO *dado){
	int i;
	if(lista->n==0){
		return LISTA_VAZIA;
	} else {
		*dado=lista->v[0];
		for(i=1;i<lista->n;i++){
			lista->v[i-1]=lista->v[i];
			lista->n--;
			return SUCESSO;
	}
}

int consultaPorCodigo(LISTACF *lista, int cod, DADO *dado){
	int i;
	if(
	for(i=0;i<=lista.n;i++){
		if(lista.v[i].cod==cod){
			dado=lista.v[i];
			return SUCESSO;
		} else{
			return DADO_INEXISTENTE;
		}
	}
}

int incluiAntes(LISTACF *lista, int cod, DADO *dado){
	int i;
	
	if(lista.n==MAX_NODOS){
		return LISTA_CHEIA;
	}
	
	for(i=0;i<=lista.n;i++){
		if(lista.v[i].cod==cod){
			dado=lista.v[i-1];
			return SUCESSO;
		}
	}
	

int excluiNodo(LISTACF* lista, int cod, int *n){
	int i;
	for(i=0;i<=lista->n;i++){
		if(lista->v[i].cod==cod){
			*n=lista->n--;
			return SUCESSO;
		} else {
			return CODIGO_INEXISTENTE;
		}
	}

		


                               

    
    
