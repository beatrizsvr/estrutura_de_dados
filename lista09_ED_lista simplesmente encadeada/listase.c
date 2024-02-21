#include <stdio.h>
#include <stdlib.h>
#include "listase.h"

void criaLista(LISTASE *lista){
     lista->inicio = NULL;
}

int incluiNoInicio(LISTASE *lista, Dado dado){
    Nodo *pNodo;
    pNodo = (Nodo *) malloc (sizeof (Nodo));
    if (pNodo == NULL)
       return(FALTOU_MEMORIA);
    else {
       pNodo->info = dado;
       pNodo->prox = lista->inicio;
       lista->inicio = pNodo;
       return(SUCESSO);
    }
}
 
void exibe(LISTASE lista){
     Nodo *pAux;
     pAux = lista.inicio;
     printf("\nInicio: %p \n", lista.inicio);
     printf("Exibindo a Lista\n");
     printf("[EnderecoNodo] [Codigo] [Peso] [EnderecoProx]\n");
     while (pAux != NULL) {
           printf("%p - %3d %.2f - %p\n", pAux, pAux->info.cod, pAux->info.peso, pAux->prox);
           pAux = pAux->prox;
     }
}

int quantidadeDeNodos(LISTASE lista){
    int conta=0;
    Nodo *pAux;
    
    pAux = lista.inicio;
    while (pAux != NULL) {
           conta++;
           pAux = pAux->prox;
    }
    return(conta);
}

int estaVazia(LISTASE lista){
    if (lista.inicio==NULL)
       return(LISTA_VAZIA);
    else
       return(0);     
}

int excluiDoInicio(LISTASE *lista, Dado *dado){
	Nodo *pTemp;
	if(lista->inicio==NULL){
		return LISTA_VAZIA;
	} else {
		*dado = lista->inicio->info;
		pTemp = lista->inicio;
		lista->inicio = lista->inicio->prox;
		free (pTemp);
		return SUCESSO;
	}
}

int incluiNoFim(LISTASE *lista, Dado dado){
	Nodo *pNodo, *pAux;
	//pnodo carrega os dados do main e paux é o usado p chegar no fim da lista e incluir o pnodo nele
	pNodo = (Nodo *) malloc (sizeof (Nodo));
	if(pNodo == NULL){
		return(FALTOU_MEMORIA);
	} else {
		pNodo->info=dado;
		pNodo->prox=NULL;
		if(lista->inicio==NULL){
			lista->inicio=pNodo;
		} else {
			for(pAux=lista->inicio; pAux->prox != NULL; pAux=pAux->prox){	
			}
			pAux->prox=pNodo;
		}
		return SUCESSO;	
	}
}

int excluiDoFim(LISTASE *lista, Dado *dado){
	Nodo *pTemp, *pAux;
	
	if(lista->inicio==NULL){
		return LISTA_VAZIA;
	} else {
		if(lista->inicio->prox==NULL){
			pTemp=lista->inicio;
			*dado = pTemp->info;
			lista->inicio=NULL;
			free (pTemp);
		} else {
			for(pTemp=lista->inicio; pTemp->prox->prox != NULL; pTemp=pTemp->prox){
			}
			*dado = pTemp->prox->info;
			pAux = pTemp->prox;
			pTemp->prox = NULL;
			free (pAux); //o free nao tornaria o pAux null?	
		}
	}
	return SUCESSO;
}

int incluiDepois(LISTASE *lista, int cod, Dado dado){
	Nodo *pNodo, *pAux;
	
	pNodo = (Nodo *) malloc (sizeof (Nodo));//quando vai adicionar um nodo
	if(pNodo == NULL){
		return(FALTOU_MEMORIA);
	} else{
		pNodo->info=dado;
		for(pAux=lista->inicio; pNodo->prox != NULL; pAux=pAux->prox){
			if(pAux->info.cod == cod){
				pAux->prox=pNodo;
			}
		}
		return SUCESSO;
	}
	return CODIGO_INEXISTENTE;
}

int excluiNodo(LISTASE *lista, int cod, Dado *dado){
	Nodo *pTemp, *pAux;
	
	for(pAux=lista->inicio; pAux != NULL; pAux=pAux->prox){
		if(pAux->info.cod==cod && pAux==lista->inicio){
			*dado= pAux->info;
			pTemp = pAux;
			*dado = pAux->prox->info;
			pTemp=pAux->prox;
			pAux->prox=pAux->prox->prox;
			free(pTemp);
			return SUCESSO;
		}
	}
	return CODIGO_INEXISTENTE;
}


int consultaPorCodigo(LISTASE lista, int cod, Dado *dado){
	Nodo *pNodo, *pAux;
	for(pAux=lista.inicio; pAux != NULL; pAux->prox){
		if(pAux->info.cod==cod){
			*dado = pAux->info;
			return SUCESSO;
	} else {
		return CODIGO_INEXISTENTE;
		}
	}
}
