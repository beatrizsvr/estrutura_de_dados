//header funcoes e typedef e define

#ifndef pilha_H
#define SUCESSO 0
#define PILHA_VAZIA 1
#define FALTOU_MEMORIA 2

typedef struct {
	int cod;
	float peso;
} DADO;

typedef struct nodo Nodo;

struct nodo {
	DADO info;
	Nodo *prox;
};

typedef struct {
	Nodo *topo;
} PILHASE;


void criaPilha(PILHASE *pilha);
int empilha (PILHASE *pilha, DADO dado);
int desempilha(PILHASE *pilha, DADO *dado);
int quantidadeDeNodos (PILHASE pilha);
int estaVazia(PILHASE pilha);
int consulta(PILHASE pilha, int *dado);
void exibe(PILHASE pilha);

#endif
