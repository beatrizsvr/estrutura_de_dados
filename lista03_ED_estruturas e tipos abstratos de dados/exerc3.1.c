#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int hora, minuto, segundo;
} HORARIO;

main(){
	
	HORARIO hora1, hora2;
	
	printf("Digite a hora, o minuto e o segundo: ");
	scanf("%d %d %d", &hora1.hora, &hora1.minuto, &hora1.segundo);
	
	
	printf("Digite a hora, o minuto e o segundo: ");
	scanf("%d %d %d", &hora2.hora, &hora2.minuto, &hora2.segundo);
	
	if (hr1.hora > hr2.hora || hr1.minuto > hr2.minuto || hr1.segundos > hr2.segundos) {
	    printf("O menor horario eh: %d:%d:%d\n", hr2.hora, hr2.minuto, hr2.segundos);
	} else if (hr1.hora < hr2.hora || hr1.minuto < hr2.minuto || hr1.segundos < hr2.segundos) {
		printf("O menor horario eh: %d:%d:%d\n", hr1.hora, hr1.minuto, hr1.segundos);
	} else {
	    printf("Horarios iguais");
	}	
}
