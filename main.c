#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE * file;

void loguin(void);

void criarConta(void);

void clean(void);

int main(void){
    
    loguin();

    return 0;
}

void loguin(void){
    int option;
    
    printf("1 - Entrar\n");
    printf("2 - Criar uma nova conta\n");
    printf("0 - Sair\n");
    
    printf("\nBem vindo :), deseja Criar uma nova conta ou efetuar o entrar: ");
        scanf("%i",&option);
    
    switch (option)
    {
    case 1:
        /* code */
        break;
    case 2:
        criarConta();
    default:
        break;
    }

}

void criarConta(void){
      clean();

      char nick[64];
      printf("Digite seu loguin: ");
       scanf("%s",nick);
      
       printf("%s ",nick);
}

void clean(void){
     system("cls");
}