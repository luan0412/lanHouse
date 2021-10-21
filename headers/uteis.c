#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "uteis.h"

FILE *file;

int qtUserTotal;

char users[100][64];

void criarConta(void)
{
    clean();

    char urlBase[32] = "./database/users";

    char nick[64];

    printf("Digite seu login: ");
    scanf("%s", nick);

    file = fopen(urlBase, "a");

    if (file != NULL)
    {
        fprintf(file, "%s\n", nick);
    }

    fclose(file);
    addOneQtUsers();
    login();
}

void clean(void)
{
    system("cls");
}

int singUp(void)
{
    listUsers();
    qtUserTotal = qtUsers();
    clean();

    char user[64];
    printf("Digite seu Usuario: ");
    scanf("%s", &user);
    int response = autentication(user);

    if (response == 1)
    {
        setAtualUser(user);
        return response;
    }
    else
    {
        return response;
    }
}

void listUsers(void)
{
    char urlBase[32] = "./database/users";
    int i = 0;
    file = fopen(urlBase, "r");

    char user[64];

    if (file != NULL)
    {
        while (!feof(file))
        {
            fscanf(file, "%s", &user);

            strcpy(users[i], user);

            i++;
        }
    }
}

int qtUsers(void)
{
    char urlBase[32] = "./database/qtUsers";
    file = fopen(urlBase, "r");
    char qtUsers[3];

    if (file != NULL)
    {
        while (!feof(file))
        {
            fscanf(file, "%s", &qtUsers);
        }
    }

    fclose(file);
    return atoi(qtUsers);
}

void addOneQtUsers(void)
{
    qtUserTotal = qtUsers();

    if (qtUserTotal == 0)
    {
        qtUserTotal = 1;
    }
    else
    {
        qtUserTotal++;
    }

    char urlBase[32] = "./database/qtUsers";

    file = fopen(urlBase, "w");

    if (file != NULL)
    {
        fprintf(file, "%i", qtUserTotal);
    }
    fclose(file);
}

