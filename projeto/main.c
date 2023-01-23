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
  lista = leArquivo("pesquisa.txt", lista);
  /*--------------------------------------*/
  bool condicao = true;
  int opcao;
  /*--------------------------------------*/
  
  Musicas* lista_musicas;
  lista_musicas = alocarMusicas();
  lista_musicas = lerarquivo(lista_musicas);

  /*--------------------------------------*/

  popularidadeMusicas(lista, lista_musicas);


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

      printarMusicas(lista_musicas);
      
      lista = inserirElemento(lista, criarPessoa());
      imprimirLista(lista);
      
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
      printf("Sair\n");
      condicao = false;
      iteraLista(lista);

      freeMusicas(lista_musicas);

      break;

    default:
      lb();
      printf("Opcao invalida: %d\n", opcao);
      break;
    }
  }
  freeLista(lista);
}


