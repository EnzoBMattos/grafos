#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX_NUM_VERT 100 // indica número máximo de vértices
#define ERRO -1 // valor que indica erro
#define VERTICE_INVALIDO NULL // valor que indica vértice inválido
#define ARESTA_NULA -1 // valor que indica inexistência de aresta

typedef int Peso;

typedef struct str_aresta {
    int vdest;
    Peso peso;
    struct str_aresta* prox;
} Aresta;

typedef struct {
    Aresta** listaAdj;
    int numVert;
} Grafo; 

typedef Aresta* ApontadorVertAdj;

bool inicializaGrafo(Grafo* g, int numVert);
int obtemNrVert(Grafo* g);
Peso obtemPesoAresta(int v1, int v2, Grafo* g);
void verificaValVert(int v, Grafo* g);
void verificaValGrafo(Grafo* g);
void insereAresta(int v1, int v2, Peso p, Grafo* g);
bool existeAresta(int v1, int v2, Grafo* g);
bool removeAresta(int v1, int v2, Peso* p, Grafo* g);
bool listaAdjVazia(int v, Grafo* g);
ApontadorVertAdj primeiroListaAdj(int v, Grafo* g);
ApontadorVertAdj proxListaAdj(int v, Grafo* g, ApontadorVertAdj atual);
void imprimeGrafo(Grafo* g);
void liberaGrafo(Grafo* g);
int vertDest(ApontadorVertAdj p, Grafo* g);