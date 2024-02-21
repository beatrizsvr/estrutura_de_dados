#ifndef listade_H
#define listade_H

#define SUCESSO 0
#define LISTA_VAZIA 1
#define FALTOU_MEMORIA 2
#define CODIGO_INEXISTENTE 3

typedef struct {
        int cod;
        float preco;
        char nome[30];
} DADO;
        
typedef struct nodo Nodo;

struct nodo {
       DADO produto;
       Nodo *ant;
       Nodo *prox;
};

typedef struct {
        Nodo *inicio;
        Nodo *fim;
        int n;
} LISTADE;

void criaLista(LISTADE *lista);
void exibe(LISTADE lista);
int excluiDoInicio(LISTADE *lista, DADO *dado);
int excluiDoFim (LISTADE *lista, DADO *dado);
int excluiNodo(LISTADE *lista, int cod, DADO *dado);
int incluiNoFim(LISTADE *lista, DADO dado);
void gravaArquivo(LISTADE lista);
void lerArquivo(LISTADE *lista);
int consultaPorCodigo (LISTADE lista, int cod, DADO *dado);
float valorTotal (LISTADE lista);

#endif
