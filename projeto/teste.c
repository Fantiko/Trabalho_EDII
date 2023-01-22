#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct pessoa
{
    char nome[50]; // nome da pessoa
    // char sobrenome[50]; 
    int idade;
    int sexo; // 0 = masculino, 1 = feminino
    int Nmusica[5]; // numero de musicas que a pessoa gosta

} Pessoa;

typedef struct no  // lista duplamente encadeada
{
    Pessoa *pessoa;
    struct no *prox;
} NoLista;

void main()
{
    Pessoa *p = malloc(sizeof(Pessoa));
    NoLista *l = malloc(sizeof(NoLista));
    

}

