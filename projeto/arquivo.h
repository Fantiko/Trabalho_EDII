#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.h"
#include "auxiliar.h"

void abrirarquivo(FILE *arquivo);
void fechararquivo(FILE *arquivo);
void escreverPessoa(FILE *arquivo, Pessoa* p);