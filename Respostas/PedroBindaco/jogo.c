#include "jogo.h"
#include "mapa.h"
#include "jogador.h"
#include "vector.h"
#include "solicitacao.h"
#include "rolagem.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Jogo{
    Mapa * mapa;
    Vector * jogadores;
    int qtdJogadores;
    int vez;
};

Jogo * criaJogo(Mapa * m, Vector * jogadores){
    Jogo * jogo = (Jogo*)calloc(1, sizeof(Jogo));
    jogo->mapa = m;
    jogo->jogadores = jogadores;
    jogo->qtdJogadores = VectorSize(jogadores);
    return jogo;
}

void desalocaJogo(Jogo * jogo){
    VectorDestroy(jogo->jogadores, desalocaJogador);
    desalocaMapa(jogo->mapa);
    free(jogo);
}

void rodaJogo(Jogo * jogo, char proximaAcao){
    if(proximaAcao == 'R'){
        int qtdRolagens;
        scanf("%*s"); //descarta OLAGEM
        scanf("%d", &qtdRolagens);
        executaRolagem(jogo, qtdRolagens);
    } else if (proximaAcao == 'E'){
        char tipo[21];
        scanf("%s", tipo);
        if(strcmp(tipo, "ESTADO") == 0){
            imprimeEstado(jogo);
        } else if(strcmp(tipo, "RANKING") == 0) {
            imprimeRanking(jogo);
        } else if(strcmp(tipo, "RELATORIO") == 0){
            imprimeRelatorioJogo(jogo);
        }
    }
}

Mapa *obtemMapaJogo(Jogo *jogo){
    return jogo->mapa;
}

Vector *obtemJogadoresJogo(Jogo *jogo){
    return jogo->jogadores;
}

int obtemQtdJogadoresJogo(Jogo *jogo){
    return jogo->qtdJogadores;
}

int obtemVezJogo(Jogo *jogo){
    return jogo->vez;
}

void avancaVezJogo(Jogo *jogo){
    jogo->vez = (jogo->vez+1) % jogo->qtdJogadores;
}