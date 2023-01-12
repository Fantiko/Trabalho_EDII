#include <stdio.h>
#include <stdlib.h>
#include "auxiliar.h"
#include <string.h>

typedef struct pessoa
{
    char nome[50]; // nome da pessoa
    char sobrenome[50]; 
    int idade;
    int sexo; // 0 = masculino, 1 = feminino
    int Nmusica[5]; // numero de musicas que a pessoa gosta

} Pessoa;

typedef struct no  // lista duplamente encadeada
{
    Pessoa *pessoa;
    struct no *prox;
} NoLista;
/*-----------------------------Funçoes lista encadeada--------------------------------------------*/

NoLista* criarLista()
{
    return NULL;
}

NoLista* createNode(Pessoa *pessoa)
{
    NoLista * no = (NoLista*) malloc(sizeof(NoLista));
    no->pessoa = pessoa;
    no->prox = NULL;
    return no;
}

int estaVazia(NoLista** l){
    return (*l == NULL);
}

void inserirElemento(NoLista** l, Pessoa *pessoa)
{
    NoLista *no = createNode(pessoa);
    if(estaVazia(l))
    {
        *l = no;
    }
    else
    {
        NoLista *aux = *l;
        while(aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = no;
    }
}

void removeElemento(NoLista** l, Pessoa *pessoa)
{
    if(estaVazia(l))
    {
        printf("Lista vazia");
    }
    else
    {
        NoLista *aux = *l;
        NoLista *ant = NULL;
        while(aux != NULL && aux->pessoa != pessoa)
        {
            ant = aux;
            aux = aux->prox;
        }
        if(aux == NULL)
        {
            printf("Elemento nao encontrado");
        }
        else
        {
            if(ant == NULL)
            {
                *l = aux->prox;
            }
            else
            {
                ant->prox = aux->prox;
            }
            free(aux);
        }
    }
}
void imprimirPessoa(Pessoa *p)
{
    Pessoa *aux = p;
    printf("Nome: %s\n", aux->nome);
    printf("Sobrenome: %s\n", aux->sobrenome);
    printf("Idade: %d\n", aux->idade);
    printf("Sexo: %c\n", aux->sexo);
    for (int i = 0; i < 5; i++)
    {
        printf("Musicas que a pessoa gosta: %d\n", aux->Nmusica[i]);
    }   
}

void imprimirLista(NoLista **l){
    NoLista *aux = *l;
    while(aux != NULL){
        imprimirPessoa(aux->pessoa);
        aux = aux->prox;
    }
}

/*-----------------------------funçoes pessoa--------------------------------------------*/
Pessoa* criarPessoa()
{
    int iterador;
    Pessoa *p;
    p = (Pessoa*) malloc(sizeof(Pessoa));
    if(p == NULL)
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }

    printf("Digite o nome da pessoa: ");
    scanf("%s", p->nome);

    printf("Digite o sobrenome da pessoa: ");
    scanf("%s", p->sobrenome);

    printf("Digite a idade da pessoa: ");
    scanf("%d", &p->idade);

    printf("Digite o sexo da pessoa: ");
    scanf(" %d", &p->sexo);

    printf("Digite 5 IDs de musicas que a pessoa gosta: ");
    for (iterador = 0; iterador < 5; iterador++)
    {
        scanf("%d", &p->Nmusica[iterador]);
    }
    
    return p;
}



void freePessoa(Pessoa *p)
{
    free(p);
}

Pessoa* buscarPessoa(NoLista** l, char nome[50], char sobrenome[50])
{
    NoLista *aux = *l;
    while(aux != NULL)
    {
        if(strcmp(aux->pessoa->nome, nome) == 0 && strcmp(aux->pessoa->sobrenome, sobrenome) == 0)
        {
            return aux->pessoa;
        }
        aux = aux->prox;
    }
    return NULL;
}