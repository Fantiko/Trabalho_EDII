#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.h"
#include "auxiliar.h"

int id_global = 1;

// typedef struct pessoa
// {
//     int id;
//     char nome[50]; // nome da pessoa
//     int idade;
//     int sexo;       // 0 = masculino, 1 = feminino
//     int Nmusica[5]; // numero de musicas que a pessoa gosta

// } Pessoa;

// typedef struct no // lista duplamente encadeada
// {
//     Pessoa *pessoa;
//     struct no *prox;
// } NoLista;
/*-----------------------------Funçoes lista encadeada--------------------------------------------*/

NoLista *criarLista()
{
    return NULL;
}

void atualizarid()
{
    id_global++;
}

void printasexo(int sexo)
{
    if (sexo == 0)
    {
        printf("Sexo: Masculino");
    }
    else
    {
        printf("Sexo: Feminino");
    }
}


void imprimirPessoa(Pessoa *p)
{
    Pessoa *aux = p;
    printf("\nID: %d", aux->id);
    printf("\nNome: %s\n", aux->nome);
    printf("Idade: %d\n", aux->idade);
    printasexo(aux->sexo);
    printf("\nMusicas que a pessoa gosta: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", aux->Nmusica[i]);
    }
}

NoLista *createNode(Pessoa *pessoa)
{
    NoLista *no = (NoLista *)malloc(sizeof(NoLista));
    no->pessoa = pessoa;
    no->prox = NULL;
    return no;
}

int estaVazia(NoLista *l)
{
    return (l == NULL);
}

NoLista* inserirElemento(NoLista *l, Pessoa *pessoa)
{
    
    NoLista *aux = l;
    NoLista *no = createNode(pessoa);
    if(no == NULL) return l;
    if (estaVazia(l))
    {   
        l = no;
    }
    else
    {
        
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = no;
        
    }
    return l;
}

NoLista * removeElemento(NoLista *l, int ID)
{
    if (estaVazia(l))
    {
        printf("Lista vazia");
    }
    else
    {
        NoLista *aux = l;
        NoLista *ant = NULL;
        while (aux != NULL && !(verificaPessoa(aux->pessoa, ID)))
        {
            ant = aux;
            aux = aux->prox;
        }
        if (aux == NULL)
        {
            printf("Elemento nao encontrado");
        }
        else
        {
            if (ant == NULL)
            {
                l = aux->prox;
            }
            else
            {
                ant->prox = aux->prox;
            }
            freePessoa(aux->pessoa);
            free(aux);
        }
    }
    return l;
}

int verificaPessoa(Pessoa *p, int ID)
{
    return p->id ==ID;

}




void imprimirLista(NoLista *l)
{
    NoLista *aux = l;
    while (aux != NULL)
    {
        imprimirPessoa(aux->pessoa);
        aux = aux->prox;
    }
}

/*-----------------------------funçoes pessoa--------------------------------------------*/
Pessoa *criarPessoa()
{
    int iterador;
    Pessoa *p;
    p = (Pessoa *)malloc(sizeof(Pessoa));
    if (p == NULL)
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }

    p->id = id_global;
    atualizarid();

    lb();
    printf("Digite o nome da pessoa: ");
    scanf("%[^\n]", p->nome);
    lb();

    printf("Digite a idade da pessoa: ");
    scanf("%d", &p->idade);
    lb();

    printf("0 - Masculino | 1 - Feminino");
    printf("\nDigite o sexo da pessoa: ");
    scanf(" %d", &p->sexo);
    lb();

    printf("Digite 5 IDs de musicas que a pessoa gosta:\n");
    for (iterador = 0; iterador < 5; iterador++)
    {
        printf("digite o ID da musica %d: ", iterador + 1);
        scanf("%d", &p->Nmusica[iterador]);
    }
    lb();

    return p;
}

void freePessoa(Pessoa *p)
{   
    if(p!=NULL){
        free(p);
    }
}

void escreverPessoa(FILE *arquivo, Pessoa *p)
{
   
    Pessoa *aux = p;
    fprintf(arquivo, "%d %s\t%d %d\n", aux->id, aux->nome, aux->idade, aux->sexo);
    fprintf(arquivo, "\t%d %d %d %d %d\n", aux->Nmusica[0], aux->Nmusica[1], aux->Nmusica[2], aux->Nmusica[3], aux->Nmusica[4]);

}
/*------------------------------------------------------*/

void iteraLista(NoLista *l)
{
    FILE *arquivo = fopen("pesquisa.txt", "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    NoLista *aux = l;
    while (aux != NULL)
    {   
        escreverPessoa(arquivo, aux->pessoa);
        aux = aux->prox;
    }

    fclose(arquivo);
}

NoLista * leArquivo(char *nome_arquivo, NoLista *l)
{
    FILE *arquivo = fopen(nome_arquivo, "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
    Pessoa* p = (Pessoa *)malloc(sizeof(Pessoa));
    NoLista *aux = l;    
    lb();
    int i=0;
    while (fscanf(arquivo, "%d %[^\t]\t%d %d\n\t%d %d %d %d %d\n", &p->id, p->nome, &p->idade, &p->sexo, &p->Nmusica[0], &p->Nmusica[1], &p->Nmusica[2], &p->Nmusica[3], &p->Nmusica[4]) != EOF)
    {   
        
        if (p == NULL)
        {
            printf("Erro na alocacao de memoria");
            exit(1);
        }
        aux = inserirElemento(aux, p);
        if(i==0 && l==NULL){
            l = aux;
            i++;
        }
        
        atualizarid();
        p = (Pessoa *)malloc(sizeof(Pessoa));  
    }
    free(p);
    fclose(arquivo);
    return l;
}

static void percorreLista(NoLista* l){
    NoLista *aux = l;
    NoLista * atual;
    while (aux != NULL)
    {
        atual = aux;
        aux = aux->prox;
        printf("%s\n", atual->pessoa->nome);
    }
}
void freeLista(NoLista *l)
{   
  //percorreLista(l);
  NoLista *aux = l;
  NoLista * atual;
  while (aux != NULL)
  {
    atual = aux;
    aux = aux->prox;
    freePessoa(atual->pessoa);
    free(atual);
  }
}



void imprimirNo(NoLista* n){
    imprimirPessoa(n->pessoa);
}