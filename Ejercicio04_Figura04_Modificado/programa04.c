#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define NUM_PROC 3

int main() {
    int i, pid;

    for (i = 1; i <= NUM_PROC; i++) {
        pid = fork();

        if (pid == -1) {
            fprintf(stderr, "Error al crear el proceso\n");
            exit(1);
        } 
        
        if (pid == 0) { // Lógica exclusiva de los hijos
	    printf("------------------- [Proceso Hijo %d] -----------------\n", i);
	    printf("PID: %d\n", getpid()); 
            switch(i) {
                case 1:
		    printf("Hijo 1: \n");
                    printf("Calculando la suma de los primeros 15 numeros\n");
                    int suma = 0;
                    for(int j=1; j<=15; j++) suma += j;
                    printf("Resultado [Hijo 1]: %d\n", suma);
                    break;
                    
                case 2:
		    printf("Hijo 2: \n");
                    printf("Mostrar potencias de 5: \n");
		    int p = 1;
		    for(int j=1; j<=5; j++){
		    p  *= 5;
		    printf("  %d",p);
		    }
                    printf("\n");
                    printf(" ");
                   break;

                case 3:
                    printf("Hijo 3: \n");
		    printf("Mostrar documentos que hay en esta carpeta: \n");
		    printf("\n");
		    system("ls -l");
		    printf("\n");
                    break;
            }
            exit(0); // El hijo termina aquí para no seguir en el bucle del padre
        }
    }

    // El padre espera a que los 3 hijos terminen
    for (i = 1; i <= NUM_PROC; i++) {
        wait(NULL);
    }
    
    printf("[Proceso Padre]: Todos mis hijos han terminado.\n Finalizando programa.\n");
    return 0;
}
