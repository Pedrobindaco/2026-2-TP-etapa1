#ifndef _ACAO_VAZIA_H_
#define _ACAO_VAZIA_H_
#include "jogador.h"

typedef struct Vazia Vazia;

/**
 * @brief Aloca dinamicamente uma ação do tipo VAZIA
 * @return Ponteiro para o Vazia criado
 */
Vazia *criaVazia();

/**
 * @brief Lê da entrada padrão, na mesma linha, quantidade (a palavra VAZIA
 * já deve ter sido lida) e cria o Vazia com criaVazia.
 * @return Ponteiro para a vazia criada
 */
Vazia *leVazia();

/**
 * @brief Converte o dado genérico para Vazia e não faz nada
 * @param dado Ponteiro genérico para o Vazia
 * @param j Jogador que parou na célula
 * @return 0
 */
int executaVazia(void *dado, Jogador *j);

/**
 * @brief Converte o dado genérico para Vazia e imprime, sem quebra de linha:
 * "VAZIA"
 * @param dado Ponteiro genérico para o Vazia
 */
void imprimeVazia(void *dado);

/**
 * @brief Converte o dado genérico para Vazia e libera a memória alocada para ele
 * @param dado Ponteiro genérico para o Vazia
 */
void desalocaVazia(void *dado);
 

#endif //_ACAO_VAZIA_H
