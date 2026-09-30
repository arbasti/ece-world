#include "Joueur.h"
#include <stdio.h>


void enregistrement(char* joueur1,char* joueur2){
    int i;
    char val;
    printf("Saisir le pseudo du joueur 1 : \n");
    for(i =0;i<10;i++){
        val = readkey();
        if(val == 13){
            break;
        }
        else{
            printf("%c",val);
            joueur1[i] = val;
        }
    }


        printf("\nSaisir le pseudo du joueur 2 : \n");
        i = 0;
        do {
            val = readkey();
            if (val != 13) {
                printf("%c", val);
                joueur2[i] = val;
            }
            i++;
        } while (val != 13);
        for(int j = 0;j<strlen(joueur2);j++){
            if(joueur2[j] == 7){
                joueur2[j] = ' ';
            }
        }
}

//
// Created by gammp on 18/05/2023.
//
