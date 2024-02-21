
#include <stdio.h>
#include <stdlib.h>
#include "listade.h"

int main()
{
    int op,cod,peso,n, aux;
    LISTADE lista;
    DADO dado;
    
    criaLista(&lista);

    do {
      printf("\n0. Fim                         5. Exclui do Inicio         10. Exclui Nodo\n");    
      printf("1. Inclui no Inicio            6. Inclui no Fim            11. Grava em Arquivo de Texto\n");    
      printf("2. Exibe Lista                 7. Exclui do Fim            12. Le em Arquivo de Texto\n");    
      printf("3. Quantidade de Nodos         8. Consulta por Codigo      \n");    
      printf("4. Exibe Situacao da Lista     9. Inclui Depois      \n");
      printf("Operacao: ");    
      scanf("%d", &op);

      switch(op){
            case 1:
                 printf("[cod][peso]\n");
                 scanf ("%d %f", &dado.cod,&dado.peso);
                 if (incluiNoInicio(&lista, dado)==0)
                    printf("Operacao realizada com Sucesso!\n");
                 else
                    printf("Operacao NAO realizada: faltou memoria!");
                 break;
            case 3:
            	printf("Quantidade de nodos: %d", quantidadeDeNodos(lista));
          		break;
          	case 4:
          		if(estaVazia(lista)==1){
          			printf("Lista vazia\n");
				  } else {
				  	printf("A lista possui 1 ou mais nodos\n");
				  }
				break;
          	case 5:
          		if(excluiDoInicio(&lista, &dado)==LISTA_VAZIA){
          			printf("Lista vazia\n");
				}else{
					printf("Dados excluidos com sucesso! Cod: %d Peso: %f\n", dado.cod, dado.peso);
				} 
          		break;
          	case 6:
          		printf("[cod][peso]\n");
                scanf ("%d %f", &dado.cod,&dado.peso);
                if(incluiNoFim(&lista, dado)==SUCESSO){
                	printf("Dados incluidos com sucesso!\n");
				}else{
					printf("Faltou memoria!\n");
				}
      			break;
      		case 7:
      			if(excluiDoFim(&lista, &dado)==LISTA_VAZIA){
          			printf("Lista vazia\n");
				}else{
					printf("Dados excluidos com sucesso! Cod: %d Peso: %f\n", dado.cod, dado.peso);
				} 
          		break;
          	case 8:
          		printf("Informe o codigo de referencia:\n");
          		scanf("%d", &cod);
          		if(consultaPorCodigo(lista, cod, &dado)==SUCESSO){
          			printf("Dados encontrados com sucesso! Cod: %d Peso: %f\n", dado.cod, dado.peso);
				} else {
					printf("Codigo inexistente\n");
				}
          		break;
          	case 9:
          		printf("Informe o codigo de referencia:\n");
          		scanf("%d", &cod);
          		printf("[cod][peso]\n");
                scanf ("%d %f", &dado.cod,&dado.peso);
                aux = incluiDepois(&lista, cod, dado);
          		if(aux==SUCESSO){
          			printf("Dados incluidos com sucesso!\n");
				} else if(aux==CODIGO_INEXISTENTE){
					printf("Codigo inexistente\n");
				} else {
					printf("Faltou memoria\n");
				}
          		break;
          	case 10:
          		printf("Informe o codigo de referencia:\n");
          		scanf("%d", &cod);
          		if(excluiNodo(&lista, cod, &dado)==SUCESSO){
          			printf("Dados excluidos com sucesso! Cod: %d Peso: %f\n", dado.cod, dado.peso);	
				} else {
					printf("Codigo inexistente");
				}
          		break;
	  }
      exibe(lista);            
    } while (op!=0);  

  return(0);
}
