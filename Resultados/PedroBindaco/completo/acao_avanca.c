#include "acao_avanca.h"
#include "jogador.h"
#include <stdio.h>
#include <stdlib.h>

struct Avanca{
    int qtd;
};

/**
 * @brief Aloca dinamicamente uma ação do tipo AVANCA e guarda nela a quantidade
 * @param qtd Quantidade de casas avancadas
 * @return Ponteiro para o Avanca criado
 */
Avanca *criaAvanca(int qtd){
    Avanca * a = (Avanca*)calloc(1, sizeof(Avanca));
    a->qtd = qtd;
    return a;
}

/**
 * @brief Lê da entrada padrão, na mesma linha, quantidade (a palavra AVANCA
 * já deve ter sido lida) e cria o Avanca com criaAvanca.
 * @return Ponteiro para o ouro criado
 */
Avanca *leAvanca(){
    int qtd;
    scanf("%d\n", &qtd);
    Avanca * a = criaAvanca(qtd);
    return a;
}

/**
 * @brief Converte o dado genérico para Avanca e adiciona valor
 * @param dado Ponteiro genérico para o Avanca
 * @param j Jogador que parou na célula
 * @return Quantidade casas para o jogador andar
 */
int executaAvanca(void *dado, Jogador *j){
    Avanca * a = (Avanca*)dado;
    return a->qtd;
}

/**
 * @brief Converte o dado genérico para Avanca e imprime, sem quebra de linha:
 * "AVANCA <qtd>"
 * @param dado Ponteiro genérico para o Avanca
 */
void imprimeAvanca(void *dado){
    Avanca * a = (Avanca*)dado;
    printf("AVANCA %d", a->qtd);
}

/**
 * @brief Converte o dado genérico para Avanca e libera a memória alocada para ele
 * @param dado Ponteiro genérico para o Avanca
 */
void desalocaAvanca(void *dado){
    Avanca * a = (Avanca*)dado;
    free(a);
}

