#ifndef listade_H
#define listade_H

#define SUCESSO 0
#define LISTA_VAZIA 1
#define FALTOU_MEMORIA 2
#define CODIGO_INEXISTENTE 3

typedef struct {
        int cod;
        float peso;
} DADO;
        
typedef struct nodo Nodo;

struct nodo {
       DADO info;
       Nodo *ant;
       Nodo *prox;
};

typedef struct {
        Nodo *inicio;
        Nodo *fim;
        int n;
} LISTADE;

void criaLista(LISTADE *lista);
int incluiNoInicio(LISTADE *lista, DADO dado);
void exibe(LISTADE lista);
int quantidadeDeNodos (LISTADE lista);
int estaVazia (LISTADE lista);
int excluiDoInicio(LISTADE *lista, DADO *dado);
int incluiNoFim(LISTADE *lista, DADO dado);
int incluiDepois(LISTADE *lista, int cod, DADO dado);
int excluiNodo(LISTADE *lista, int cod, DADO *dado);
void gravaArquivo(ListaDE *lista, FILE *arquivo);
void leArquivo(ListaDE *lista);


#endif
