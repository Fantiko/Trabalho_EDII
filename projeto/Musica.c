#include <stdio.h>
#include <stdlib.h>

#include "Musica.h"
#include "auxiliar.h"
#include "Pessoa.h"

#define N 30

// typedef struct musicas
// {
//     int IDmusica;     // ID da musica
//     char nome[50];    // nome da musica
//     char artista[50]; // nome do artista
//     int Npop;         // numero de pessoas que gostam da musica

// } Musicas;

Musicas *alocarMusicas()
{
    Musicas *lista = (Musicas *)malloc(N * sizeof(Musicas));
    if (lista == NULL)
    {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }

    return lista;
}

Musicas *lerarquivo(Musicas *lista)
{
    FILE *arquivo;
    arquivo = fopen("musicas.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo musicas.txt\n");
        exit(1);
    }

    Musicas *aux = lista;
    int i = 0;
    while (!feof(arquivo))
    {
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
    for (i = 0; i < N; i++)
    {
        printf("[%d] - %s %s - %d\n", lista[i].IDmusica, lista[i].nome, lista[i].artista, lista[i].Npop);
    }
}

void freeMusicas(Musicas *lista)
{
    if (lista != NULL)
    {
        free(lista);
    }
}

void popularidadeMusicas(NoLista *l, Musicas *lista)
{
    NoLista *aux = l;
    int i, j;

    while (aux != NULL)
    {

        for (i = 0; i < 5; i++)
        {

            j = aux->pessoa->Nmusica[i];

            lista[j-1].Npop++;
        }
        aux = aux->prox;
    }
}

void ordenarmusicas(Musicas *lista)
{
    FILE *arquivo = fopen("musicasOrdenadas.txt", "w");
    shellsort(lista, N);
    int i;
    for (i = 0; i < N; i++)
    {
        if (lista[i].Npop != 0)
        {

            fprintf(arquivo, "%d - %s %s - %d\n", lista[i].IDmusica, lista[i].nome, lista[i].artista, lista[i].Npop);
        }
    }
    fclose(arquivo);
}

void escreveMusica(Musicas *lista)
{
    FILE *arquivo = fopen("musicas.txt", "w");
    int i = 0;

    while (i < N)
    {
        fprintf(arquivo, "%d - %s %s - %d\n", lista[i].IDmusica, lista[i].nome, lista[i].artista, lista[i].Npop);
        i++;
    }

    fclose(arquivo);
}

void shellsort(Musicas *a, int size)
{
    int i, j;
    Musicas value;
    int gap = 1;

    do
    {
        gap = 3 * gap + 1;
    } while (gap < size);

    do
    {
        gap /= 3;
        for (i = gap; i < size; i++)
        {
            value = a[i];
            j = i - gap;

            while (j >= 0 && value.Npop > a[j].Npop)
            {
                a[j + gap] = a[j];
                j -= gap;
            }
            a[j + gap] = value;
        }
    } while (gap > 1);
}

FILE* abrirarquivos(char* nome){
    FILE* arquivo = fopen("nome", "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo %s", nome);
        exit(1);
    }
    return arquivo;
}

void fechararquivos(FILE* arquivo){
    fclose(arquivo);
}

void separaPessoas(NoLista* l , Musicas* m){
    FILE* Hmaior = abrirarquivos("categorias/Hmaior.txt");
    FILE* Hmenor = abrirarquivos("categorias/Hmenor.txt");
    FILE* Mmaior = abrirarquivos("categorias/Mmaior.txt");
    FILE* Mmenor = abrirarquivos("categorias/Mmenor.txt");
    

    NoLista* aux = l;
    while(aux!=NULL){
        if(aux->pessoa->sexo==0){
            if(aux->pessoa->idade>=20){

                for (int i = 0; i < 3; i++)
                {
                    if (aux->pessoa->Nmusica[i]==m[i].IDmusica)
                    {
                        printf("oi");
                        escreverPessoa(Hmaior, aux->pessoa);
                    }
                    
                }
                
            }else{
                for (int i = 0; i < 3; i++)
                {
                    if (aux->pessoa->Nmusica[i]==m[i].IDmusica)
                    {
                        escreverPessoa(Hmenor, aux->pessoa);
                        
                    }
                    
                }
            }
        }else{
            if(aux->pessoa->idade>=20){
                for (int i = 0; i < 3; i++)
                {
                    if (aux->pessoa->Nmusica[i]==m[i].IDmusica)
                    {
                        escreverPessoa(Mmaior, aux->pessoa);
                        
                    }
                    
                }
            }else{
                for (int i = 0; i < 3; i++)
                {
                    if (aux->pessoa->Nmusica[i]==m[i].IDmusica)
                    {
                        escreverPessoa(Mmenor, aux->pessoa);
                        
                    }
                    
                }
                
            }
        }
        aux = aux->prox;
    }

    fechararquivos(Hmaior);
    fechararquivos(Hmenor);
    fechararquivos(Mmaior);
    fechararquivos(Mmenor);
}

void atualizaPop(NoLista* l, Musicas* m){
    NoLista* aux = l;
    while(aux->prox !=NULL){
       
        aux = aux->prox;
    }

    for (int i = 0; i < 5; i++)
    {
        m[aux->pessoa->Nmusica[i]-1].Npop++;
    }
    


}