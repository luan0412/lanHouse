#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "uteis.h"

FILE * file;

int qtUserTotal;

char users[100][64];

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

int singUp(void){
    listUsers();
    qtUserTotal = qtUsers();
    clean();
   
    char user[64];
    printf("Digite seu Usuario: ");
     scanf("%s",&user);
    return autentication(user);
    
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

int login(void){
    clean();
    int option;
    int valid;
    printf("1 - Entrar\n");
    printf("2 - Criar uma nova conta\n");
    printf("0 - Sair\n");
    
    printf("\nBem vindo :), deseja Criar uma nova conta ou efetuar o entrar: ");
        scanf("%i",&option);
    
    switch (option){
    case 1:
        valid = singUp();
        break;
    case 2:
        criarConta();
    default:
        break;
    }
    return valid;
}

int autentication(char *user){
       
       for(int i=0;i<qtUserTotal;i++){
           if(strcmp(user, users[i]) == 0){
            printf("Este user e valido");
            return 1;
           }
       }

       printf("Nenhum usuario encontrado");
       return 0;
}

char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    count += last_comma < (a_str + strlen(a_str) - 1);

    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}