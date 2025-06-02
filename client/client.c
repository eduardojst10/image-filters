#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h> 
#include "../utils/include/logger.h"
typedef struct{
    char* filtro;
    char* name_client;
    int nr_request;
    char* name_fifo;
    char* name_image;
    
} Request;



int main(char* args[], int argc){
    pid_t client_pid = getpid();
    if(argc < 3){
        logger("ERROR","Erro no input");
        exit(-1);
    }
    Request* req = malloc(sizeof(Request));

    req->filtro = strdup(argv[1]);
    req->name_image = strdup(argv[2]);
    
    while(true){

    }

    free(req);
    return 0;
}