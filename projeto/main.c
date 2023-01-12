#include <stdio.h>
#include <stdlib.h>
#include "Pessoa.h"
#include "auxiliar.h"
#include <stdbool.h>
#include <string.h>

// #define N 5

typedef struct musicas
{
  int IDmusica; // ID da musica
  int Npop;     // numero de pessoas que gostam da musica

} Musicas;

void main()
{

  NoLista *lista = criarLista();



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
    printf("Digite a opcao desejada: ");
    linha();
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
      break;

    default:
      printf("Opcao invalida\n");
      break;
    }
  }

}
