#include <stdio.h>          
#include "ficheiro.h"       

#define FILENAME "tarefas.dat"  // Nome do ficheiro onde as tarefas são armazenadas

// Função para carregar as tarefas armazenadas num ficheiro binário
void carregar_tarefas(Tarefa *tarefas, int *qtd) {
  FILE *file = fopen(FILENAME, "rb");  // Abre o ficheiro em modo leitura binária
  if (!file) return;                   // Se o ficheiro não existir, termina a função
  fread(qtd, sizeof(int), 1, file);    // Lê a quantidade de tarefas armazenadas
  fread(tarefas, sizeof(Tarefa), *qtd, file); // Lê as tarefas do ficheiro para o array
  fclose(file);                        // Fecha o ficheiro
}

// Função para guardar tarefas num ficheiro binário
void guardar_tarefas(Tarefa *tarefas, int qtd) {
  FILE *file = fopen(FILENAME, "wb");  // Abre o ficheiro em modo escrita binária
  if (!file) {                         // Verifica se houve erro ao abrir o ficheiro
    printf("Erro ao guardar tarefas!\n");
    return;
  }
  fwrite(&qtd, sizeof(int), 1, file);         // Escreve a quantidade de tarefas
  fwrite(tarefas, sizeof(Tarefa), qtd, file); // Escreve o array de tarefas no ficheiro
  fclose(file);                               // Fecha o ficheiro
}
