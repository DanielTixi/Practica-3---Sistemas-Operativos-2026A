#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid;
    
    char *programa = "date";
    char *args[] = {"date", NULL}; 

    printf("Padre: Iniciando el programa\n");

    pid = fork(); // Se crea el hijo

    if (pid == -1) {
        perror("Error al crear el proceso");
        exit(1);
    } 
    else if (pid == 0) {
        printf("---Tarea del Hijo---\n");
        printf("Voy a consultar la fecha, me voy a transformar en date\n");
        fflush(stdout); 

        // El hijo se transforma en 'date'
        execvp(programa, args);
	//Si ocurre algun problema:
        perror("Error al ejecutar el comando date");
        exit(1);

    }else {
        // Padre:
        printf("Padre: He creado un hijo con PID %d y estoy esperando\n", pid);
        
        wait(NULL); 
        
        printf("Padre: El hijo terminó, ahora puedo cerrar.\n");
    }

    return 0;
}
