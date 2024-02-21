#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "filaSE.h"

main(){
	
	FILASE fila;
	DADO dado;
	int op;
	
	criaFila(&fila);
	
	for(op=21;op!=0;){
		printf("Digite uma escolha do cardapio:\n 0.Fim\n 1.Insere\n 2.Retira\n 3.Quantidade de nodos\n 4. Exibe situacao da fila\n 5.Consulta frente\n");
		scanf("%d", &op);
		
		if(op==1){
			printf("Digite o codigo e o peso:\n");
			scanf("%d %f", &dado.cod, &dado.peso);
			
			if(insere(&fila, dado)==SUCESSO){
				printf("Dado inserido com sucesso\n");
			} else {
				printf("Faltou memoria\n");
			}
		} else if(op==2){
			if(retira(&fila, &dado)==FILA_VAZIA){
					printf("Fila vazia\n");
			} else {
				printf("Dados excluidos:\n Codigo: %d, Peso: %.2f\n", dado.cod, dado.peso);
			}
		} else if(op==3){
			printf("Quantidade de nodos: %d\n", quantidadeDeNodos(fila));
		} else if(op==4){
			if(estaVazia(fila)==1){
				printf("Fila vazia\n");
			} else {
				printf("A fila possui 1 ou mais nodos\n");
			}
		} else (op==5){
			if(consulta(fila, &dado)==FILA_VAZIA){
				printf("Fila vazia\n");
			} else {
				printf("Exibindo frente\nCodigo: %d, Peso: %f\n", dado.cod, dado.peso);
			}
		}
		exibe(fila);
	}
	
}
