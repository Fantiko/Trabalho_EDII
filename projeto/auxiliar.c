#include<stdlib.h>
#include<stdio.h>

#include "auxiliar.h"

void lb(){
    setbuf(stdin, NULL);// limpa o buffer do teclado
}

void lt(){
    system("clear");// limpa a tela
    //system("cls");// limpa a tela
}

void linha(){
    printf("\n<------------------------//---------------------------------->\n");
}