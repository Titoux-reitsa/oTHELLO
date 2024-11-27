#include <stdio.h>
#include <stdbool.h>
#include "fonctions.h"

int tab_ref_pontos[8][8]={{500 ,-150,30,10,10,30,-150,500 },
                          {-150,-250,0 ,0 ,0 ,0 ,-250,-150},
                          {30  ,0   ,1 ,2 ,2 ,1 ,0   ,30  },
                          {10  ,0   ,2 ,16,16,2 ,0   ,10  },
                          {10  ,0   ,2 ,16,16,2 ,0   ,10  },
                          {30  ,0   ,1 ,2 ,2 ,1 ,0   ,30  },
                          {-150,-250,0 ,0 ,0 ,0 ,-250,-150},
                          {500 ,-150,30,10,10,30,-150,500 }};

int anal_tab_pontos(int plateau[8][8],int couleur){
    int score=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(plateau[i][j]==couleur){
                score+=tab_ref_pontos[i][j];
            }
        }
    }
    return score;
}
int IA(int plateau[Lenght_tab][Lenght_tab], int Indice_player,int coup_nul[2]){
    int Possible_vect[8][2];
    coup_nul[0]=64;
    coup_nul[1]=-1000;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            int play=Is_possible(plateau, i, j, Indice_player, Possible_vect);
            if(play>0){
                coup_nul[0]=i*8+j;
                if(anal_tab_pontos(plateau, Indice_player)>coup_nul[1]){
                    coup_nul[1]=anal_tab_pontos(plateau, Indice_player);
                    coup_nul[0]=i*8+j;
                }
            }
        }
    }
    return coup_nul[0];
}
