//header funcoes e typedef e define

#ifndef fila_H
#define SUCESSO 0
#define FILA_VAZIA 1
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
	Nodo *frente;
	Nodo *re;
} FILASE;

void criaFila(FILASE *fila);
int insere(FILASE *fila, DADO dado);
int retira(FILASE *fila, DADO *dado);
int estaVazia(FILASE fila);
int consulta(FILASE fila, DADO *dado);
void quantidadeDeNodos(FILASE fila);
void exibe(FILASE fila);

#endif
