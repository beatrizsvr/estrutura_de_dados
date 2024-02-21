#ifndef Lista_H
#define Lista_H
#define MAX_NODOS 5
#define SUCESSO 0
#define LISTA_VAZIA 1
#define LISTA_CHEIA 2
#define CODIGO_INEXISTENTE 3

typedef struct {
        int cod;
        float peso;
} DADO;

typedef struct {
        int n;
        DADO v[MAX_NODOS];
} LISTACF;

#endif
