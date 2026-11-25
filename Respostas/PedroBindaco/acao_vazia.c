#include "acao_vazia.h"
#include "jogador.h"
#include <stdio.h>
#include <stdlib.h>

struct Vazia{
    char nada;
};

/**
 * @brief Aloca dinamicamente uma ação do tipo VAZIA
 * 
 * @return Ponteiro para o Vazia criado
 */
Vazia *criaVazia(){
    Vazia * v = (Vazia*)calloc(1, sizeof(Vazia));
    v->nada = 'a';
    return v;
}

/**
 * @brief Lê da entrada padrão, na mesma linha, quantidade (a palavra VAZIA
 * já deve ter sido lida) e cria o Vazia com criaVazia.
 * @return Ponteiro para a vazia criada
 */
Vazia *leVazia(){
    Vazia * v = criaVazia();
    return v;
}

/**
 * @brief Converte o dado genérico para Vazia e não faz nada
 * @param dado Ponteiro genérico para o Vazia
 * @param j Jogador que parou na célula
 * @return 0
 */
int executaVazia(void *dado, Jogador *j){
    return 0;
}

/**
 * @brief Converte o dado genérico para Vazia e imprime, sem quebra de linha:
 * "VAZIA"
 * @param dado Ponteiro genérico para o Vazia
 */
void imprimeVazia(void *dado){
    printf("VAZIA");
}

/**
 * @brief Converte o dado genérico para Vazia e libera a memória alocada para ele
 * @param dado Ponteiro genérico para o Vazia
 */
void desalocaVazia(void *dado){
    Vazia * v = (Vazia*)dado;
    free(v);
}

