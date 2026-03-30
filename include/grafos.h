#ifndef GRAFO_H
#define GRAFO_H

#ifdef MATRIZ
    #include "grafo_matrizAdj.h"
#else
    #include "grafo_listaAdj.h"
#endif

#endif

bool inicializaGrafo(Grafo* g, int numVert);
int obtemNrVert(Grafo* g);
Peso obtemPesoAresta(int v1, int v2, Grafo* g);
void verificaValVert(int v, Grafo* g);
void insereAresta(int v1, int v2, Peso p, Grafo* g);
bool existeAresta(int v1, int v2, Grafo* g);
bool removeAresta(int v1, int v2, Peso* p, Grafo* g);
bool listaAdjVazia(int v, Grafo* g);
ApontadorVertAdj primeiroListaAdj(int v, Grafo* g);
ApontadorVertAdj proxListaAdj(int v, Grafo* g, ApontadorVertAdj atual);
void imprimeGrafo(Grafo* g);
void liberaGrafo(Grafo* g);
int vertDest(ApontadorVertAdj p, Grafo* g);