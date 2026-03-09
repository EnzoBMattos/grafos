#include "grafo_matrizadj.h"
#include <stdlib.h>

bool inicializaGrafo(Grafo* g, int numVert) {
    for (int i = 0; i < numVert; i++) {
        for (int j = 0; j < numVert; j++) {
            g->matrizAdj[i][j] = ARESTA_NULA;
        }
    }
    g->numVert = numVert;
    return true;
}

int obtemNrVert(Grafo* g) {
    return g->numVert;
}


void verficaValVert(int v, Grafo* g) {
    if (!g) {
        printf("Erro: ponteiro para grafo nulo\n");
        exit(ERRO);
    }
    if (v < 0 || v > g->numVert) {
        printf("Erro: vértice inválido");
        exit(ERRO);
    }
}

void verificaValGrafo(Grafo* g) {
    if (!g) {
        printf("Erro: ponteiro para grafo nulo\n");
        exit(ERRO);
    }
}

void insereAresta(int v1, int v2, Peso p, Grafo* g) {
    verificaValVert(v1, g); verficaValVert(v2, g);
    g->matrizAdj[v1][v2] = p;
    g->matrizAdj[v2][v1] = p;
}

bool existeAresta(int v1, int v2, Grafo* g) {
    verificaValVert(v1, g); verficaValVert(v2, g);
    return (g->matrizAdj[v1][v2] != ARESTA_NULA);
}

bool removeAresta(int v1, int v2, Peso* p, Grafo* g) {
    verificaValVert(v1, g); verficaValVert(v2, g);
    *p = g->matrizAdj[v1][v2];
    g->matrizAdj[v1][v2] = ARESTA_NULA;
    return true;
}

bool listaAdjVazia(int v, Grafo* g) {
    verificaValVert(v, g);
    for (int i = 0; i < g->numVert; i++) {
        if (g->matrizAdj[v][i] != ARESTA_NULA) return false; 
    }
}

Peso obtemPesoAresta(int v1, int v2, Grafo* g) {
    verificaValVert(v1, g); verficaValVert(v2, g);
    return g->matrizAdj[v1][v2];
}

ApontadorVertAdj primeiroListaAdj(ApontadorVertAdj v, Grafo* g) {
    verficaValVert(v, g);

    proxListaAdj(v, g, -1);
}


ApontadorVertAdj proxListaAdj(ApontadorVertAdj v, Grafo* g, int atual) {
    verficaValVert(v, g);
    for (int i = atual + 1; i < g->numVert; i++) {
        if (g->matrizAdj[v][i] != ARESTA_NULA) return i;
    }
    return VERTICE_INVALIDO;
}

void imprimeGrafo(Grafo* g) {
    for (int i = 0; i < g->numVert; i++) {
        for (int j = 0; j < g->numVert; j++) {
            if (g->matrizAdj[i][j] != ARESTA_NULA) {
                printf("peso:%d (%d, %d)", g->matrizAdj[i][j], i, j);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void liberaGrafo(Grafo* g) {

}

