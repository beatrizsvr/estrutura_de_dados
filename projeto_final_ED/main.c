#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "listade.h"

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	int a,b,c,d,aux,f=0;
	DADO dado;
	LISTADE produtos, carrinho;
	criaLista(&produtos);
	lerArquivo(&produtos);
	criaLista(&carrinho);
	
	printf("+----------------------------------------+");
	printf("\n|  Bem-vindo/a a Papelaria Dream Paper!  |");
	printf("\n+----------------------------------------+\n");
	system("pause");
	system("cls");
	
	for(a=3; a!=0;){
   		printf("+---------- MENU -----------+");
   		printf("\n|  0. Sair                  |");
		printf("\n|  1. Entrar como cliente   |");
		printf("\n|  2. Entrar como lojista   |\n");
   		printf("+---------------------------+\n");
   		scanf("%d", &a);
   		system("pause");
		system("cls");
   		
   		if(a==1){
   			for(b=4; b!= 0;){
   				printf("+----- MENU DE COMPRAS -----+\n");
   				printf("| 0. Sair                   |\n");
   				printf("| 1. Adicionar no carrinho  |\n");
   				printf("| 2. Excluir do carrinho    |\n");
   				printf("| 3. Exibir carrinho        |\n");
   				printf("| 4. Efetuar pagamento      |\n");
   				printf("+---------------------------+\n");
   				scanf("%d", &b);
   				
   				if(b==1){
   					for(d=0; d!=1;){
   						printf("Exibindo produtos da loja:\n");
   						exibe(produtos);
						printf("Digite o código do produto que deseja adicionar ao carrinho:\n");
						scanf("%d", &aux);
						if(consultaPorCodigo(produtos, aux, &dado)==CODIGO_INEXISTENTE){
							printf("Código inexistente!\n");
							printf("Deseja finalizar a operação? 1.Sim 2.Não\n");
							scanf("%d", &d);
							
						}else{
							if(incluiNoFim(&carrinho, dado)==FALTOU_MEMORIA){
								printf("Faltou memória!\n");
							} else{
								printf("Produto adicionado com sucesso!\n");
								d=1;
							}	
						}	
					}
				} else if(b==2){
					for(d=0; d!=1;){
						printf("Digite o código do produto que deseja excluir:\n");
						scanf("%d", &aux);
						if(excluiNodo(&carrinho, aux, &dado)==CODIGO_INEXISTENTE){
							printf("Código inexistente!\n");
							printf("Deseja finalizar a operação? 1.Sim 2.Não\n");
							scanf("%d", &d);
						} else {
							printf("Produto excluído com sucesso!\n");
							printf("Código: %d, Nome: %s, Preço: R$%.2f\n", dado.cod, dado.nome, dado.preco);
							d=1;
						}
					}
				} else if(b==4){
					printf("Exibindo carrinho:\n");
					exibe(carrinho);
					printf("Total: R$%.2f\n", valorTotal(carrinho));
					printf("Desejar efetuar o pagamento? 1. Sim 2. Não\n");
					scanf("%d", &aux);
					
					if(aux==1){
						for(d=0;d<=carrinho.n;d++){
							excluiDoFim(&carrinho, &dado);
						}
						printf("Pagamento realizado com sucesso!\n");
					}
				}
				printf("Exibindo carrinho:\n");
				exibe(carrinho);
				printf("Total: R$%.2f\n", valorTotal(carrinho));
				system("pause");
				system("cls");
			}
		}else if(a==2){
			for(c=5; c!=0; ){
				printf("+---- MENU DO LOJISTA ----+\n");
				printf("| 0. Sair                 |\n");
				printf("| 1. Adicionar produto    |\n");
				printf("| 2. Excluir produto      |\n");
				printf("| 3. Mostrar produtos     |\n");
				printf("| 4. Gravar alterações    |\n");
				printf("+-------------------------+\n");
				scanf("%d", &c);
	
				if(c==1){
					printf("Digite codigo do produto: \n");
					scanf("%d", &dado.cod);
					printf("Digite nome do produto:\n");
					scanf("%c");
					gets(dado.nome);
					printf("Digite preço do produto: \n");
					scanf("%f", &dado.preco);
					if(incluiNoFim(&produtos,dado)==FALTOU_MEMORIA){
						printf("Faltou memória!\n");
					} else {
						printf("Produto incluído com sucesso!\n");
					}
				}else if(c==2){
					exibe(produtos);
					printf("Digite o código do produto que deseja excluir:\n");
					scanf("%d", &aux);
					if(excluiNodo(&produtos, aux, &dado)==CODIGO_INEXISTENTE){
						printf("Código inexistente!\n");
					} else {
						printf("Produto excluído com sucesso!\n");
						printf("Código: %d, Nome: %s, Preço: R$%.2f\n", dado.cod, dado.nome, dado.preco);
					}
				} else if(c==4 || c==0){
					printf("Deseja gravar as alterações?\n1. Sim 2. Não\n");
					scanf("%d", &aux);
					if(aux==1){
						gravaArquivo(produtos);
					}
				}
				printf("Exibindo os produtos da loja\n");
				exibe(produtos);
				system("pause");
				system("cls");
			}
		}
	}
	return(0);
}
