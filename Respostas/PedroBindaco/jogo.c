#include "jogo.h"
#include "mapa.h"
#include "jogador.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

struct Jogo{
    Mapa * mapa;
    Vector * jogadores;
    int qtdJogadores;

};

void criaJogo(Mapa * m, Vector * jogadores){
    Jogo * jogo = (Jogo*)calloc(1, sizeof(Jogo));
    jogo->mapa = m;
    jogo->jogadores = jogadores;
    jogo->qtdJogadores = VectorSize(jogadores);
    return jogo;
}

void desalocaJogo(Jogo * jogo){
    VectorDestroy(jogo->jogadores, desalocaJogador);
}