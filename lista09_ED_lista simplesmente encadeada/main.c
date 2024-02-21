#include <stdio.h>
#include <stdlib.h>
#include "listase.h"

int main()
{
    int op,cod,peso, aux;
    LISTASE lista;
    Dado dado;
    
    criaLista(&lista);

    do {
      printf("\n0. Fim                         5. Exclui do Inicio         10. Exclui Nodo\n");    
      printf("1. Inclui no Inicio            6. Inclui no Fim            \n");    
      printf("2. Exibe Lista                 7. Exclui do Fim            \n");    
      printf("3. Quantidade de Nodos         8. Consulta por Codigo      \n");    
      printf("4. Exibe Situacao da Lista     9. Inclui Depois.           \n");
      printf("Operacao: ");    
      scanf("%d", &op);

      switch(op){
            case 1:
                 printf("[Codigo][Peso]\n");
                 scanf ("%d %f", &dado.cod,&dado.peso);
                 if (incluiNoInicio(&lista, dado)==SUCESSO)
                    printf("Operacao Realizada com Sucesso!\n");
                 else
                    printf("Operacao NAO realizada: Faltou Memoria!");
                 break;
            case 2:
				exibe(lista);
				break;
            case 3:
                 printf("Quantidade de Nodos= %d\n", quantidadeDeNodos(lista));
                 break;
        	case 4:
				if(estaVazia(lista)==LISTA_VAZIA){
					printf("A lista esta vazia\n");
				} else {
					printf("A lista possui 1 ou mais nodos\n");
				}
				break;
            case 5:
            	if(excluiDoInicio(&lista, &dado)==LISTA_VAZIA){
					printf("Lista vazia\n");
				} else {
					printf("Codigo %d, Peso %f\n", dado.cod, dado.peso);
				}
				break;
            case 6:
            	printf("[Codigo][Peso]\n");
                 scanf (" %d %f", &dado.cod,&dado.peso);
                 if (incluiNoFim(&lista, dado)==SUCESSO)
                    printf("Operacao Realizada com Sucesso!\n");
                 else
                    printf("Operacao NAO realizada: Faltou Memoria!");
                 break;
            case 7:
            	if(excluiDoFim(&lista, &dado)==LISTA_VAZIA){
					printf("Lista vazia\n");
				} else {
					printf("Codigo %d, Peso %f\n", dado.cod, dado.peso);
				}
      			break;
      		case 8:
				printf("Digite o codigo de referencia:\n");
				scanf("%d", &cod);
				if(consultaPorCodigo(lista, cod, &dado)==SUCESSO){
					printf("Codigo %d, Peso %f", dado.cod, dado.peso);
				} else {
					printf("Codigo inexistente\n");
				}
				break;
      		case 9:
      			printf("[Codigo][Peso]\n");
                scanf (" %d %f", &dado.cod,&dado.peso);
                printf("Codigo de referencia:\n");
                scanf("%d", &cod);
                
                aux=incluiDepois(&lista, cod, dado);
                if(aux==FALTOU_MEMORIA){
                	printf("Faltou memoria\n");
				} else if(aux==CODIGO_INEXISTENTE){
					printf("Codigo inexistente\n");
				} else {
					printf("Sucesso\n");
				}
				break;
			case 10:
				printf("Digite um codigo:\n");
				scanf("%d", &cod);
				if(excluiNodo(&lista, cod, &dado)==CODIGO_INEXISTENTE){
					printf("Codigo inexistente\n");
				} else {
					printf("Codigo %d, Peso %f\n", &dado.cod, &dado.peso);
				}
    		exibe(lista);             
  			return(0);
  		}
	}while (op!=0);
}
