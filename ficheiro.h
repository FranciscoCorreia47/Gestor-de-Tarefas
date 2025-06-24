#ifndef FICHEIRO_H       // Verifica se o cabeçalho já foi incluído anteriormente
#define FICHEIRO_H       // Define a macro de inclusão única para evitar múltiplas inclusões

#include "tarefa.h"      // Inclui o cabeçalho onde a estrutura 'Tarefa' está definida

// Declaração da função que carrega tarefas de um ficheiro binário.
// Parâmetros:
// - tarefas: array onde as tarefas serão carregadas
// - qtd: ponteiro para inteiro onde será armazenada a quantidade de tarefas lidas
void carregar_tarefas(Tarefa *tarefas, int *qtd);

// Declaração da função que guarda tarefas num ficheiro binário.
// Parâmetros:
// - tarefas: array com as tarefas a serem guardadas
// - qtd: número de tarefas presentes no array
void guardar_tarefas(Tarefa *tarefas, int qtd);

#endif  // Fecha a condição de inclusão única
