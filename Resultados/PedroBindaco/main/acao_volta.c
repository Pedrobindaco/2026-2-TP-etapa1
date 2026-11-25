#include "acao_volta.h"
#include "jogador.h"
#include <stdio.h>
#include <stdlib.h>

struct Volta{
    int qtd;
};

/**
 * @brief Aloca dinamicamente uma ação do tipo VOLTA e guarda nela a quantidade
 * @param qtd Quantidade de casas avancadas
 * @return Ponteiro para o Volta criado
 */
Volta *criaVolta(int qtd){
    Volta * a = (Volta*)calloc(1, sizeof(Volta));
    a->qtd = qtd;
    return a;
}

/**
 * @brief Lê da entrada padrão, na mesma linha, quantidade (a palavra VOLTA
 * já deve ter sido lida) e cria o Volta com criaVolta.
 * @return Ponteiro para o ouro criado
 */
Volta *leVolta(){
    int qtd;
    scanf("%d\n", &qtd);
    Volta * a = criaVolta(qtd);
    return a;
}

/**
 * @brief Converte o dado genérico para Volta
 * @param dado Ponteiro genérico para o Volta
 * @param j Jogador que parou na célula
 * @return Quantidade casas para o jogador andar
 */
int executaVolta(void *dado, Jogador *j){
    Volta * a = (Volta*)dado;
    return -a->qtd;
}

/**
 * @brief Converte o dado genérico para Volta e imprime, sem quebra de linha:
 * "VOLTA <qtd>"
 * @param dado Ponteiro genérico para o Volta
 */
void imprimeVolta(void *dado){
    Volta * a = (Volta*)dado;
    printf("VOLTA %d", a->qtd);
}

/**
 * @brief Converte o dado genérico para Volta e libera a memória alocada para ele
 * @param dado Ponteiro genérico para o Volta
 */
void desalocaVolta(void *dado){
    Volta * a = (Volta*)dado;
    free(a);
}

