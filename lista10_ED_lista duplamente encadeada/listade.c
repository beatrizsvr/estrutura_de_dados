#include <stdio.h>
#include <stdlib.h>
#include "listade.h"

void criaLista(LISTADE *lista){
     lista->inicio = NULL;
     lista->fim = NULL;
     lista->n = 0;
}

int incluiNoInicio(LISTADE *lista, DADO dado){
    Nodo *pNodo;
    pNodo = (Nodo *) malloc (sizeof (Nodo));
    if (pNodo == NULL) {
       return(FALTOU_MEMORIA);
   	}else{
       pNodo->info = dado;
       pNodo->prox = lista->inicio;
       pNodo->ant = NULL;
	}
     
	if (lista->n == 0){
        lista->fim = pNodo;
    }else{
        lista->inicio->ant = pNodo;  
	}
	
    lista->inicio = pNodo;
    lista->n++;
    return(SUCESSO);
}

void exibe(LISTADE lista){
     Nodo *pAux;
     pAux = lista.inicio;
     printf("\nExibindo a Lista\n");
     printf("Inicio: %p \n", lista.inicio);
     printf("[End Ant] [cd] [End Nodo] [peso] [End Prox]\n");
     while (pAux != NULL) {
           printf("%p - %3d %p %.2f - %p\n", pAux->ant, pAux->info.cod, pAux, pAux->info.peso, pAux->prox);
           pAux = pAux->prox;
     }
     printf("Fim: %p - N= %d\n", lista.fim, lista.n);
}

int quantidadeDeNodos (LISTADE lista){
	if(lista.inicio==NULL){
		return 0;
	} else {
		return lista.n;
	} 
}

int estaVazia (LISTADE lista){
	if(lista.inicio==NULL){
		return 1;
	}else{
		return 0;
	}
}

int excluiDoInicio(LISTADE *lista, DADO *dado){
	Nodo *pTemp;
	if(lista->inicio==NULL){
		return LISTA_VAZIA;
	}else{
		*dado = lista->inicio->info;
		pTemp = lista->inicio;
		lista->inicio = lista->inicio->prox;
		free(pTemp);
		lista->n--;
		return SUCESSO;
	}
}

int incluiNoFim(LISTADE *lista, DADO dado){
	Nodo *pNodo;
	
	pNodo = (Nodo *) malloc (sizeof (Nodo));
	
	if(pNodo == NULL){
	    return(FALTOU_MEMORIA);
	}else{
		pNodo->info = dado;
		pNodo->prox = NULL;
		if(lista->inicio== NULL){
			lista->inicio = pNodo;
			pNodo->ant = NULL;
		} else {
			lista->fim->prox = pNodo;
			pNodo->ant = lista->fim;
		}
		lista->fim = pNodo;
	}
    lista->n++;
    return(SUCESSO);
}

int excluiDoFim (LISTADE *lista, DADO *dado){
	Nodo *pTemp;
	
	if(lista->inicio==NULL){
		return LISTA_VAZIA;
	}else{
		if(lista->inicio->prox==NULL){
			excluiDoInicio(lista,dado);
		} else {
			pTemp = lista->fim;
			*dado = pTemp->info;
			pTemp->ant->prox = NULL;
			lista->fim = pTemp->ant;
			free (pTemp);
			lista->n--;
			return SUCESSO;
		}
	}
	lista->n--;
}

int consultaPorCodigo (LISTADE lista, int cod, DADO *dado){
	Nodo *pAux;
	for(pAux = lista.inicio; pAux != NULL; pAux = pAux->prox){
		if(pAux->info.cod == cod){
			*dado = pAux->info;
			return SUCESSO;
		}
	}
	return CODIGO_INEXISTENTE;
}

int incluiDepois(LISTADE *lista, int cod, DADO dado){
	Nodo *pAux, *pNodo;
	
	pNodo = (Nodo *) malloc (sizeof (Nodo));
	
	if (pNodo == NULL) {
       return(FALTOU_MEMORIA);
   	}else{
		for(pAux = lista->inicio; pAux != NULL; pAux = pAux->prox){
			if(pAux->info.cod == cod){
				if(pAux->prox == NULL){
					incluiNoFim(lista, dado);
				} else {
					pNodo->info = dado;
					pNodo->ant = pAux;
					pNodo->prox = pAux->prox;
					pAux->prox = pNodo;
					pNodo->prox->ant = pNodo;
				}
				lista->n++;
				return SUCESSO;
			}
	}
		return CODIGO_INEXISTENTE;
	}	
}

int excluiNodo(LISTADE *lista, int cod, DADO *dado){
	Nodo *pAux, *pTemp;
	
	for(pAux = lista->inicio; pAux != NULL; pAux = pAux->prox){
		if(pAux->info.cod == cod){
			*dado = pAux->info;
			if(pAux->ant == NULL){
				excluiDoInicio(lista, dado);
			} else if(pAux->prox == NULL){
				excluiDoFim(lista, dado);
			} else {
				pTemp = pAux;	
				pAux->ant->prox = pAux->prox;
				pAux->prox->ant = pAux->ant;
				free (pTemp);
			}
			lista->n--;
			return SUCESSO;
		}
	}
		return CODIGO_INEXISTENTE;
}

