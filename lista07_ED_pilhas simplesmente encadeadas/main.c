#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "pilhasSE.h"

main(){
	
	PILHASE pilha;
	DADO dado;
	int op;
	
	criaPilha(&pilha);
	
	for(op=21;op!=0;){
		printf("Digite uma escolha do cardapio:\n 0.Fim\n 1.Empilha\n 2.Desempilha\n 3.Quantidade de nodos\n 4. Exibe situacao da pilha\n 5.Consulta topo\n");
		scanf("%d", &op);
		
		if(op==1){
			printf("Digite o codigo e o peso:\n");
			scanf("%d %f", &dado.cod, &dado.peso);
			
			if(empilha(&pilha, dado)==SUCESSO){
				printf("Dado inserido com sucesso\n");
			} else {
				printf("Faltou memoria\n");
			}
		} else if(op==2){
			if(desempilha(&pilha, &dado)==SUCESSO){
				printf("Dados excluidos:\n Codigo: %d, Peso: %.2f\n", dado.cod, dado.peso);
			} else {
				printf("Pilha vazia\n");
			}	
		} else if(op==3){
			printf("Quantidade de nodos: %d\n", quantidadeDeNodos(pilha));
		} else if(op==4){
			if(estaVazia(pilha)==1){
				printf("A pilha esta vazia\n");
			} else {
				printf("A pilha possui 1 ou mais nodos\n");
			}
		} else if(op==5){
			if(consultaTopo(pilha, &dado)==PILHA_VAZIA){
				printf("Pilha vazia\n");
			} else {
				printf("Exibindo topo\nCodigo: %d, Peso: %f\n", dado.cod, dado.peso);
			}
		}
		
		exibe(pilha);
	}
	
}
