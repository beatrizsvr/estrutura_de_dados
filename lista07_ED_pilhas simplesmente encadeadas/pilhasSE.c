#include <stdio.h>
#include <stdlib.h>
#include "pilhasSE.h"

void criaPilha(PILHASE *pilha){
	pilha->topo = NULL;
}

int empilha (PILHASE *pilha, DADO dado){
	Nodo *pNodo;
	
	pNodo = (Nodo *) malloc (sizeof(Nodo)); //monta a estrutura de um nodo (montada nos typedef)
	
	if(pNodo == NULL){
		return FALTOU_MEMORIA;
	} else {
		pNodo->info = dado; //passa dado para info do nodo
		pNodo->prox = pilha->topo; //endereco do nodo recebe endereco do proximo nodo
		pilha->topo=pNodo; //nodo da pilha recebe o ultimo nodo
		return SUCESSO;
	}
}


int desempilha(PILHASE *pilha, DADO *dado){
	Nodo *pNodo;
	
	if(pilha->topo == NULL){
		return PILHA_VAZIA;
	} else {
		pNodo = pilha->topo; 
		*dado = pNodo->info;
		pilha->topo=pNodo->prox;
		free(pNodo);
		return SUCESSO;
	}
}

int quantidadeDeNodos (PILHASE pilha){
	Nodo *pNodo;
	int c=0;
	
	for(pNodo = pilha.topo; pNodo!=NULL; pNodo = pNodo->prox){
		c++;
	}
	
	return c;
}

int estaVazia(PILHASE pilha){
	if(pilha.topo == NULL){
		return 1;
	} else {
		return 0;
	}
}

void exibe(PILHASE pilha){
	Nodo *pNodo;
	printf("Exibindo pilha\n");
	//pNodo = pilha.topo; coloca no nodo o endereco do topo da pilha
	for(pNodo = pilha.topo; pNodo!=NULL; pNodo = pNodo->prox){
		printf("Codigo %d, Peso: %f\n", pNodo->info.cod, pNodo->info.peso);
	}		
}

int consultaTopo(PILHASE pilha, DADO *dado){
	if(pilha.topo == NULL){
		return PILHA_VAZIA;
	} else {
		*dado = pilha.topo->info;
		return SUCESSO;
	}
}		



		
	
