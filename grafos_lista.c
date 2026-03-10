#include "grafo_listaAdj.h"
#include <stdlib.h>
#include <stdio.h>

bool inicializaGrafo(Grafo* g, int numVert) {
    verificaValGrafo(g);
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
    if (v < 0 || v >= g->numVert) {
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
    verificaValVert(v1, g); verificaValVert(v2, g);

    Aresta* novo1 = (Aresta*) malloc(sizeof(Aresta));
    if (!novo1) {
        printf("Não foi possível alocar memória para aresta\n");
        exit(ERRO);   
    } 
    novo1->peso = p;
    novo1->prox = g->listaAdj[v1];
    novo1->vdest = v2;
    g->listaAdj[v1] = novo1;

    Aresta* novo2 = (Aresta*) malloc(sizeof(Aresta));
    if (!novo2) {
        printf("Não foi possível alocar memória para aresta\n");
        exit(ERRO);   
    }
    novo2->peso = p;
    novo2->prox = g->listaAdj[v2];
    novo2->vdest = v1;
    g->listaAdj[v2] = novo2;

}

bool existeAresta(int v1, int v2, Grafo* g) {
    verificaValVert(v1, g); verificaValVert(v2, g);

    Aresta* atual = g->listaAdj[v1];
    while (atual) {
        if (atual->vdest == v2) return true;
        atual = atual->prox;
    }

    return false;
}

bool removeAresta(int v1, int v2, Peso* p, Grafo* g) {
    verificaValVert(v1, g); verificaValVert(v2, g);

    Aresta* atual = g->listaAdj[v1];
    Aresta* ant = NULL;
    bool remocao1 = false;
    while (atual) {
        if (atual->vdest == v2) {
            *p = atual->peso;
            
            if (ant) ant->prox = atual->prox;
            else g->listaAdj[v1] = atual->prox;
            
            atual->prox = NULL;
            free(atual);
            atual = NULL;
            remocao1 = true;
            
            break;
        }
        ant = atual;
        atual = atual->prox;
    }

    atual = g->listaAdj[v2];
    ant = NULL;
    bool remocao2 = false;
        while (atual) {
        if (atual->vdest == v1) {
            *p = atual->peso;
            
            if (ant) ant->prox = atual->prox;
            else g->listaAdj[v2] = atual->prox;
            
            atual->prox = NULL;
            free(atual);
            atual = NULL;
            remocao2 = true;
            
            break;
        }
        ant = atual;
        atual = atual->prox;
    }

    return (remocao1 && remocao2);
}

bool listaAdjVazia(int v, Grafo* g) {
    verificaValVert(v, g);

    if (g->listaAdj[v]) return false;
    return true;
}

Peso obtemPesoAresta(int v1, int v2, Grafo* g) {
    verificaValVert(v1, g); verificaValVert(v2, g);

    Aresta* atual = g->listaAdj[v1];
    while (atual) {
        if (atual->vdest == v2) return atual->peso;
        atual = atual->prox;
    }

    return ARESTA_NULA;
}

ApontadorVertAdj primeiroListaAdj(int v, Grafo* g) {
    verificaValVert(v, g);
    return g->listaAdj[v];
}

ApontadorVertAdj proxListaAdj(int v, Grafo* g, ApontadorVertAdj atual) {
    verificaValVert(v, g);

    return atual->prox;
}

void imprimeGrafo(Grafo* g) {
    verificaValGrafo(g);
    for (int i = 0; i < g->numVert; i++) {
        Aresta* atual = g->listaAdj[i];
        bool imprimiu = false;
        while (atual) {
            printf("peso:%d (%d,  %d) ", atual->peso, i, atual->vdest);
            imprimiu = true;
            atual = atual->prox;
        }
        if(imprimiu) printf("\n");
    }
    printf("\n");
}

void liberaGrafo(Grafo* g) {
    verificaValGrafo(g); Aresta* atual;

    for (int i = 0; i < g->numVert; i++) {
        atual = g->listaAdj[i];
        while (atual) {
            g->listaAdj[i] = atual->prox;
            g->listaAdj = NULL;
            free(atual);
            atual = g->listaAdj[i];
        }
    }

    free(g->listaAdj);
    g->listaAdj = NULL;
    g->numVert = 0;
}

int vertDest(ApontadorVertAdj p, Grafo* g) {
    if (!p) {
        printf("Erro: apontador para vértice inválido\n");
        exit(ERRO);
    }
    return p->vdest;
}
