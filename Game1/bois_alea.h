//
// Created by gammp on 05/05/2023.
//

#ifndef INC_1__PROJET_ECE_WORLD_BOIS_ALEA_H
#define INC_1__PROJET_ECE_WORLD_BOIS_ALEA_H
#include "game1.h"
#include <stdio.h>
#include <allegro.h>

void placement_1(int j,int i,int pos_x,int pos_y,int imgcourante,BITMAP* sprites[],BITMAP* title);
void placement_2(int j,int i,int pos_x,int pos_y,int imgcourante,BITMAP* sprites[],BITMAP* title);
void placement_3(int j,int i,int pos_x,int pos_y,int imgcourante,BITMAP* sprites[],BITMAP* title);
void placement_4(int j,int i,int pos_x,int pos_y,int imgcourante,BITMAP* sprites[],BITMAP* title);

//Si crossy road, ajouter ,int *fin
void collision_1(int * pos_perso_x,const int * pos_perso_y,int pos_x,int pos_x_inv,int pos_y,int j,int i,int direct,int dx);
void collision_2(int * pos_perso_x,const int * pos_perso_y,int pos_x,int pos_x_inv,int pos_y,int j,int i,int direct,int dx);
void collision_3(int * pos_perso_x,const int * pos_perso_y,int pos_x,int pos_x_inv,int pos_y,int j,int i,int direct,int dx);
void collision_4(int * pos_perso_x,const int * pos_perso_y,int pos_x,int pos_x_inv,int pos_y,int j,int i,int direct,int dx);

void out_1(int * pos_perso_x,const int * pos_perso_y,int pos_x,int pos_x_inv,int pos_y,int j,int i,int direct,int *fin);
void out_2(int * pos_perso_x,const int * pos_perso_y,int pos_x,int pos_x_inv,int pos_y,int j,int i,int direct,int *fin);
void out_3(int * pos_perso_x,const int * pos_perso_y,int pos_x,int pos_x_inv,int pos_y,int j,int i,int direct,int *fin);
void out_4(int * pos_perso_x,const int * pos_perso_y,int pos_x,int pos_x_inv,int pos_y,int j,int i,int direct,int *fin);

#endif //INC_1__PROJET_ECE_WORLD_BOIS_ALEA_H
