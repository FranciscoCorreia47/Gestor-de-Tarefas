#include <stdio.h>
#include "arquivo.h"

// Função para salvar tarefas no arquivo texto
int salvar_tarefas(Tarefa *tarefas, int qtd) {
    FILE *f = fopen(ARQUIVO_TAREFAS, "w");//Abre o arquivo definido por ARQUIVO_TAREFAS para escrita ("w").
    if (!f) return 0;//Se f for NULL, significa que o arquivo não pôde ser aberto;A função retorna 0 indicando falha.

    for (int i = 0; i < qtd; i++) {
        fprintf(f, "%d|%s|%d\n", tarefas[i].id, tarefas[i].descricao, tarefas[i].concluida);// Escreve cada tarefa no arquivo em formato texto, separando os campos com |.id: número da tarefa.descricao: texto descritivo.concluida: flag (0 ou 1) indicar se a tarefa foi concluída ou não.
    }
    fclose(f); //Fecha o arquivo após a escrita.

    return 1;
}
// Função para carregar tarefas do arquivo texto
int carregar_tarefas(Tarefa *tarefas, int max) {
    FILE *f = fopen(ARQUIVO_TAREFAS, "r");//Abre o arquivo para leitura.
    if (!f) return 0; //Se o arquivo não existir ou não puder ser aberto, retorna 0.
    int qtd = 0;
    while (fscanf(f, "%d|%99[^|]|%d\n", &tarefas[qtd].id, tarefas[qtd].descricao, &tarefas[qtd].concluida) == 3 && qtd < max) {
        qtd++; //Lê linha por linha do arquivo.
    }
    fclose(f);
    return qtd;
}
