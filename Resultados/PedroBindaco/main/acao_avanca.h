#ifndef _ACAO_AVANCA_H_
#define _ACAO_AVANCA_H_

#include "jogador.h"

typedef struct Avanca Avanca;

/**
 * @brief Aloca dinamicamente uma ação do tipo AVANCA e guarda nela a quantidade
 * @param qtd Quantidade de casas avancadas
 * @return Ponteiro para o Avanca criado
 */
Avanca *criaAvanca(int qtd);

/**
 * @brief Lê da entrada padrão, na mesma linha, quantidade (a palavra AVANCA
 * já deve ter sido lida) e cria o Avanca com criaAvanca.
 * @return Ponteiro para o ouro criado
 */
Avanca *leAvanca();

/**
 * @brief Converte o dado genérico para ouro e adiciona valor
 * @param dado Ponteiro genérico para o ouro
 * @param j Jogador que parou na célula
 * @return Quantidade de ouro a ser adicionada ao jogador
 */
int executaAvanca(void *dado, Jogador *j);

/**
 * @brief Converte o dado genérico para Avanca e imprime, sem quebra de linha:
 * "AVANCA <qtd>"
 * @param dado Ponteiro genérico para o Avanca
 */
void imprimeAvanca(void *dado);

/**
 * @brief Converte o dado genérico para Avanca e libera a memória alocada para ele
 * @param dado Ponteiro genérico para o Avanca
 */
void desalocaAvanca(void *dado);

#endif // _ACAO_AVANCA_H_
