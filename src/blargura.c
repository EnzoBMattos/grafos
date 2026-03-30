#include "busca_largura.h"
#include "busca_profundidade.h"
#include <limits.h>

enum CORES {BRANCO, CINZA, PRETO};

void visitaLargura(int origem, Grafo* g, int cor[], int antecessor[], int distancia[]) {
    cor[origem] = CINZA;
    distancia[origem] = 0;
    Fila f;
    inicializarFila(&f);
    entrarFila(&f, origem);
    while (!filaVazia(&f)) {
        int u = sairFila(&f);
        ApontadorVertAdj w = primeiroListaAdj(u, g);
        while (w != VERTICE_INVALIDO) {
            int i = vertDest(w, g);
            
            if (cor[i] == BRANCO) {
                cor[i] = CINZA;
                antecessor[i] = u;
                distancia[i] = distancia[u] + 1; 
                entrarFila(&f, i);
            }

            w = proxListaAdj(u, g, w);
        }
        cor[u] = PRETO;
    }

}

void buscaEmLargura(Grafo* g) {
    verificaValGrafo(g);

    int nVert = obtemNrVert(g);
    int* cor = (int*) malloc(sizeof(int) * nVert);
    int* antecessor = (int*) malloc(sizeof(int) * nVert);
    int* distancia = (int*) malloc(sizeof(int) * nVert);

    for (int i = 0; i < nVert; i++) {
        cor[i] = BRANCO;
        antecessor[i] = -1;
        distancia[i] = INT_MAX;
    }

    for (int i = 0; i < nVert; i++) {
        if (cor[i] == BRANCO) {
            visitaLargura(i, g, cor, antecessor, distancia);
        }
    }
}

void menorCaminho(int v1, int v2, Grafo* g) {
    verificaValGrafo(g);

    int nVert = obtemNrVert(g);
    int* cor = (int*) malloc(sizeof(int) * nVert);
    int* antecessor = (int*) malloc(sizeof(int) * nVert);
    int* distancia = (int*) malloc(sizeof(int) * nVert);

    for (int i = 0; i < nVert; i++) {
        cor[i] = BRANCO;
        antecessor[i] = -1;
        distancia[i] = INT_MAX;
    }

    visitaLargura(v1, g, cor, antecessor, distancia);

    if (distancia[v2] == INT_MAX) {
        printf("Nao ha caminho entre os vertices v1 e v2\n");
        free(cor);
        free(antecessor);
        free(distancia);
        return;
    }

    imprimeCaminho(v1, v2, antecessor, g);

    printf("E esse caminho tem %d distancia\n", distancia[v2]);

    free(cor);
    free(antecessor);
    free(distancia);
    
}