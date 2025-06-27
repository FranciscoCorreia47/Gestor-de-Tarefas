#include <stdio.h>    
#include <stdlib.h>    
#include <string.h>    
#include "menu.h"      // Declarações dos menus
#include "tarefa.h"    // Estrutura e funções de tarefas
#include "ficheiro.h"  // Leitura/escrita de ficheiros

// Função que apresenta o menu principal ao utilizador e executa as ações conforme opção escolhida.
void menu_principal(Tarefa *tarefas, int *qtd){
  short int opcao;

  do{
    system("cls||clear");  // Limpa o terminal (compatível com Windows e Unix)
    printf("---Seja Bem Vindo ao Gestor de Tarefas!---");
    printf("\n");
    printf("      O que pretende fazer?      ");
    printf("\n");
    // Interface textual do menu
    printf("+----------------------------------+\n");
    printf("|        Gestor de Tarefas         |\n");
    printf("+----------------------------------+\n");
    printf("|       [1] Adicionar Tarefas      |\n");
    printf("|       [2] Eliminar Tarefas       |\n");
    printf("|       [3] Listar Tarefas         |\n");
    printf("|       [4] Alterar Tarefas        |\n");
    printf("|       [5] Concluir Tarefas       |\n");
    printf("|       [0] Sair                   |\n");
    printf("+----------------------------------+\n");
    printf("|\n+-> ");
    scanf("%hd", &opcao);  // Lê a opção escolhida

    // Executa a ação correspondente  
    switch(opcao){
      case 1: adicionar_tarefa(tarefas, qtd); break;
      case 2: remover_tarefa(tarefas, qtd); break;
      case 3: menu_listar(tarefas, *qtd); break;
      case 4: alterar_tarefas(tarefas, *qtd); break;
      case 5: concluir_tarefa(tarefas, *qtd); break;
      case 0:
        guardar_tarefas(tarefas, *qtd);  // Guarda os dados antes de sair
        opcao = -1;                      // Encerra o ciclo
        break;
    }
  }while(opcao != -1);
}

//Função auxiliar de menu_listar, que imprime a linha de separação, no estilo "+----+"
void print_linha_separacao() {
    printf("+");
    for (int i = 0; i < LARGURA - 2; i++) printf("-");
    printf("+\n");
}

//Função auxiliar de menu_listar, que imprime texto centralizado, baseado numa largura
void print_centralizado(const char *texto, int largura) {
    int comprimento = strlen(texto);
    int alinhamento = (largura - comprimento) / 2;
    printf("| %*s%s%*s |\n", alinhamento, "", texto, (largura - comprimento - alinhamento) - 2, "");
}

//Função auxiliar de menu_listar, que imprime texto alinhado à esquerda, baseado numa largura
void print_esquerda(const char *texto, int largura) {
    printf("| %-*s |\n", largura - 4, texto);
}

void menu_listar(Tarefa *tarefas, int qtd) {
    for (int i = 0; i < qtd; i++) {
        print_linha_separacao();

        // Imprimir o ID
        char string_id[20];
        snprintf(string_id, sizeof(string_id), "Tarefa %d", i);
        print_centralizado(string_id, LARGURA - 2);

        print_linha_separacao();

        // Imprimir o nome
        print_esquerda(tarefas[i].nome, LARGURA);

        print_linha_separacao();

        // Imprimir a descrição
        char desc[TAM_DESC + 1];
        strncpy(desc, tarefas[i].descricao, TAM_DESC);
        desc[TAM_DESC] = '\0';

        int comp_desc = strlen(desc);
        int tam_max_linha = LARGURA - 4; // -4 contando com "| " e " |"

        for (int pos = 0; pos < comp_desc; pos += tam_max_linha) {
            char linha[tam_max_linha + 1];
            strncpy(linha, desc + pos, tam_max_linha);
            linha[tam_max_linha] = '\0';
            print_esquerda(linha, LARGURA);
        }

        print_linha_separacao();

        // Imprimir o Status
        char status[20];
        snprintf(status, sizeof(status), "Status: %s", 
                tarefas[i].concluida ? "Concluída" : "Pendente");
        print_esquerda(status, LARGURA);

        print_linha_separacao();
        printf("\n"); // Espaço entre tarefas
    }

    printf("Pressione Enter para continuar...");
    limpar_entrada();
    getchar();
}
