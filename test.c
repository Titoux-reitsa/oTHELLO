#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "fonctions.h"

int Possible_vect[8][2]={{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};
	if(coup==64){
		return 0;
	}
	int j = coup%8;
	int i = coup/8;
	bool played = Is_possible(tableau,i,j,couleur,Possible_vect);
	if(played)swap(tableau,i,j,couleur,Possible_vect);

	return 1;
