#include <stdio.h>
#include <stdlib.h>
#include "Pessoa.h"
#include "auxiliar.h"
#include "arquivo.h"
#include <stdbool.h>
#include <string.h>

// #define N 5

void escreverPessoa(FILE *arquivo, Pessoa *p)
{
  if (arquivo == NULL)
  {
    printf("Erro ao abrir o arquivo");
    exit(1);
  }

  Pessoa *aux = p;
  fprintf(arquivo, "%s %d %d\n", aux->nome, aux->idade, aux->sexo);
  fprintf(arquivo, "\t%d %d %d %d %d\n", aux->Nmusica[0], aux->Nmusica[1], aux->Nmusica[2], aux->Nmusica[3], aux->Nmusica[4]);
  
}
/*------------------------------------------------------*/

void iteraLista(NoLista **l, FILE *arquivo)
{
  NoLista *aux = *l;
  while (aux != NULL)
  {
    escreverPessoa(arquivo, aux->pessoa);
    aux = aux->prox;
  }
}

typedef struct musicas
{
  int IDmusica; // ID da musica
  int Npop;     // numero de pessoas que gostam da musica

} Musicas;

/*------------------------------------------------------*/

void main()
{

  NoLista *lista = criarLista();
  /*--------------------------------------*/
  FILE *arquivo;
  arquivo = abrirarquivo(arquivo);

  /*--------------------------------------*/
  bool condicao = true;
  int opcao;
  /*--------------------------------------*/
  while (condicao)
  {

    opcao = 0;

    linha();
    printf("1 - Cadastrar pessoa\n");
    printf("2 - Remover pessoa\n");
    printf("3 - Imprimir pessoas\n");
    printf("4 - Sair\n");
    linha();
    printf("Digite a opcao desejada: ");
    scanf("%d", &opcao);

    switch (opcao)
    {

    case 1:
      lt();
      linha();
      printf("-<<<--Cadastrar pessoa-->>>-\n");
      inserirElemento(&lista, criarPessoa());
      break;

    case 2:
      lt();
      linha();
      printf("-<<<--Remover pessoa-->>>-\n");
      break;

    case 3:
      lt();
      linha();
      printf("-<<<--Imprimir Lista-->>>-\n");
      imprimirLista(&lista);
      break;

    case 4:
      printf("Sair\n");
      condicao = false;
      iteraLista(&lista, arquivo);

      break;

    default:
      lb();
      printf("Opcao invalida\n");
      break;
    }
  }

  fechararquivo(arquivo);
}
