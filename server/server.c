#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <fcntl.h>
#include <string.h> 
#include <stdlib.h>
#include "../utils/include/logger.h"
#define FIFO_PATH "/tmp/fifo_server"
#define BUF_SIZE 256


int main(){
    pid_t pid;
    int status;
    
    if(access(FIFO_PATH,0) ==-1){
        if(mkfifo(FIFO_PATH,0666) == -1){
            logger("ERROR","Erro a criar FIFO");
            exit(1);
        }
        logger("INFO","[SERVIDOR] FIFO criado");
    }else{
        logger("INFO","[SERVIDOR] FIFO a escutar");
    }

    char buffer[BUF_SIZE];

    while(true){
        int fifo_fd = open(FIFO_PATH, O_RDONLY);
        if (fifo_fd == -1) {
            logger("ERROR","Erro a abrir FIFO");
            continue;
        }

        ssize_t bytes_read = read(fifo_fd,buffer,BUF_SIZE-1);
        if(bytes_read > 0){
            buffer[bytes_read] = '\0';
            logger_detail("INFO", "[SERVIDOR] Pedido recebido: %s", buffer );
            //printf("[SERVIDOR] Pedido recebido: %s\n", buffer);
        }

        close(fifo_fd);
    }
    
    /*
    for(int i=1 ; i<11; i++){
        if((pid = fork()) == 0){         
         pid_t Pid_filho = getpid();    
         pid_t Pid_pai = getppid();
	     printf("[FILHO] pid= %d  -> [PAI] pid= %d\n",Pid_filho,Pid_pai);
         sleep(2); //adormece o processo
         _exit(i); //vai terminar o programa i

        }else{
            pid_t pid_terminates = wait(&status);//vai esperar pelo filho i
            printf("----[PAI] process %d exited. exit code: %d----\n",pid_terminates,WEXITSTATUS(status));
        }
    }
    */

    return 0;
}

