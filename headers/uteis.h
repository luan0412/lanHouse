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

char** str_split(char* a_str, const char a_delim);

void printSpace(int qt);
#endif