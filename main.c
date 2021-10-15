#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// arquivos
FILE * file;

//variaveis globais
char users[100][64];
int qtUserTotal;
char atualUser[64];

//assinaturas de funcoes
void login(void);

void criarConta(void);

void clean(void);

void singUp(void);

void listUsers(void);

int qtUsers(void);

void addOneQtUsers(void);

int autentication(char *user);

// MAIN
int main(void){
    
    login();

    return 0;
}


// corpo operacional das funcoes
void login(void){
    clean();
    int option;
   
    printf("1 - Entrar\n");
    printf("2 - Criar uma nova conta\n");
    printf("0 - Sair\n");
    
    printf("\nBem vindo :), deseja Criar uma nova conta ou efetuar o entrar: ");
        scanf("%i",&option);
    
    switch (option){
    case 1:
        singUp();
        break;
    case 2:
        criarConta();
    default:
        break;
    }

}

void criarConta(void){
      clean();

      char urlBase[32] = "./database/users";

      char nick[64];

      printf("Digite seu login: ");
       scanf("%s",nick);
    
    file = fopen(urlBase, "a");

    if(file!=NULL){
        fprintf(file,"%s\n",nick);
    }

    fclose(file);
    addOneQtUsers();
    login();
}

void clean(void){
     system("cls");
}

void singUp(void){
    listUsers();
    qtUserTotal = qtUsers();
    clean();
   
    char user[64];
    printf("Digite seu Usuario: ");
     scanf("%s",&user);
    autentication(user);
    
}

void listUsers(void){
    char urlBase[32] = "./database/users";
    int i=0;
    file = fopen(urlBase, "r");

    char user[64];
    
    if(file != NULL){
        while (!feof(file)){
            fscanf(file, "%s", &user);
        
          strcpy(users[i],user);
       
            i++;
        }
    }
}

int qtUsers(void){
    char urlBase[32] = "./database/qtUsers";
    file = fopen(urlBase,"r");
    char qtUsers[3];
   
   if(file != NULL){
     while (!feof(file)){
        fscanf(file, "%s", &qtUsers);
     }
   }
    
    fclose(file);
    return atoi(qtUsers);
}

void addOneQtUsers(void){
    qtUserTotal = qtUsers();
    if(qtUserTotal==0){
        qtUserTotal = 1;
    }else{
        qtUserTotal++;
    }
    

    char urlBase[32] = "./database/qtUsers";

    file = fopen(urlBase,"w");
    
    if(file != NULL){
       fprintf(file,"%i",qtUserTotal);
    }
    fclose(file);
}

int autentication(char *user){
       
       for(int i=0;i<qtUserTotal;i++){
           if(strcmp(user, users[i]) == 0){
            printf("Este user e valido");
            return 0;
           }
       }

       printf("Nenhum usuario encontrado");
}