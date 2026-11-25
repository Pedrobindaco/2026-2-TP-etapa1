#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogador.h"
#include "acao_ouro.h"
#include "celula.h"


struct Ouro{
    int qtd;
};

/**
 * @brief Aloca dinamicamente uma ação do tipo OURO e guarda nela a quantidade
 * @param qtd Quantidade de ouro
 * @return Ponteiro para o ouro criado
 */
Ouro *criaOuro(int qtd){
    Ouro * o = (Ouro*)calloc(1, sizeof(Ouro));
    o->qtd = qtd;
    return o;
}

/**
 * @brief Lê da entrada padrão, na mesma linha, quantidade (a palavra OURO
 * já deve ter sido lida) e cria o ouro com criaOuro.
 * @return Ponteiro para o ouro criado
 */
Ouro *leOuro(){
    int qtd;
    scanf("%d\n", &qtd);
    Ouro * o = criaOuro(qtd);
    return o;
}

/**
 * @brief Converte o dado genérico para ouro e adiciona valor
 * @param dado Ponteiro genérico para o ouro
 * @param j Jogador que parou na célula
 * @return Quantidade de ouro a ser adicionada ao jogador
 */
int executaOuro(void *dado, Jogador *j){
    Ouro * o = (Ouro*)dado;
    adicionaOuroJogador(j, o->qtd);
    return 0;
}

/**
 * @brief Converte o dado genérico para ouro e imprime, sem quebra de linha:
 * "OURO <qtd>"
 * @param dado Ponteiro genérico para o ouro
 */
void imprimeOuro(void *dado){
    Ouro * o = (Ouro*)dado;
    printf("OURO %d", o->qtd);
}

/**
 * @brief Converte o dado genérico para ouro e libera a memória alocada para ele
 * @param dado Ponteiro genérico para o ouro
 */
void desalocaOuro(void *dado){
    Ouro * o = (Ouro*)dado;
    free(o);
}