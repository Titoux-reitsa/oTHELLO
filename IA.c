#include <stdio.h>
#include <stdbool.h>
#include "fonctions.h"

int tab_ref_pontos[8][8]={{500 ,-150,30,10,10,30,-150,500 },
                          {-150,-2500,0 ,0 ,0 ,0 ,-2500,-150},
                          {30  ,0   ,1 ,2 ,2 ,1 ,0   ,30  },
                          {10  ,0   ,2 ,16,16,2 ,0   ,10  },
                          {10  ,0   ,2 ,16,16,2 ,0   ,10  },
                          {30  ,0   ,1 ,2 ,2 ,1 ,0   ,30  },
                          {-150,-2500,0 ,0 ,0 ,0 ,-2500,-150},
                          {500 ,-150,30,10,10,30,-150,500 }};

int anal_tab_pontos(int plateau[8][8],int couleur){
    int score=0;
    if(plateau[0][0]!=-1){tab_ref_pontos[0][1]=1;tab_ref_pontos[1][1]=1;tab_ref_pontos[1][0]=1;}
    if(plateau[7][7]!=-1){tab_ref_pontos[7][6]=1;tab_ref_pontos[6][6]=1;tab_ref_pontos[6][7]=1;}
    if(plateau[0][7]!=-1){tab_ref_pontos[0][6]=1;tab_ref_pontos[1][7]=1;tab_ref_pontos[1][6]=1;}
    if(plateau[7][0]!=-1){tab_ref_pontos[6][0]=1;tab_ref_pontos[6][1]=1;tab_ref_pontos[7][1]=1;}
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(plateau[i][j]==couleur){
                score+=tab_ref_pontos[i][j];
                
            }
        }
    }
    printf("score = %d\n",score);
    return score;
}
int IA(int plateau[Lenght_tab][Lenght_tab], int Indice_player,int my_color, int coup_nul[2],int profondeur){
    int coup_temp_point=coup_nul[1];
    int coup_temp=coup_nul[0];
   
        if(profondeur>0){
            int new_tab[8][8]; 
            for(int k=0;k<8;k++){
                for(int l=0;l<8;l++){
                    new_tab[k][l]=plateau[k][l];
                }
            }
            coup_nul[0]=IA(new_tab,Indice_player,my_color,coup_nul,profondeur-1);
            printf("%d profondeur",profondeur);
            int Possible_vect[8][2]= {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};
            int play=Is_possible(new_tab, coup_nul[0]%8, coup_nul[0]/8, Indice_player, Possible_vect);
            if(play>0){swap(new_tab, coup_nul[0]%8, coup_nul[0]/8, Indice_player, Possible_vect);}
            best_move(new_tab,Indice_player,coup_nul);
            return coup_nul[0];
        }
            
                
    return best_move(plateau,Indice_player,coup_nul);
}

int best_move(int plateau[Lenght_tab][Lenght_tab], int Indice_player, int coup_nul[2]){
    
    coup_nul[0]=64;
    coup_nul[1]=-100000;
    int cp_tmp=64;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            int new_tab[8][8]; 
            for(int k=0;k<8;k++){
                for(int l=0;l<8;l++){
                        new_tab[k][l]=plateau[k][l];
                }
            }
            int Possible_vect[8][2] = { {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0} };
            int play=Is_possible(new_tab, i, j, Indice_player, Possible_vect);
            
            if(play>0){
                
                swap(new_tab, i, j, Indice_player, Possible_vect);
                coup_nul[0]=i*8+j;
                int pts_temp=anal_tab_pontos(new_tab, Indice_player);
                
                    if(pts_temp>coup_nul[1]){
                        coup_nul[1]=pts_temp;
                        cp_tmp=i*8+j;
                    }
            }
        }
    }
    return cp_tmp;
}

