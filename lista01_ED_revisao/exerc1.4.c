/*
Escreva uma função chamada maiorNumero que receba como entrada dois inteiros positivos e retorne o
maior deles ou o valor -1 se eles forem iguais. Considere que os valores de entrada são sempre positivos (não
é necessário validar).
Escreva um programa em C para ler um valor N. A seguir ler N duplas de inteiros (considere que serão
informado apenas valores positivos). Para cada dupla informada exibir o maior elemento ou a frase “Eles são
iguais”. Para obter o maior elemento deve ser utilizada a função maiorNumero
*/

#include <stdio.h>

int maiorNumero(int num_1, int num_2);

main(){
	int n, num_1, num_2, i, aux;
	
	//entrada de n
	printf("Digite o valor de N:\n");
	scanf("%d", &n);
	
	//entrada das duplas de valores
	for(i=0;i<n;i++){
		printf("Digite o primeiro numero:\n");
		scanf("%d", &num_1);
		
		printf("Digite o segundo numero:\n");
		scanf("%d", &num_2);
		
		aux = maiorNumero(num_1,num_2);
		
		//verifica retorno da funcao
		if(aux==-1){
			printf("Eles sao iguais\n");
		}else if(aux==num_1){
			printf("Numero maior e: %d\n", num_1);
		} else {
			printf("Numero maior e: %d\n", num_2); 
		}
	}
}

//funcao que retorna valores
int maiorNumero(int num_1, int num_2){
	
	if(num_1 == num_2){
		return -1;
	} else if(num_1>num_2){
		return num_1;
	} else {
		return num_2;
	}
}
