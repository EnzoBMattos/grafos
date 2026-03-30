CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -Wno-unused-parameter
SRC_COMMON = main.c src/bprofundidade.c src/blargura.c src/fila.c
SRC_LISTA = src/grafos_lista.c
SRC_MATRIZ = src/grafos_matriz.c
EXEC_LISTA = main_lista
EXEC_MATRIZ = main_matriz

# Regra padrão
all: lista

# Compilar com lista de adjacência
lista:
	$(CC) $(CFLAGS) $(SRC_COMMON) $(SRC_LISTA) -o $(EXEC_LISTA)

# Compilar com matriz de adjacência
matriz:
	$(CC) $(CFLAGS) -DMATRIZ $(SRC_COMMON) $(SRC_MATRIZ) -o $(EXEC_MATRIZ)

# Limpar executáveis
clean:
	rm -f $(EXEC_LISTA) $(EXEC_MATRIZ)
