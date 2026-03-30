#include <stdio.h>
#include "grafos.h"
#include "busca_profundidade.h"

int main () {
    Grafo g;
    inicializaGrafo(&g, 10);
    insereAresta(1, 2, 1, &g);
    insereAresta(1, 3, 1, &g);
    insereAresta(3, 4, 1, &g);
    insereAresta(4, 7, 1, &g);
    insereAresta(9, 0, 1, &g);
    imprimeGrafo(&g);

    if(existeCaminho(1, 7, &g)) {
        printf("eh um caminho\n");
    }
    else {
        printf("não existe caminho\n");
    }

    if(grafoAciclico(&g)) {
        printf("o grafo eh aciclico\n");
    }
    else {
        printf("o grafo nao eh aciclico\n");
    }

    printf("ha %d componentes conexos no grafo\n", componentesConexos(&g));

    return 0;
}