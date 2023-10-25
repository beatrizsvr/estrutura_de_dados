/*
Escreva um programa em C para ler a quantidade L de linhas (máximo 10) e a quantidade C de colunas
(máximo 10) de uma matriz. A seguir ler uma matriz L x C (considere que serão informados apenas valores
positivos). A seguir ler uma quantidade indeterminada de valores. Para cada valor escrever uma mensagem
indicando se ele está ou não armazenado na matriz. Para cada valor informado, a mensagem deve ser
impressa apenas uma vez. O programa termina ao ser informado um valor negativo.
*/

#include <stdio.h>

main(){
	
	int l,c,i,j,valor,f=0, matriz[10][10];
	
	//leitura das linhas
	do{
		
		printf("Digite o numero de linhas (maximo 10):\n");
		scanf("%d", &l);
		
		if(l>10){
			printf("Numero invalido! Digite o numero de linhas (maximo 10):\n");
		scanf("%d", &l);
		}
	} while (l<0 || l>10);
	
	//leituras das colunas
	do{
		printf("Digite o numero de colunas (maximo 10):\n");
		scanf("%d", &c);
		
		if(c>10){
			printf("Numero invalido! Digite o numero de colunas (maximo 10):\n");
		scanf("%d", &c);
		}
	} while (c<0 || c>10);
	
	//entrada de valores dos indices
	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
			printf("Digite o valor do indice %dx%d:\n", i, j);
			scanf("%d", &matriz[i][j]);
		}
	}
	
	//verifica se valor esta na matriz
	do{
		printf("Digite um valor:\n");
		scanf("%d", &valor);	
			
		for(i=0;i<l;i++){
			for(j=0;j<c;j++){
				if(valor==matriz[i][j]){
					f=1;
				}
			}
		}
		
		if(f=1){
			printf("O valor esta na matriz!\n");
		}else{
			printf("O valor nao esta na matriz!\n");
				}		
	}while(valor > 0);		
}
