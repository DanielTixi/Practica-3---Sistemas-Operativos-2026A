#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	int pid, i;
	int var = 0; //Variable que modificara el padre

	pid = fork(); //Clonacion del proceso

	switch(pid){
		case -1:
			return 1;

		case  0:

			//El hijo abre el archivo en modo escritura y registra los datos
			printf("[HIJO] Escribiendo archivo...\n");
			FILE *f = fopen("valores.txt", "w");
			for(i=1; i<=10; i++){
			fprintf(f, "Registro %d: valor = %d\n", i, i * 10);
	}

			fclose(f);
			break;

	default:
		//El Padre incrementa la variable de 10 en 10
		printf("[PADRE] Incrementando variable...\n");
		for(i = 1; i <= 10; i++){
		var += 10;
		printf("Ciclo %d: Var = %d\n", i, var);
	}

		// wait al final para no bloquear al padre antes
		wait(0);
		break;

	}
	return 0;
} 


