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

void model(void);

// MAIN
int main(void){
    
   qtTotalUsers = qtUsers();
   //action();

   model();
   
   // clean();
    return 0;  
}

// corpo operacional das funcoes
void action(void){
    int islogin = login();

    if(islogin == 1){
        controller();
    }else{
        printf("Erro no loguin :(\n");
    }
}

void controller(void){
    clean();
    int option;
    printf("1 - Colocar uma disponibilidade\n");
    printf("2 - Ver lista de disponibilidade por hora\n");
    printf("3 - Ver lista de disponibilidade por jogo\n");
    printf("0 - sair\n");
    printf("O que deseja fazer: ");
        scanf("%i",&option);
    
    switch (option)
    {
    case 1:
        model();
        break;
    case 2:
    
        break;
    case 3:

        break;
    default:
        break;
    }

}

void model(void){
    char months[] = "Gabriel,10:00,PUBG";
    char** tokens;

    tokens = str_split(months, ',');

    if (tokens)
    {
        int i;
        int qt;

        char user[qt][64];

        for (i = 0; *(tokens + i); i++)
        {
             printf("%s\n",  *(tokens + i));
            free(*(tokens + i));
        }
       
       
        free(tokens);
    }
}