#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./headers/uteis.h"

// variaveis
int qtTotalUsers;

// arquivos


//assinaturas de funcoes
void action();
void controller(void);


// MAIN
int main(void){
    
   qtTotalUsers = qtUsers();
    action();
    clean();
    return 0;  
}

// corpo operacional das funcoes
void action(void){
    int islogin = login();

    if(islogin == 1){
        controller();
    }else{
        printf("\nErro no loguin =(\n");
    }
}

