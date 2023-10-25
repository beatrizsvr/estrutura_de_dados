/*
Escreva um programa em C para ler um valor Q que representa a quantidade de alunos de uma turma. A
seguir ler Q pares de dados contendo, cada um, a altura e um código para masculino (1) e outro para
feminino (2) de cada aluno. Calcular e escrever:
-A altura do aluno mais alto da turma.
-A média de altura das alunas.
*/

#include <stdio.h>

main(){
	
	int q, genero, i;
	float altura, cont=0, somaAlturas=0, maisAlto=0, mediaAlturas;
	
	//entrada valor de Q
	printf("Digite o valor de Q: ");
	scanf("%d", &q);
	
	//entrada de genero e altura
	for(i=0;i<q;i++){
		printf("Digite o genero 1.Masculino 2.Feminino:\n");
		scanf("%d", &genero);	
				
		printf("Digite a altura: ");
		scanf("%f", &altura);	
		
		//condicoes
		if(genero==2){
			somaAlturas = somaAlturas + altura;
		}else{
			if(altura>maisAlto){
			maisAlto = altura;
			}
		}	
		
	}
	
	//impressao dos resultados
	printf("A altura do mais alto e %.2f\n", maisAlto);
	printf("A soma da altura das mulheres e: %.2f\n", somaAlturas);
}

