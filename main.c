#include <stdio.h>
#include "tarefa.h"
#include "arquivo.h"
#include "menu.h"

int main() {
    Tarefa tarefas[MAX_TAREFAS]; //Cria um vetor (array) chamado tarefas, com capacidade máxima definida por MAX_TAREFAS.
    int qtd = carregar_tarefas(tarefas, MAX_TAREFAS //Chama a função carregar_tarefas, que lê do arquivo as tarefas previamente salvas.
    int opcao;
    do {
        mostrar_menu();// Chama a função mostrar_menu() para exibir as opções disponíveis ao usuário.
        scanf("%d", &opcao);
        executar_opcao(opcao, tarefas, &qtd);
    } while (opcao != 6);
    salvar_tarefas(tarefas, qtd); //Após o usuário sair do programa, as tarefas atuais são salvas no arquivo, garantindo que as alterações não sejam perdidas.

    return 0;
}

