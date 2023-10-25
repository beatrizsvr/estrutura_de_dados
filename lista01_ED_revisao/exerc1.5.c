/*
Escreva um programa em C para ler um inteiro Q (máximo 10). A seguir ler um vetor Z de Q elementos e
um valor Y. Copiar todos os elementos maiores que Y que estão no vetor Z para um vetor W (sem deixar
elementos vazios entre os valores copiados). Escrever o vetor W após o término cópia.
*/

#include <stdio.h>

main(){
	
	int i,q, vetor_z[10], y, vetor_w[10];
	
	//entrada de q
	printf("Digite o valor de Q:\n");
	scanf("%d", &q);
	
	if(q>10){
		printf("Digite um valor ate 10:\n");
		scanf("%d", &q);
	}
	
	//entrada de valores
	for(i=0;i<q;i++){
		printf("Digite o valor %d:\n", i+1);
		scanf("%d", &vetor_z[i]);
	}
	
	//entrada de y
	printf("Digite o valor de Y:\n");
	scanf("%d", &y);
	
	//loop de alocacao de valores do vetor z para vetor w
	for(i=0;i<q;i++){
		if(vetor_z[i]>y){
			vetor_w[i]=vetor_z[i];
		}
	}
	
	//impressao do vetor w
	for(i=0;i<y;i++){
		printf("%d\n", vetor_w[i]);
	}
}


