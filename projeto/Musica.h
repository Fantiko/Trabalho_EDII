#ifndef MUSICA_H
#define MUSICA_H
#include "Pessoa.h"

#define N 30

typedef struct musicas Musicas;

Musicas* alocarMusicas();
Musicas* lerarquivo(Musicas *lista);
void printarMusicas(Musicas *lista);
void freeMusicas(Musicas *lista);

void popularidadeMusicas(NoLista* l, Musicas *lista);

void shellsort(int *a, int size);




#endif