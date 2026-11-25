#include "solicitacao.h"
#include "jogo.h"
#include "mapa.h"
#include "celula.h"
#include "jogador.h"
#include <stdio.h>
#include <stdlib.h>

void imprimeJogadoresNaCasa(Jogo *jogo, int casa){
    Vector * jogadores = obtemJogadoresJogo(jogo);
    int jaImprimiu = 0;
    for (int i = 0; i<VectorSize(jogadores); i++){
        Jogador * jogadorAtual = VectorGet(jogadores, i);
        if (obtemPosicaoJogador(jogadorAtual)!= casa){
            continue;
        }
        if (jaImprimiu) {
            printf(", ");
        } else {
            printf(" <- ");
        }
        printf("%s", obtemNomeJogador(jogadorAtual));
        jaImprimiu = 1;
    }
}

void imprimeEstadoJogadores(Jogo * jogo){
    Vector * jogadores = obtemJogadoresJogo(jogo);
    for(int i = 0; i < obtemQtdJogadoresJogo(jogo); i++){
        printEstadoJogador(VectorGet(jogadores, i));
    }
}

void imprimeEstado(Jogo * jogo){
    printf("=========== ESTADO ============\n");
    printf("[INICIO]");
    imprimeJogadoresNaCasa(jogo, 0);
    printf("\n");
    
    imprimeCelulasMapa(obtemMapaJogo(jogo));

    printf("[FIM]");
    imprimeJogadoresNaCasa(jogo, obtemPosicaoFimMapa(obtemMapaJogo(jogo)));
    printf("\n");
    printf("-------------------------------\n");
    imprimeEstadoJogadores(jogo);
    imprimeSituacao(jogo);
    printf("===============================\n");
}

void imprimeRanking(Jogo * jogo){
    Vector * jogadores = obtemJogadoresJogo(jogo);
    int n = VectorSize(jogadores);

    Jogador ** ordenados = (Jogador**)calloc(1, n * sizeof(Jogador *));
    for (int i = 0; i < n; i++){
        ordenados[i] = VectorGet(jogadores, i);
    }

    qsort(ordenados, n, sizeof(Jogador *), comparaOrdJogador);

    printf("=========== RANKING ===========\n");
    for (int i = 0; i < n; i++){
        printRankingJogador(ordenados[i], i + 1);
    }
    printf("===============================\n");

    free(ordenados);
}

void imprimeSituacao(Jogo *jogo){
    Vector *jogadores = obtemJogadoresJogo(jogo);
    int fim = obtemPosicaoFimMapa(obtemMapaJogo(jogo));

    for (int i = 0; i < VectorSize(jogadores); i++){
        Jogador *jogadorAtual = VectorGet(jogadores, i);
        if (obtemPosicaoJogador(jogadorAtual) == fim){
            printf("- Situacao: VENCEDOR %s\n", obtemNomeJogador(jogadorAtual));
            return;
        }
    }
    printf("- Situacao: EM ANDAMENTO\n");
}

void imprimeRelatorioJogo(Jogo * jogo){
    Vector * jogadores = obtemJogadoresJogo(jogo);
    int n = VectorSize(jogadores);
    int jogadas = 0, disputas = 0, monstros = 0;
    for (int i = 0; i < n; i++){
        Jogador * jogadorAtual = VectorGet(jogadores, i);
        jogadas += obtemJogadasJogador(jogadorAtual);
        disputas += obtemDisputasVencidasJogador(jogadorAtual);
        monstros += obtemMonstrosDerrotadosJogador(jogadorAtual);
    }
    printf("========= RELATORIO ===========\n");

    printf("- Celulas do mapa: %d\n", obtemQtdCelulasMapa(obtemMapaJogo(jogo)));
    printf("- Jogadores: %d\n", n);
    printf("- Jogadas totais: %d\n", jogadas);
    printf("- Disputas: %d\n", disputas);
    printf("- Monstros derrotados: %d\n", monstros);

    imprimeSituacao(jogo);

    printf("-------------------------------\n");
    for (int i = 0; i < n; i++){
        printRelatorioJogador(VectorGet(jogadores, i));
    }
    printf("===============================\n");


}