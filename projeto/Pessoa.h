
typedef struct pessoa
{
    int id;
    char nome[50]; // nome da pessoa
    int idade;
    char sexo;
    int Nmusica[5]; // numero de musicas que a pessoa gosta

} Pessoa;

typedef struct no  // lista duplamente encadeada
{
    Pessoa *pessoa;
    struct no *prox;
} NoLista;

NoLista* criarLista();
NoLista* createNode(Pessoa *pessoa);
int estaVazia(NoLista**l);
void inserirElemento(NoLista** l, Pessoa *pessoa);
void removeElemento(NoLista** l, Pessoa *pessoa);
void imprimirLista(NoLista **l);

Pessoa* criarPessoa();
void imprimirPessoa(Pessoa *p);
void freePessoa(Pessoa *p);
void printasexo(int sexo);
void freeLista(NoLista **l);
void escreverPessoa(FILE *arquivo, Pessoa *p);
void iteraLista(NoLista **l);
void leArquivo(char* nome_arquivo, NoLista **l);
void atualizarid();
void freeLista(NoLista **l);

