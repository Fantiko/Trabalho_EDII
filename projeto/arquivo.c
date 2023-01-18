#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "auxiliar.h"



FILE* abrirarquivo(FILE *arquivo){
    arquivo = fopen("pesquisa.txt","w");
    printf("Arquivo aberto com sucesso!\n");
    fprintf(arquivo, "Inicio do arquivo\n");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
    return arquivo;
}

void fechararquivo(FILE *arquivo){
    fprintf(arquivo, "Fim do arquivo");
    fclose(arquivo);
}


   
