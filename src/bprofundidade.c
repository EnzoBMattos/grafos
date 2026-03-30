#include "busca_profundidade.h"

enum CORES {BRANCO, CINZA, PRETO};

void visitaProfundidade(int v, Grafo* g, int* tempo, int cor[], int desc[], int term[], int ant[]) {
    cor[v] = CINZA;
    desc[v] = ++(*tempo);

    ApontadorVertAdj u = primeiroListaAdj(v, g);
    while (u != VERTICE_INVALIDO) {
        int i = vertDest(u, g);
        if (cor[i] == BRANCO) {
            ant[i] = v;
            visitaProfundidade(i, g, tempo, cor, desc, term, ant);
        }
        u = proxListaAdj(v, g, u);
    }
    term[v] = ++(*tempo);
    cor[v] = PRETO; 
}


void buscaProfundidade(Grafo* g) {
    verificaValGrafo(g);

    int nVert = obtemNrVert(g);
    int tempo = 0;
    int* desc = (int*) malloc(sizeof(int) * nVert);
    int* term = (int*) malloc(sizeof(int) * nVert);
    int* ant = (int*) malloc(sizeof(int)* nVert);
    int* cor = (int*) malloc(sizeof(int) * nVert);

    for (int i = 0; i < nVert; i++) {
        cor[i] = BRANCO;
        desc[i] = term[i] = 0; 
        ant[i] = -1;
    }

    for (int i = 0; i < nVert; i++) {
        if (cor[i] == BRANCO) visitaProfundidade(i, g, &tempo, cor, desc, term, ant);
    }

    free(desc);
    free(term);
    free(ant);
    free(cor);
}

void imprimeCaminho(int v1, int v2, int ant[], Grafo* g) {
    if (v1 == v2) {
        printf("%d ", v1);
        return;
    }
    else {
        imprimeCaminho(v1, ant[v2], ant, g);
        printf("%d ", v2);
    }
}

void visitaCaminho(int v, int ant[], int cor[], Grafo* g) {
    cor[v] = CINZA;

    ApontadorVertAdj u = primeiroListaAdj(v, g);
    while (u != VERTICE_INVALIDO) {
        int i = vertDest(u, g);
        if (cor[i] == BRANCO) {
            ant[i] = v; 
            visitaCaminho(i, ant, cor, g);
        }
        u = proxListaAdj(v, g, u);
    }
    cor[v] = PRETO;
}

bool existeCaminho(int v1, int v2, Grafo* g) {
    verificaValGrafo(g);

    int nVert = obtemNrVert(g);

    int* ant = (int*) malloc(nVert * sizeof(int));
    int* cor = (int*) malloc(nVert * sizeof(int));
    
    for (int i = 0; i < nVert; i++) {
        cor[i] = BRANCO; 
        ant[i] = -1;
    }

    visitaCaminho(v1, ant, cor, g);

    bool resp = false;
    if (cor[v2] == CINZA || cor[v2] == PRETO) {
        imprimeCaminho(v1, v2, ant, g);
        resp = true;
    }
    free(ant); free(cor);
    return resp;
}

void visitaAciclico(int v, Grafo* g, bool* resp, int cor[], int ant[]) {
    cor[v] = CINZA;

    ApontadorVertAdj u = primeiroListaAdj(v, g);
    while (u != VERTICE_INVALIDO) {
        int i = vertDest(u, g);
        
        if (cor[i] == CINZA && ant[v] != i) {
            *resp = false;
            return;
        }

        if (cor[i] == BRANCO) {
            ant[i] = v;
            visitaAciclico(i, g, resp, cor, ant);
        }

        u = proxListaAdj(v, g, u);
    }

    cor[v] = PRETO;
}

bool grafoAciclico(Grafo* g) {
    verificaValGrafo(g);
    
    int nVert = obtemNrVert(g);
    int* cor = (int*) malloc(sizeof(int) * nVert);
    int* ant = (int*) malloc(sizeof(int) * nVert);

    for (int i = 0; i < nVert; i++) {
        cor[i] = BRANCO;
        ant[i] = -1;
    }

    bool resp = true;
    for (int i = 0; i < nVert; i++) {
        if (cor[i] == BRANCO && resp) {
            visitaAciclico(i, g, &resp, cor, ant);
        }
    }
    free(cor); free(ant);
    return resp;
}

void visitaConexo(Grafo* g, int v, int cor[]) {
    cor[v] = CINZA;
    printf("%d ", v);

    ApontadorVertAdj u = primeiroListaAdj(v, g);
    while (u != VERTICE_INVALIDO) {
        int i = vertDest(u, g);

        if (cor[i] == BRANCO) {
            visitaConexo(g, i, cor);
        }

        u = proxListaAdj(v, g, u);
    }

    cor[v] = PRETO;
}

int componentesConexos(Grafo* g) {
    verificaValGrafo(g);

    int nVert = obtemNrVert(g);
    int* cor = (int*) malloc(sizeof(int) * nVert);
    int contComponente = 0;

    for (int i = 0; i < nVert; i++) {
        cor[i] = BRANCO;
    }

    for (int i = 0; i < nVert; i++) {
        if (cor[i] == BRANCO) {
            contComponente++;
            printf("Componente %d: ", contComponente);
            visitaConexo(g, i, cor);
            printf("\n");
        }
    }

    free(cor);
    return contComponente;
}