int login(void)
{
    clean();
    int option;
    int valid;
    
    printf("1 - Entrar\n");
    printf("2 - Criar uma nova conta\n");
    printf("0 - Sair\n");

    printf("\nBem vindo :), deseja Criar uma nova conta ou efetuar o entrar: ");
    scanf("%i", &option);

    switch (option)
    {
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

int autentication(char *user)
{

    for (int i = 0; i < qtUserTotal; i++)
    {
        if (strcmp(user, users[i]) == 0)
        {
            printf("Este user e valido");
            return 1;
        }
    }

    printf("Nenhum usuario encontrado");
    return 0;
}

void printSpace(int qt)
{
    for (int i = 0; i < qt; i++)
    {
        printf(" ");
    }
}

void printTableScheduled(void)
{
    clean();
    FILE *arq;
    char url[] = "./database/agendados.txt";

    arq = fopen(url, "r");

    char a[64];
    char b[64];
    char c[64];

    char pessoas[10][3][64];
    int i = 0;
    int qtPessoas = 0;
    int maiorName = 0;
    while (!feof(arq))
    {
        fscanf(arq, "%s", &a);
        fscanf(arq, "%s", &b);
        fscanf(arq, "%s", &c);

        strcpy(pessoas[i][0], a);
        strcpy(pessoas[i][1], b);
        strcpy(pessoas[i][2], c);

        //printf("\n|     %s      %s       %s", pessoas[i][0], pessoas[i][1], pessoas[i][2]);

        i++;
    }

    fclose(arq);

    for (int j = 0; j < i; j++)
    {
        if (maiorName < strlen(pessoas[j][0]))
        {
            maiorName = strlen(pessoas[j][0]);
        }
    }

    qtPessoas = i;

    if (maiorName % i != 0)
    {
        maiorName++;
    }

    headTable(maiorName);
    printf("\n");

    //Body Table
    for (int i = 0; i < qtPessoas - 1; i++)
    {

        printf("|");

        for (int j = 0; j < 3; j++)
        {
            int tamString = strlen(pessoas[i][j]);

            int space = ((maiorName + 2) - tamString) / 2;

            printSpace(space);
            printf("%s", pessoas[i][j]);
            printSpace(space);
        }

        printf("\n");
    }

    printf("\n\n");

    int option;
    printf("======= Sub-Menu =======\n");
    printf("1 - Menu Principal\n");
    printf("2 - Rever Lista\n");
    printf("Qual opcao voce deseja escolher: ");
    scanf("%i", &option);

    switch (option)
    {
    case 1:
        controller();
        break;
    case 2:
        printTableScheduled();
    default:
        break;
    }
}

void headTable(int maiorName)
{
    int space;

    space = ((maiorName + 2) - 4) / 2;

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
    printSpace(space - 1);

    printf("\n");

    for (int i = 0; i < 3; i++)
    {
        printf("|", maiorName);
        for (int j = 0; j < maiorName + 1; j++)
        {
            printf("-");
        }

        if (maiorName % 2 == 0)
        {
            printf("-");
        }
    }
}

void controller(void)
{
    clean();
    int option;
    printf("====================== Menu Principal ======================\n");
    printf("1 - Colocar uma disponibilidade\n");
    printf("2 - Ver lista de disponibilidade por hora\n");
    printf("3 - Marcar com alguem\n");
    printf("4 - Ver Agenda\n");
    printf("0 - sair\n");
    printf("O que deseja fazer: ");
    scanf("%i", &option);

    switch (option)
    {
    case 1:
        addDisponibilidade();
        break;
    case 2:
        printTableScheduled();
        break;
    case 3:
        marcar();
        break;
    case 4:
        verAgenda();
    default:
        break;
    }
}

void setAtualUser(char *user)
{
    char urlBase[32] = "./database/atualUser";
    file = fopen(urlBase, "w");

    if (file != NULL)
    {
        printf("\n %s\n", user);
        fprintf(file, "%s", user);
    }

    fclose(file);
}

void addDisponibilidade(void)
{
    clean();
    char text[64];

    FILE *file;
    char urlBase[32] = "./database/agendados.txt";

    file = fopen(urlBase, "a");

    if (file != NULL)
    {
        printf("Digite seu nome: ");
        scanf("%s", &text);
        fprintf(file, "%s ", text);
        printf("Digite seu horario(HH:MM): ");
        scanf("%s", &text);
        fprintf(file, "%s ", text);
        printf("Digite seu nome do jogo sem espaco: ");
        scanf("%s", &text);
        fprintf(file, "%s\n", text);
    }
    fclose(file);

    controller();
}

void marcar(void)
{
    clean();
    listUsers();
    int usersQt = qtUsers();

    char text[64];
    char horario[6];
    printf("Digite o nome: ");
    scanf("%s", &text);

    for (int i = 0; i < 5; i++)
    {
        if (strcmp(text, users[i]) == 0)
        {
            printf("Digite o horario: ");
            scanf("%s", &horario);
            printf("%s\n", horario);

            int returnValid = isValidParametrs(text, horario);
            
            if(returnValid==1){
                printf("Marcado!!!\n");
                break;
            }else{
                printf("Infelizmente nao foi encontrado nessa lista =(\n");
                break;
            }
            
        }
       
    }
     controller();
}

int isValidParametrs(char *nome, char *hora)
{

    FILE *arq;
    char url[] = "./database/agendados.txt";

    arq = fopen(url, "r");

    char a[64];
    char b[64];
    char c[64];

    char pessoas[10][3][64];
    int i = 0;
    int qtPessoas = 0;

    if (arq != NULL)
    {
        while (!feof(arq))
        {
            fscanf(arq, "%s", &a);
            fscanf(arq, "%s", &b);
            fscanf(arq, "%s", &c);

            strcpy(pessoas[i][0], a);
            strcpy(pessoas[i][1], b);
            strcpy(pessoas[i][2], c);

            if (strcmp(nome, a) == 0 && strcmp(hora, b) == 0)
            {
                fclose(arq);
                char nick[64];
                printf("Digite seu nick para confirmar: ");
                scanf("%s", nick);
                
                FILE *arq;
                char url[] = "./database/agenda.txt";
                arq = fopen(url, "a");
                fprintf(arq,"%s ",nick);
                fprintf(arq,"%s ",nome);
                fprintf(arq,"%s \n",hora);
                fclose(arq);
                return 1;
            }
            else
            {
                fclose(arq);
                return 0;
            }
            i++;
            printf("kkk\n");
        }
    }
    else
    {
        printf("Arquivo não encontrado =(\n");
    }

    fclose(arq);
}

void verAgenda(void)
{
    char nick[64];
    printf("Digite seu nick: ");
     scanf("%s",&nick);
    
     clean();
    FILE *arq;
    char url[] = "./database/agenda.txt";

    arq = fopen(url, "r");

    char a[64];
    char b[64];
    char c[64];

    char pessoas[10][3][64];
    int i = 0;
    int qtPessoas = 0;
    int maiorName = 0;
    while (!feof(arq)){
        fscanf(arq, "%s", &a);
        fscanf(arq, "%s", &b);
        fscanf(arq, "%s", &c);
        
        if(strcmp(nick, b)==0){
        strcpy(pessoas[i][0], a);
        strcpy(pessoas[i][1], c);
        }
        i++;
    }

    fclose(arq);

    for (int j = 0; j < i; j++)
    {
        if (maiorName < strlen(pessoas[j][0]))
        {
            maiorName = strlen(pessoas[j][0]);
        }
    }

    qtPessoas = i;

    if (maiorName % i != 0)
    {
        maiorName++;
    }

    headTable(maiorName);
    printf("\n");

    //Body Table
    for (int i = 0; i < qtPessoas - 1; i++)
    {

        printf("|");

        for (int j = 0; j < 3; j++)
        {
            int tamString = strlen(pessoas[i][j]);

            int space = ((maiorName + 2) - tamString) / 2;

            printSpace(space);
            printf("%s", pessoas[i][j]);
            printSpace(space);
        }

        printf("\n");
    }

    printf("\n\n");

    int option;
    printf("======= Sub-Menu =======\n");
    printf("1 - Menu Principal\n");
    printf("2 - Rever Lista\n");
    printf("Qual opcao voce deseja escolher: ");
    scanf("%i", &option);

    switch (option)
    {
    case 1:
        controller();
        break;
    case 2:
        verAgenda();
    default:
        break;
    }
}