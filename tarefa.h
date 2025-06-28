#ifndef TAREFA_H
#define TAREFA_H  // Evita múltiplas inclusões deste cabeçalho

// Constantes utilizadas para limitar tamanhos de campos e do sistema em geral
#define MAX_TAREFAS 100      
#define TAM_NOME 50          
#define TAM_DESC 128      
#define ALTURA 9             
#define LARGURA 70

// Estrutura que representa uma tarefa no sistema
typedef struct {
  char nome[TAM_NOME];            // Nome da tarefa
  char descricao[TAM_DESC];      // Descrição detalhada da tarefa
  int concluida;              // Indica se a tarefa foi concluída (1 = sim, 0 = não)
} Tarefa;

// Declarações de funções para gestão do array de tarefas

//Limpa o buffer de entrada (stdin)
void limpar_entrada();

// Adiciona uma nova tarefa ao array
void adicionar_tarefa(Tarefa *tarefas, int *qtd);

// Remove uma tarefa existente do array
void remover_tarefa(Tarefa *tarefas, int *qtd);

// Permite modificar os dados de uma tarefa existente
void alterar_tarefas(Tarefa *tarefas, int qtd);

// Marca uma tarefa como concluída
void concluir_tarefa(Tarefa *tarefas, int qtd);

#endif  // Fim da proteção contra múltiplas inclusões
