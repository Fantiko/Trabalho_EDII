#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "auxiliar.h"
#include "Pessoa.h"


void abrirarquivo(FILE *arquivo){
    arquivo = fopen("pesquisa.txt", "w+");
    printf("Arquivo aberto com sucesso!\n");
    fprintf(arquivo, "Inicio do arquivo\n");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
}

void fechararquivo(FILE *arquivo){
    fprintf(arquivo, "Fim do arquivo");
    fclose(arquivo);
}

void escreverPessoa(FILE *arquivo, Pessoa* p){
    fprintf(arquivo,"%[^\t] %d %d\n", p->nome, p->idade, p->sexo);
    fprintf(arquivo,"\t%d %d %d %d %d\n", p->Nmusica[0], p->Nmusica[1], p->Nmusica[2], p->Nmusica[3], p->Nmusica[4]);

}
   
