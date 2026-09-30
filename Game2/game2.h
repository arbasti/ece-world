//
// Created by gammp on 12/05/2023.
//

#ifndef INC_1__PROJET_ECE_WORLD_GAME2_H
#define INC_1__PROJET_ECE_WORLD_GAME2_H
#include <allegro.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX_KOOPA 5

void tir_au_ballon(BITMAP* title,int turn,int* ticket1,int* ticket2,BITMAP* ballon,BITMAP* ciel,BITMAP* kooap[2],BITMAP* nombre[2],char joueur1[],char joueur2[],SAMPLE* music,int* score_1,int* score_2,int* gamescore2,SAMPLE* sound,SAMPLE* victory);


#endif //INC_1__PROJET_ECE_WORLD_GAME2_H
