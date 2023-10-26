/*
Escreva uma funçao em C chamada duplaCrescente que classifique 2 valores inteiros passados como
argumento em ordem crescente.
Entrada: Dois numeros inteiros
Saída: Os dois inteiros em ordem crescente.
Retorno: Nenhum
Escreva um programa em C para ler uma quantidade indeterminada de duplas de inteiros. Escrever cada dupla
em ordem crescente. Os valores em ordem crescente devem ser obtidos atraves da chamada a funçao
duplaCrescente. O programa termina quando os dois valores informados forem iguais (nesta situaçao os
valores nao devem ser impressos)
*/


#include <stdio.h>
#include <stdlib.h>

void duplaCrescente(int a, int b, int *c, int *d){
	if(a<b){
		*c=a;
		*d=b;
	}else{
		*d=a;
		*c=b;
	}
}

main(){
	
	int a, b, c, d;
	
	do{
		printf("Digite dois valores:\n ");
		scanf("%d %d", &a, &b);
		
		if(a!=b){
			duplaCrescente(a, b, &c, &d);
			printf("%d %d\n", c, d);
		}
	}while(a!=b);
	
	
}
