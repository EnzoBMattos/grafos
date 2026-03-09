#include <stdbool.h>
#define MAX_NUM_VERT 100 // indica número máximo de vértices
#define ERRO -1 // valor que indica erro
#define VERTICE_INVALIDO -1 // valor que indica vértice inválido
#define ARESTA_NULA -1 // valor que indica inexistência de aresta

typedef int Peso;

typedef struct {
    Peso matrizAdj[MAX_NUM_VERT][MAX_NUM_VERT];
    int numVert;
} Grafo;

typedef int ApontadorVertAdj;

bool inicializaGrafo(Grafo* g, int numVert);
int obtemNrVert(Grafo* g);
Peso obtemPesoAresta(int v1, int v2, Grafo* g);
void verificaValVert(int v, Grafo* g);
void insereAresta(int v1, int v2, Peso p, Grafo* g);
bool existeAresta(int v1, int v2, Grafo* g);
bool removeAresta(int v1, int v2, Peso* p, Grafo* g);
bool listaAdjVazia(int v, Grafo* g);
int primeiroListaAdj(int v, Grafo* g);
ApontadorVertAdj proxListaAdj(ApontadorVertAdj v, int atual, Grafo* g);
void imprimeGrafo(Grafo* g);
void liberaGrafo(Grafo* g);