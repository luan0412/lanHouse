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

void  printTableScheduled(void);

void headTable(int maiorName);

// MAIN
int main(void){
    
   qtTotalUsers = qtUsers();
    action();

    printTableScheduled();
   
    clean();
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
    printf("0 - sair\n");
    printf("O que deseja fazer: ");
        scanf("%i",&option);
    
    switch (option)
    {
    case 1:
        break;
    case 2:
        printTableScheduled();
        break;
    default:
        break;
    }

}

void printTableScheduled(void){
    clean();
    FILE *arq;
    char url[] = "./database/agendados.txt";
    
    arq = fopen(url, "r");

    char a[64];
    char b[64];
    char c[64];

    char pessoas[10][3][64];
    int i=0;
    int qtPessoas=0;
    int maiorName=0;
    while(!feof(arq)){
        fscanf(arq, "%s", &a);
        fscanf(arq, "%s", &b);
        fscanf(arq, "%s", &c);
        
        strcpy(pessoas[i][0],a);
        strcpy(pessoas[i][1], b);
        strcpy(pessoas[i][2], c);
    
        //printf("\n|     %s      %s       %s", pessoas[i][0], pessoas[i][1], pessoas[i][2]);
        
        i++;
    } 

    fclose(arq);

    for ( int j = 0; j<i; j++)
    {
        if(maiorName<strlen(pessoas[j][0])){
            maiorName = strlen(pessoas[j][0]);
            
        }
    }
    
    printf("%i\n\n",maiorName);
    qtPessoas = i;
    if(maiorName%i != 0){
        maiorName++;
    }

    headTable(maiorName);
    printf("\n");

    //Body Table
    for(int i=0;i<qtPessoas-1;i++){
        
        printf("|");
        
        for(int j=0;j<3;j++){
            int tamString = strlen(pessoas[i][j]);
            
            int space = ((maiorName+2) - tamString)/2;

            printSpace(space);
            printf("%s",pessoas[i][j]);
            
             if(tamString%2!=0){
                 printSpace(space+1);
             }
             else{
                 printSpace(space);
             }

        }
        
        printf("\n");
    }

    printf("\n\n");
}

void headTable(int maiorName){
    int space;
    
    space = ((maiorName+2) - 4)/2;
   
    printf("\n======= Agendados ======\n");
    printf("|");
     printSpace(space);
      printf("Nick");
       printSpace(space);

    printf("|");
     printSpace(space);
      printf("Hora");
       printSpace(space);
     
    printf("| ");
      printSpace(space);
       printf("Jogo");
        printSpace(space-1);
   


    printf("\n");

    for(int i=0;i<3;i++){
        printf("|",maiorName);        
        for(int j=0;j<maiorName+1;j++){
            printf("-");
        }

        if(maiorName%2==0){
            printf("-");
        }
    }

}