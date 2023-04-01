#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include <locale.h>
#include <malloc.h>
#include "chaine2.h"


char all[1000];



void menu()
    {
    	char T[30],P1[15],P2[15];
		lecture_chaine(T);
		ent_reel(T,P1,P2);
		affichage_chaine(P1,P2);
		char_to_num(P1);
		char_to_num_v(P2);
    	printf("\nLe nombre en lettres est : %s ",all);
	}

int main ()
    {
        menu();
    }
