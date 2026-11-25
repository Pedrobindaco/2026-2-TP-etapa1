#include "cadastro.h"
#include "acao_vazia.h"
#include "acao_ouro.h"
#include "acao_monstro.h"
#include "acao_avanca.h"
#include "acao_volta.h"
#include "acao_item.h"
#include "mapa.h"
#include "celula.h"
#include "jogador.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cadastraMapa(Mapa * m){
    char tipo[21];
    scanf("%s %*s ", tipo);
    //le INICIO e descarta MAPA e qualquer espaco em branco depois
    while (1){
        scanf("%s ", tipo);
        if(strcmp(tipo, "FIM") == 0){
            scanf("%*s ");
            break;
        }
        if(strcmp(tipo, "OURO")== 0){
            insereCelulaMapa(m, leOuro(), executaOuro, imprimeOuro, desalocaOuro);
        } else if(strcmp(tipo, "MONSTRO")== 0){
            insereCelulaMapa(m, leMonstro(), executaMonstro, imprimeMonstro, desalocaMonstro);
        } else if(strcmp(tipo, "ITEM")== 0){
            insereCelulaMapa(m, leItem(), executaItem, imprimeItem, desalocaItem);
        } else if(strcmp(tipo, "AVANCA")== 0){
            insereCelulaMapa(m, leAvanca(), executaAvanca, imprimeAvanca, desalocaAvanca);
        } else if(strcmp(tipo, "VOLTA")== 0){
            insereCelulaMapa(m, leVolta(), executaVolta, imprimeVolta, desalocaVolta);
        } else if(strcmp(tipo, "VAZIA")== 0){
            insereCelulaMapa(m, leVazia(), executaVazia, imprimeVazia, desalocaVazia);
        }

    }
    
}

char cadastraJogadores(Vector * jogadores){
    char c;
    while (scanf(" %c", &c) == 1){
        if (c != 'J') return c;
        Jogador * j = leJogador();
        VectorPushBack(jogadores, j);
    }
    return '\0';
}

