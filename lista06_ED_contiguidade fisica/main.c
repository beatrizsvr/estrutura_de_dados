#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

main(){
	
	LISTACF lista;
	DADO dado;
	int op;
	
	criaLista(&lista);
	
	do{
		printf("Escolha uma execucao do menu:\n 0.Fim\n 1.Inclui no fim\n 2.Exibe lista\n 3.Quantidade de nodos\n 4.Exibe situaçao da lista\n 5.Exclui no fim\n 6.Inclui no incio\n 7.Exclui no inicio\n 8.Consulta por codigo\n 9.Inclui antes\n 10.Exclui nodo\n");
		scanf("%d", &op);
		
	}while(op!=0);
	
} 
