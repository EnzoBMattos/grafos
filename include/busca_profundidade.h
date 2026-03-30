#include "grafos.h"

void visitaProfundidade(int v, Grafo* g, int* tempo, int cor[], int desc[], int term[], int ant[]);
void buscaProfundidade(Grafo* g);
void imprimeCaminho(int v1, int v2, int ant[], Grafo* g);
void visitaCaminho(int v, int ant[], int cor[], Grafo* g);
bool existeCaminho(int v1, int v2, Grafo* g);
void visitaAciclico(int v, Grafo* g, bool* resp, int cor[], int ant[]);
bool grafoAciclico(Grafo* g);
void visitaConexo(Grafo* g, int v, int cor[]);
int componentesConexos(Grafo* g);