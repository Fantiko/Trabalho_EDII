#ifndef MUSICA_H
#define MUSICA_H
#include "Pessoa.h"

#define N 30

typedef struct musicas Musicas;

struct musicas
{
    int IDmusica;     // ID da musica
    char nome[50];    // nome da musica
    char artista[50]; // nome do artista
    int Npop;         // numero de pessoas que gostam da musica

};


Musicas* alocarMusicas();
Musicas* lerarquivo(Musicas *lista);
void printarMusicas(Musicas *lista);
void freeMusicas(Musicas *lista);

void popularidadeMusicas(NoLista* l, Musicas *lista);

void shellsort(Musicas *a, int size);

void ordenarmusicas(Musicas *lista);
void escreveMusica(Musicas *lista );

void escreveMusica(Musicas *lista );


FILE* abrirarquivos(char* nome);
void fechararquivos(FILE* arquivo);
void separaPessoas(NoLista* l , Musicas* m);
void atualizaPop(NoLista* l, Musicas* m);




#endif