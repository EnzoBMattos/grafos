#include "grafos.h"
#include "fila_vertices.h"

void visitaLargura(int origem, Grafo* g, int cor[], int antecessor[], int distancia[]);
void buscaEmLargura(Grafo* g);
void menorCaminho(int v1, int v2, Grafo* g);

