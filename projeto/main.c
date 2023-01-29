#include <stdio.h>
#include <stdlib.h>
#include "Pessoa.h"
#include "auxiliar.h"
#include <stdbool.h>
#include <string.h>
#include "Musica.h"

/*------------------------------------------------------*/

void main()
{

  NoLista *lista = criarLista();
  lista = leArquivo("arquivos/pesquisa.txt", lista);
  /*--------------------------------------*/
  bool condicao = true;
  int opcao;
  /*--------------------------------------*/

  Musicas *lista_musicas;
  lista_musicas = alocarMusicas();
  lista_musicas = lerarquivo(lista_musicas);
  /*--------------------------------------*/
  Musicas* lista_musicasOrdenada;
  lista_musicasOrdenada = alocarMusicas();
  lista_musicasOrdenada = lerarquivo(lista_musicasOrdenada);
  /*--------------------------------------*/

  popularidadeMusicas(lista, lista_musicas);
  popularidadeMusicas(lista, lista_musicasOrdenada);

  /*--------------------------------------*/
  ordenarmusicas(lista_musicasOrdenada);

  while (condicao)
  {

    opcao = 0;

    linha();
    printf("1 - Cadastrar pessoa\n");
    printf("2 - Remover pessoa\n");
    printf("3 - Imprimir pessoas\n");
    printf("4 - Imprimir musicas\n");
    printf("5 - Imprimir musicas ordenadas\n");
    printf("6 - Sair\n");
    linha();
    printf("Digite a opcao desejada: ");
    scanf("%d", &opcao);

    switch (opcao)
    {

    case 1:
      lt();
      linha();
      printf("-<<<--Cadastrar pessoa-->>>-\n");

      printarMusicas(lista_musicas);

      lista = inserirElemento(lista, criarPessoa());
      iteraLista(lista); 
      atualizaPop(lista, lista_musicas);
      escreveMusica(lista_musicas);

      break;

    case 2:
      lt();
      linha();
      printf("-<<<--Remover pessoa-->>>-\n");
      int id = 0;
      printf("Digite o ID da pessoa que deseja remover: ");
      scanf("%d", &id);
      lista = removeElemento(lista, id);
      break;

    case 3:
      lt();
      linha();
      printf("-<<<--Imprimir Lista-->>>-\n");
      imprimirLista(lista);
      break;

    case 4:
      lt();
      printf("-<<<--Imprimir musicas-->>>-\n");
      printarMusicas(lista_musicas);
      break;

    case 5: 
      lt();
      printf("-<<<--Imprimir musicas ordenadas-->>>-\n");
      printarMusicas(lista_musicasOrdenada);
      break;


    case 6:
      printf("Sair\n");
      iteraLista(lista);
      escreveMusica(lista_musicas);
      ordenarmusicas(lista_musicas);
      separaPessoas(lista, lista_musicasOrdenada);

      condicao = false;
      break;

    default:
      lb();
      printf("Opcao invalida: %d\n", opcao);
      break;
    }
  }

  freeMusicas(lista_musicas);
  freeMusicas(lista_musicasOrdenada);
  freeLista(lista);
}
