#ifndef PESSOA_H
#define PESSOA_H
typedef struct pessoa Pessoa;

typedef struct no NoLista;

NoLista* criarLista();
NoLista* createNode(Pessoa *pessoa);
int estaVazia(NoLista*l);

NoLista* inserirElemento(NoLista* l, Pessoa *pessoa);
NoLista * removeElemento(NoLista* l, int ID);
void imprimirLista(NoLista *l);

Pessoa* criarPessoa();
int verificaPessoa(Pessoa *p, int ID);
void imprimirPessoa(Pessoa *p);
void freePessoa(Pessoa *p);
void printasexo(int sexo);
void freeLista(NoLista *l);
void escreverPessoa(FILE *arquivo, Pessoa *p);
void iteraLista(NoLista *l);
NoLista * leArquivo(char* nome_arquivo, NoLista *l);
void atualizarid();
void freeLista(NoLista *l);


void imprimirNo(NoLista* l);

#endif