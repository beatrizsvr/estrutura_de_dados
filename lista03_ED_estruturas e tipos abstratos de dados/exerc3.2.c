#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int dia, mes, ano;
} DATA;

typedef struct {
	int matricula; DATA dtanasc;
} ALUNO;

main(){
	ALUNO aluno;
	DATA hoje;
	
	printf("Digite a data de hoje: ");
	scanf("%d %d %d", &hoje.dia, &hoje.mes, &hoje.ano);
	
	do{
		printf("Digite a matricula: ");
		scanf("%d", &aluno.matricula);
		
		if(aluno.matricula>=0){
			printf("Digite a data de nascimento: ");
			scanf("%d %d %d", &aluno.dtanasc.dia, &aluno.dtanasc.mes, &aluno.dtanasc.ano);
		
			if (aluno.dtNasc.ano <= (dtHoje.ano - 18)) {
            	printf("Aluno maior de 18 anos.\n");
			} else {
				printf("Nao completou 18 anos\n");
			}
		}		
	} while(aluno.matricula>=0);	
}
