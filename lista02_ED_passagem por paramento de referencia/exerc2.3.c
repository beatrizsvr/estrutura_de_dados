/*
Escreva uma funçao chamada duplaClassificada que classifique 2 valores inteiros conforme o codigo
passado como argumento (0-ordem crescente 1-ordem decrescente).
Entrada: Um codigo que identifica a ordem de classificaçao (0-ordem crescente 1-ordem decrescente).
Entrada: Dois valores inteiros.
Saída: Os 2 valores de entrada na ordem desejada
Retorno: Nenhum
Escreva um programa para ler uma quantidade indeterminada de duplas de valores. Escrever cada dupla em
ordem crescente se a soma dos elementos da dupla for par e em ordem decrescente se a soma for ímpar. Os
valores em ordem (conforme o caso) devem ser obtidos atraves da chamada a funçao duplaClassificada. O
programa termina quando os dois valores informados forem iguais (nesta situaçao os valores nao devem ser
impressos).
*/

#include <stdio.h>
#include <stdlib.h>

void duplaClassificada (int ordem, int a, int b, int *c, int *d){
	if(ordem==1){
		if(a>b){
			*c=a;
			*d=b;
		}else{
			*c=b;
			*d=a;
		}
	} else{
		if(a<b){
			*c=a;
			*d=b;
		}else{
			*c=b;
			*d=a;
		}
	}
}

main(){
	
	int ordem, a, b, c, d;
	
	while(a!=b){
		
		printf("Digite a ordem: 0.crescente 1.decrescente\n");
		scanf("%d", &ordem);
		
		printf("Digite 2 valores:\n");
		scanf("%d %d", &a, &b);
		
		if(a!=b){
			duplaClassificada(ordem, a, b, &c, &d);
			printf("%d %d", c,d);		
		}
	}
}


