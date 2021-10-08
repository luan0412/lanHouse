#include <stdio.h>
#include <stdlib.h>

int main (void){
    char url[] = "agendados.txt";
    char url2[] = "agenda.txt";
    char nome[30];
    char horario[20];
    char jogo[30];
    FILE * arq1 ;
    FILE * arq2 ;
    int i;
    char linha[100];
    char *result;

    arq1 = fopen(url,"rt");
    if(arq1 == NULL){
   
        printf("arquivo não disponível");
    } else{ 
        i = 1 ;
        while (!feof(arq1))
        {
            result = fgets(linha,100,arq1);
            if (result)
            {
                printf("Linha %d : %s",i,linha);
            }
            fclose(arq1);
        }
        
    }
    
    arq2 = fopen(url2,"w");

    if(arq2 == NULL){
        printf("arquivo não disponível");
    } else{
        printf("Agendamento dos horários");
        printf("Digite seu nome \n");
        gets(nome);
        fprintf(arq2,"%s", nome);
        printf("O horário que quer agendar");
        gets(horario);
        fprintf(arq2,"%s",horario);
        printf("O jogo que quer jogar");
        gets(jogo);
        fprintf(arq2,"%s",jogo);
    }

    fclose(arq2);
    return 0;
}