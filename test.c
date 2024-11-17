#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "fonctions.h"

bool test(int plateau_entre[8][8],int plateau_sortie[8][8],int ligne, int colonne, int Indice_player,int Possible_vect[8][2]){
    if(Is_possible(plateau_entre,ligne,colonne, Indice_player, Possible_vect)){
        swap(plateau_entre,ligne,colonne, Indice_player, Possible_vect);
        int cmpt =0;
        for(int i=0 ; i < 8 ; i++){
            for(int j=0 ; j < 8 ; j++){
                if((plateau_entre[i][j]  == plateau_sortie[i][j])){
                    cmpt++ ;
                    if (cmpt == 64 ) {
                        return 1; 
                        printf ("test valide");
                    }
                    
                }
                else break;
            }
        }
       
    }
    printf("les deux tableaux ne correspondent pas");
    return 0;
}