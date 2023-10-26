/*
Escreva uma funçao em C chamada calcDivisao que receba como entrada dois inteiros e retorne o valor
da divisao do primeiro pelo segundo. Retornar tambem um codigo de erro indicando se foi ou nao possível
calcular a divisao.
Entrada: Dois inteiros.
Saída: O resultado da divisao (float)
Retorno: 0 se foi possível executar a divisao e 1 caso o segundo parametro de entrada for igual a zero.
Escreva um programa em C para ler um valor N. A seguir ler N duplas de valores. Para cada dupla calcular e
escrever o resultado da divisao do primeiro valor pelo segundo. Utilizar a funçao calcDivisao para obter o
resultado. Caso a funçao retorne o codigo de erro igual a 1 deve ser impressa a mensagem “Divisao por zero”.
*/

#include <stdio.h>
#include <stdlib.h>

int calcDivisao(int a, int b, float *div){
	if(b==0){
		return 1;
	} else {
		*div=(float)a/b;
		return 0;
	}
}

main(){
	int i, n, v1, v2;
	float div;
	
	printf("Digite o valor de N: ");
	scanf("%d", &n);
	
	for(i=0;i<n;i++){
		printf("Digite 2 valores:\n");
		scanf("%d %d", &v1, &v2);
		
		if(calcDivisao(v1, v2, &div)==1){
			printf("Divisao por zero");
		} else {
			printf("%f", div);
		}
	}
	
}
