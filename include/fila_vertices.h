#include <stdbool.h>
typedef struct aux {
    int vertice;
    struct aux* prox;
} No;

typedef struct {
    No* inicio;
    No* fim;
} Fila;

void inicializarFila(Fila* f);
void entrarFila(Fila* f, int vertice);
int sairFila(Fila* f);
void deletaFila(Fila* f);
bool filaVazia(Fila* f);