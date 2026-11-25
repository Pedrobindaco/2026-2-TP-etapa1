#include "solicitacao.h"
#include "jogo.h"
#include "mapa.h"
#include "celula.h"
#include <stdio.h>

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

void imprimeEstado(Jogo * j){
    printf("[INICIO]");
    imprimeJogadoresNaCasa(j, 0);
    printf("\n");
    
    imprimeCelulasMapa(obtemMapaJogo(j));

    printf("[FIM]");
    imprimeJogadoresNaCasa(j, obtemPosicaoFimMapa(obtemMapaJogo(j)));
    printf("\n");
}