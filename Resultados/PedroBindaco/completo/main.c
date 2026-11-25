#include "acao_monstro.h"
#include "acao_ouro.h"
#include "mapa.h"
#include "jogador.h"
#include "celula.h"
#include "cadastro.h"
#include "vector.h"
#include "jogo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char proximaAcao;
    Mapa * m = criaMapa();
    cadastraMapa(m);
    Vector * jogadores = VectorConstruct();
    proximaAcao = cadastraJogadores(jogadores);
    Jogo * jogo = criaJogo(m, jogadores);
    while(proximaAcao != 'F'){
        rodaJogo(jogo, proximaAcao);
        scanf(" %c", &proximaAcao);
    }
    desalocaJogo(jogo);
    return 0;
}