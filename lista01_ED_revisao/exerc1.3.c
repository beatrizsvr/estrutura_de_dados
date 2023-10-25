/*
Escreva uma função chamada exibeDivisores que exiba na tela os divisores do inteiro passado com
argumento.
Escreva um programa em C para imprimir os números de 1 a 20 com seus respectivos divisores. Cada
conjunto de divisores deve ser impresso com a função exibeDivisores. A saída deve ser impressa conforme o
formato abaixo
*/

#include <stdio.h>

int exibeDivisores(int a);

main(){
	
	int numero, i;
	
	//loop que chama a funcao
	for(i=1;i<21;i++){
		exibeDivisores(i);
		printf("\n");
	}
}
//funcao que gera os valores
int exibeDivisores(int a){
	int i;
	
	printf("%d: ", a);
	
	for(i = 1; i <= a; i++){
		if(a % i == 0){
			printf("%d ", i);
		}
	}
}
