#ifndef PESSOA_H
#define PESSOA_H

typedef struct pessoa Pessoa;

typedef struct no NoLista;

#include "Musica.h"

struct pessoa
{
    int id;
    char nome[50]; // nome da pessoa
    int idade;
    int sexo;       // 0 = masculino, 1 = feminino
    int Nmusica[5]; // numero de musicas que a pessoa gosta

};

struct no // lista duplamente encadeada
{
    Pessoa *pessoa;
    struct no *prox;
};


/*-----------------------------Funçoes lista encadeada--------------------------------------------*/

NoLista* criarLista();
NoLista* createNode(Pessoa *pessoa);
int estaVazia(NoLista*l);

NoLista* inserirElemento(NoLista* l, Pessoa *pessoa);
NoLista * removeElemento(NoLista* l, int ID);
void imprimirLista(NoLista *l);

Pessoa* criarPessoa();
int verificaPessoa(Pessoa *p, int ID);
void imprimirPessoa(Pessoa *p);
void freePessoa(Pessoa *p);
void printasexo(int sexo);
void freeLista(NoLista *l);
void escreverPessoa(FILE *arquivo, Pessoa *p);
void iteraLista(NoLista *l);
NoLista * leArquivo(char* nome_arquivo, NoLista *l);
void atualizarid();
void freeLista(NoLista *l);


void imprimirNo(NoLista* l);

#endif