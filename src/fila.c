#include "fila_vertices.h"
#include <stdlib.h>

void inicializarFila(Fila* f) {
    f->fim = NULL;
    f->inicio = NULL;
}

void entrarFila(Fila* f, int vertice) {
    No* novo = (No*) malloc(sizeof(No));
    novo->vertice = vertice;
    novo->prox = NULL;

    if (!f->inicio) {
        f->inicio = novo;
        f->fim = novo;
    }
    else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

int sairFila(Fila* f) {
    if (!f->inicio) return -1; 
    No* aux = f->inicio;
    int resp = aux->vertice;
    f->inicio = aux->prox;
    free(aux);
    return resp;
}

void deletaFila(Fila* f) {
    int i = sairFila(f);
    while(i != -1) {
        i = sairFila(f);
    }
    f->fim = NULL;
    f->inicio = NULL;
}

bool filaVazia(Fila* f) {
    return f->inicio == NULL;
}