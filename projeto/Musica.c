#include<stdio.h>
#include<stdlib.h>

#include "Musica.h"
#include "auxiliar.h"
#include "Pessoa.h"

#define N 30

typedef struct musicas
{
  int IDmusica; // ID da musica
  char nome[50]; // nome da musica
  char artista[50]; // nome do artista
  int Npop;     // numero de pessoas que gostam da musica

} Musicas;


Musicas* alocarMusicas(){
    Musicas *lista = (Musicas*) malloc(N * sizeof(Musicas));
    if(lista == NULL){
        printf("Erro ao alocar memoria\n");
        exit(1);
    }
    
    return lista;
}


Musicas* lerarquivo(Musicas *lista){
    FILE *arquivo;
    arquivo = fopen("musicas.txt", "r");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo musicas.txt\n");
        exit(1);
    }

    Musicas *aux = lista;
    int i = 0;
    while(!feof(arquivo)){
        fscanf(arquivo, "%d - %s %s - %d", &aux[i].IDmusica, aux[i].nome, aux[i].artista, &aux[i].Npop);
        aux[i].Npop = 0;
        i++;
    }
    fclose(arquivo);
    return aux;
}

void printarMusicas(Musicas *lista)
{
    int i;
    for(i = 0; i < N; i++){
        printf("%d  %s %s  %d\n", lista[i].IDmusica, lista[i].nome, lista[i].artista, lista[i].Npop);
        i++;
    }
}

void freeMusicas(Musicas *lista){
    if(lista != NULL){
        for (int i = 0; i < N; i++)
        {
            free(lista[i].nome);
            free(lista[i].artista);
        }
        free(lista);
    }
}

void popularidadeMusicas(NoLista* l, Musicas *lista){
    NoLista *aux = l;
    int i, j;
    
    while(aux != NULL){

        for(i = 0; i < 5; i++){
            
            j = aux->pessoa->Nmusica[i];

            lista[j].Npop++;
            
            
        }
        aux = aux->prox;
    }
}



void shellsort(int *a, int size)
{
 int i , j , value;
 int gap = 1;
  
 do {
  gap = 3*gap+1;
 } while(gap < size);
  
 do {
  gap /= 3;
  for(i = gap; i < size; i++) {
   value = a[i];
   j = i - gap;
    
   while (j >= 0 && value < a[j]) {
    a[j + gap] = a[j];
    j -= gap;
   }
   a[j + gap] = value;
  }
 }while(gap > 1);
}
