/*
Escreva uma funçao em C chamada classificaCrescente que classifique 2 valores inteiros passados como
argumento em ordem crescente.
Entrada/Saída: Dois numeros inteiros
Saída: Nenhuma
Retorno: Nenhum
Reescreva o programa principal do exercício 2.1 utilizando a funçao classificaCrescente para obter os valores
classificados.
*/
#include <stdio.h>
#include <stdlib.h>

void classificaCrescente(int *a, int *b){
	int aux;
	if(*a>*b){
		aux= *a;
		*a=*b;
		*b=aux;
	}
}

main(){
	int c, d;
	
	while(c!=d){
		printf("Digite 2 valores:\n");
		scanf("%d %d", &c, &d);
		
		if(c!=d){
			classificaCrescente(&c, &d);
			printf("%d %d\n", c, d);
			
		}
	}
}
