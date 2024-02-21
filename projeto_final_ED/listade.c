#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "listade.h"

void criaLista(LISTADE *lista){
     lista->inicio = NULL;
     lista->fim = NULL;
     lista->n = 0;
}

void exibe(LISTADE lista){
     Nodo *pAux;
     pAux = lista.inicio;
     
     while (pAux != NULL) {
           printf("Codigo: %d, Nome: %s, Preço: R$%.2f\n", pAux->produto.cod, pAux->produto.nome, pAux->produto.preco);
           pAux = pAux->prox;
     }
}

float valorTotal (LISTADE lista){
	float total=0;
	Nodo *pAux;
	
	for(pAux=lista.inicio; pAux != NULL; pAux=pAux->prox){
		total += pAux->produto.preco;
	}
	return total;
}

int excluiDoInicio(LISTADE *lista, DADO *dado){
	Nodo *pTemp;
	if(lista->inicio==NULL){
		return LISTA_VAZIA;
	}else{
		*dado = lista->inicio->produto;
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
		pNodo->produto = dado;
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
			*dado = pTemp->produto;
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
		if(pAux->produto.cod == cod){
			*dado = pAux->produto;
			return SUCESSO;
		}
	}
	return CODIGO_INEXISTENTE;
}

int excluiNodo(LISTADE *lista, int cod, DADO *dado){
	Nodo *pAux, *pTemp;
	
	for(pAux = lista->inicio; pAux != NULL; pAux = pAux->prox){
		if(pAux->produto.cod == cod){
			*dado = pAux->produto;
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

void gravaArquivo(LISTADE lista){
	FILE *stream; char nomeArq[12];
	
	Nodo *aux;
	aux = lista.inicio;
	
	strcpy(nomeArq,"produtos.txt");
	
	if((stream=fopen(nomeArq,"w"))==NULL){
		printf("Não foi possível abrir %s\n", nomeArq);
	} else {
		while(aux != NULL){
			fprintf(stream,"%d %s %.2f\n", aux->produto.cod, aux->produto.nome, aux->produto.preco);
			aux = aux->prox;
		}
	}
	fclose(stream);
	printf("Gravação realizada com sucesso!\n");
}

void lerArquivo(LISTADE *lista){
	FILE *stream; char nomeArq[12]; DADO produto;
	int i = 0;
	
	strcpy(nomeArq,"produtos.txt");
	
	if((stream=fopen(nomeArq,"r"))==NULL){
		printf("Não foi possível abrir %s\n", nomeArq);
	}else{
		while(fscanf(stream, "%d %s %f", &produto.cod, &produto.nome, &produto.preco)!=EOF){
			incluiNoFim(lista, produto);
		}
		fclose(stream);
		printf("Importação realizada com sucesso!\n");
	} 
}

