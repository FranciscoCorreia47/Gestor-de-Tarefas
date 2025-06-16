#include <stdio.h>
#include "ficheiro.h"


#define FILENAME "tarefas.txt"


void carregar_tarefas(Tarefa *tarefas, int *qtd) {
  FILE *file = fopen(FILENAME, "rb");
  if (!file) return;
  fread(qtd, sizeof(int), 1, file);
  fread(tarefas, sizeof(Tarefa), *qtd, file);
  fclose(file);
}


void guardar_tarefas(Tarefa *tarefas, int qtd) {
  FILE *file = fopen(FILENAME, "wb");
  if (!file) {
    printf("Erro ao guardar tarefas!\n");
    return;
  }
  fwrite(&qtd, sizeof(int), 1, file);
  fwrite(tarefas, sizeof(Tarefa), qtd, file);
  fclose(file);
}
