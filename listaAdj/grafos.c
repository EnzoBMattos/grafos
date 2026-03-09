#include "grafo_listaAdj.h"
#include <stdlib.h>

bool inicializaGrafo(Grafo* g, int numVert) {
    verificaValG(g);
    if (numVert <= 0 || numVert > MAX_NUM_VERT) return false;
    g->numVert = numVert;
    g->listaAdj = (Aresta**) calloc(numVert, sizeof(Aresta*));
    if (!g->listaAdj) return false;
    return true;
}

int obtemNrVert(Grafo* g) {
    return g->numVert;
}

void verificaValVert(int v, Grafo* g) {
    if (!g) {
        printf("Erro: ponteiro para grafo nulo\n");
        exit(ERRO);
    }
    if (v < 0 || v > g->numVert) {
        printf("Erro: vértice inválido\n");
        exit(ERRO);
    }
}

void verificaValGrafo(Grafo* g) {
    if (!g) {
        printf("Erro: ponteiro para grafo nulo\n");
        exit(-1);
    }
}

void insereAresta(int v1, int v2, Peso p, Grafo* g) {
    verificaValVert(v1, g); verificaValGrafo(v2, g);

    Aresta* novo1 = (Aresta*) malloc(sizeof(Aresta));
    novo1->peso = p;
    novo1->prox = g->listaAdj[v1];
    novo1->vdest = v2;
    g->listaAdj[v1] = novo1;

    Aresta* novo2 = (Aresta*) malloc(sizeof(Aresta));
    novo2->peso = p;
    novo2->prox = g->listaAdj[v2];
    novo2->vdest = v2;
    g->listaAdj[v2] = novo2;

}

bool existeAresta(int v1, int v2, Grafo* g) {
    verificaValVert(v1, g); verificaValGrafo(v2, g);

    Aresta* atual = g->listaAdj[v1];
    while (atual) {
        if (atual->vdest == v2) return true;
        atual = atual->prox;
    }

    return false;
}

bool removeAresta(int v1, int v2, Peso* p, Grafo* g) {
    verificaValVert(v1, g); verificaValGrafo(v2, g);

    Aresta* atual = g->listaAdj[v1];
    Aresta* ant = NULL;
    while (atual) {
        if (atual->vdest == v2) {
            *p = atual->peso;
            if (ant) ant->prox = atual->prox;
            free(atual);
            return true;
        }
        ant = atual;
        atual = atual->prox;
    }
    
    return false;
}

bool listaAdjVazia(int v, Grafo* g) {
    verificaValVert(v, g);

    if (g->listaAdj[v]) return false;
    return true;
}

Peso obtemPesoAresta(int v1, int v2, Grafo* g) {
    verificaValVert(v1, g); verificaValGrafo(v2, g);

    Aresta* atual = g->listaAdj[v1];
    while (atual) {
        if (atual->vdest == v2) return atual->peso;
        atual = atual->prox;
    }

    return VERTICE_INVALIDO;
}

int primeiroListaAdj(int v, Grafo* g) {
    return g->listaAdj[v]->vdest;
}

ApontadorVertAdj proxListaAdj(ApontadorVertAdj v, int atual, Grafo* g) {
    verificaValVert(v, g);

    return v->prox;
}

void imprimeGrafo(Grafo* g) {
    verificaValGrafo(g);
    for (int i = 0; i < g->numVert; i++) {
        Aresta* atual = g->listaAdj[i];
        while (atual) {
            printf("peso:%d (%d,  %d)", atual->peso, i, atual->vdest);
            atual = atual->prox;
        }
        printf("\n");
    }
    printf("\n");
}

void liberaGrafo(Grafo* g) {
    verificaValGrafo(g);

    for (int i = 0; i < g->numVert; i++) {
        liberalista(g->listaAdj[i]);
    }
}

void liberaLista(Aresta* atual) {
    if (!atual) return;
    liberaLista(atual->prox);
    free(atual);
}