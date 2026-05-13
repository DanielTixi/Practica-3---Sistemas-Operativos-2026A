#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    // crear el proceso hijo
    pid = fork();

    if (pid < 0) {
        // Error de creacion del hijo 
        fprintf(stderr, "Error al bifurcar (fork failed)\n");
        return 1;
    } 
    else if (pid == 0) {
        // Estamos dentro del proceso hijo
        printf("Soy el proceso HIJO (PID: %d). Listando procesos:\n", getpid());
        // Usamos system para ejecutar el comando 'ps' que lista procesos
        system("ps -f");
    } 
    else {
        // Estamos dentro del proceso padre
        wait(NULL); // El padre espera que su hijo termine y lo informa
        printf("\nMi hijo ya terminó soy el Prceso Padre\n");
    }

    return 0;
}