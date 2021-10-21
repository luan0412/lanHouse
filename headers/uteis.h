#ifndef UTEIS_H

#define  UTEIS_H

void criarConta(void);

void clean(void);

int singUp(void);

void listUsers(void);

int qtUsers(void);

void addOneQtUsers(void);

int autentication(char *user);

int login(void);

void printSpace(int qt);

void  printTableScheduled(void);

void headTable(int maiorName);

void controller(void);

void setAtualUser(char *user);

void addDisponibilidade(void);

int marcar(void);

int isValidParametrs(char *nome, char *hora);
#endif