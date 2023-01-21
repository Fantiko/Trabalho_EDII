
typedef struct pessoa
{
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
