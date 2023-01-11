#include <stdio.h>
#include <stdlib.h>
#include "Pessoa.h"

//#define N 5

typedef struct musicas
{
  int IDmusica; // ID da musica
  int Npop; // numero de pessoas que gostam da musica

} Musicas;

int main()
{
  NoLista* lista = criarLista();
  inserirElemento( &lista, criarPessoa());
  imprimirPessoa(lista->pessoa);
    return 0;
}
