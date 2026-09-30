//
// Created by gammp on 28/04/2023.
//

#ifndef INC_1__PROJET_ECE_WORLD_GAME1_H
#define INC_1__PROJET_ECE_WORLD_GAME1_H

#include <allegro.h>
#include <time.h>
#include <stdlib.h>
#define MAX_BOIS 2
#define MAX_MAP 3
#define TEMP 24


void traverse(BITMAP* map[MAX_MAP],BITMAP* map_buff,BITMAP* person,BITMAP* title,int* ticket1,int* ticket2,BITMAP* sprites[MAX_BOIS],int turn,int* score2,BITMAP* mario[5],BITMAP* princess,BITMAP* nombre[10], SAMPLE * music,int* score_1,int* score_2,char joueur1[],char joueur2[],SAMPLE* victory);

#endif //INC_1__PROJET_ECE_WORLD_GAME1_H
