/*
Escreva as seguintes fun��es em C:
Nome: exibeOnzeTracos
Descri��o: Exibe na tela uma linha com 11 hifens (�-�). Utilizar uma repeti��o.
Nome: retanguloTracos
Descri��o: Exibe na tela um ret�ngulo com 4 linhas (usar repeti��o) de 11 hifens. Cada linha com 11 hifens
deve ser impressa com a chamada da fun��o exibeOnzeTracos descrita anteriormente.
Escreva um programa em C para exibir na tela 2 ret�ngulos com uma linha em branco entre eles. Cada
ret�ngulo deve ser mostrado a partir de uma chamada a fun��o retanguloTracos.
*/

#include <stdio.h>


void exibeOnzeTracos();
void retanguloTracos();


main(){	
	int i;
	
	//impressao dos tracos
	for(i=0;i<2;i++){
		retanguloTracos();
		printf("\n");
	}
}

//funcao que gera o numero de tracos
void exibeOnzeTracos(){
	int i;
	for(i=0;i<11;i++){
		printf("-");
	}
}
//funcao que gera a quantidade de linhas
void retanguloTracos(){
	int i;
	for(i=0;i<4;i++){
		exibeOnzeTracos();
		printf("\n");
	}
}
