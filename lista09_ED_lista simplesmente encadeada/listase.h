#ifndef Listase_H
#define Listase_H

#define SUCESSO 0
#define LISTA_VAZIA 1
#define FALTOU_MEMORIA 2
#define CODIGO_INEXISTENTE 3

typedef struct {
        int cod;
        float peso;
} Dado;
        
typedef struct nodo Nodo;

struct nodo {
       Dado info;
       Nodo *prox;
};

typedef struct {
        Nodo *inicio;
} LISTASE;

void criaLista(LISTASE *lista);
int incluiNoInicio(LISTASE *lista, Dado dado);
void exibe(LISTASE lista);
int quantidadeDeNodos(LISTASE lista);
int estaVazia(LISTASE lista);
int excluiDoInicio(LISTASE *lista, Dado *dado);
int incluiNoFim(LISTASE *lista, Dado dado);
int excluiDoFim(LISTASE *lista, Dado *dado);
int incluiDepois(LISTASE *lista, int cod, Dado dado);
int excluiNodo(LISTASE *lista, int cod, Dado *dado);
int consultaPorCodigo(LISTASE lista, int cod, Dado *dado);

#endif
