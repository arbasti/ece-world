#include "bois_alea.h"

void placement_1(int j,int i,int pos_x,int pos_y,int imgcourante,BITMAP* sprites[],BITMAP* title){
    if(i == 1 || i == 4 || i == 5 || i == 10 || i == 12 || i == 13 || i == 16 || i == 19) {
        masked_blit(sprites[imgcourante], title, 0, 0, pos_x + (i * 128), pos_y - (j * 64), SCREEN_W,SCREEN_H);
    }
}

void placement_2(int j,int i,int pos_x,int pos_y,int imgcourante,BITMAP* sprites[],BITMAP* title){
    if (i == 0 || i == 2 || i == 4 || i == 8 || i == 11 || i == 12 || i == 15 || i == 17 || i == 19) {
        masked_blit(sprites[imgcourante], title, 0, 0, pos_x + (i * 128), pos_y - (j * 64), SCREEN_W,SCREEN_H);
    }
}

void placement_3(int j,int i,int pos_x,int pos_y,int imgcourante,BITMAP* sprites[],BITMAP* title){
    if (i == 5 || i == 6 || i == 7 || i == 10 || i == 2 || i == 17) {
        masked_blit(sprites[imgcourante], title, 0, 0, pos_x + (i * 128), pos_y - (j * 64), SCREEN_W,SCREEN_H);
    }
}

void placement_4(int j,int i,int pos_x,int pos_y,int imgcourante,BITMAP* sprites[],BITMAP* title){
    if (i == 2 || i == 3 || i == 11 || i == 10 || i == 17 || i == 18) {
        masked_blit(sprites[imgcourante], title, 0, 0, pos_x + (i * 128), pos_y - (j * 64), SCREEN_W,SCREEN_H);
    }
}

void collision_1(int * pos_perso_x,const int * pos_perso_y,int pos_x,int pos_x_inv,int pos_y,int j,int i,int direct,int dx){

    if (i == 1 || i == 4 || i == 5 || i == 10 || i == 12 || i == 13 || i == 16 || i == 19) {

        if(!direct) {
            if (*pos_perso_y >= pos_y - (j * 64) && *pos_perso_y < pos_y + 64 - (j * 64) &&
                *pos_perso_x >= pos_x + (i * 128) &&
                *pos_perso_x <= pos_x + 128 + (i * 128)) {
                *pos_perso_x += dx;


            }
        }
        if(direct) {
            if (*pos_perso_y >= pos_y - (j * 64) && *pos_perso_y < pos_y + 64 - (j * 64) &&
                *pos_perso_x >= pos_x_inv + (i * 128) &&
                *pos_perso_x <= pos_x_inv + 128 + (i * 128)) {

                *pos_perso_x -= dx;
            }
        }
    }
}

void collision_2(int * pos_perso_x,const int * pos_perso_y,int pos_x,int pos_x_inv,int pos_y,int j,int i,int direct,int dx){
    if (i == 0 || i == 2 || i == 4 || i == 8 || i == 11 || i == 12 || i == 15 || i == 17 || i == 19) {
        if(!direct) {
            if (*pos_perso_y >= pos_y - (j * 64) && *pos_perso_y < pos_y + 64 - (j * 64) &&
                *pos_perso_x >= pos_x + (i * 128) &&
                *pos_perso_x <= pos_x + 128 + (i * 128)) {
                *pos_perso_x += dx;
            }
        }
        if(direct) {
            if (*pos_perso_y >= pos_y - (j * 64) && *pos_perso_y < pos_y + 64 - (j * 64) &&
                *pos_perso_x >= pos_x_inv + (i * 128) &&
                *pos_perso_x <= pos_x_inv + 128 + (i * 128)) {
                *pos_perso_x -= dx;
            }
        }
    }
}

void collision_3(int * pos_perso_x,const int * pos_perso_y,int pos_x,int pos_x_inv,int pos_y,int j,int i,int direct,int dx){
    if (i == 5 || i == 6 || i == 7 || i == 10 || i == 2 || i == 17) {
        if(!direct) {
            if (*pos_perso_y >= pos_y - (j * 64) && *pos_perso_y < pos_y + 64 - (j * 64) &&
                *pos_perso_x >= pos_x + (i * 128) &&
                *pos_perso_x <= pos_x + 128 + (i * 128)) {
                *pos_perso_x += dx;
            }
        }
        if(direct) {
            if (*pos_perso_y >= pos_y - (j * 64) && *pos_perso_y < pos_y + 64 - (j * 64) &&
                *pos_perso_x >= pos_x_inv + (i * 128) &&
                *pos_perso_x <= pos_x_inv + 128 + (i * 128)) {
                *pos_perso_x -= dx;
            }
        }
    }
}

void collision_4(int * pos_perso_x,const int * pos_perso_y,int pos_x,int pos_x_inv,int pos_y,int j,int i,int direct,int dx){
    if (i == 2 || i == 3 || i == 11 || i == 10 || i == 17 || i == 18) {
        if(!direct) {
            if (*pos_perso_y >= pos_y - (j * 64) && *pos_perso_y < pos_y + 64 - (j * 64) &&
                *pos_perso_x >= pos_x + (i * 128) &&
                *pos_perso_x <= pos_x + 128 + (i * 128)) {
                *pos_perso_x += dx;
            }
        }
        if(direct) {
            if (*pos_perso_y >= pos_y - (j * 64) && *pos_perso_y < pos_y + 64 - (j * 64) &&
                *pos_perso_x >= pos_x_inv + (i * 128) &&
                *pos_perso_x <= pos_x_inv + 128 + (i * 128)) {
                *pos_perso_x -= dx;
            }
        }
    }
}

        void out_1(int * pos_perso_x,const int * pos_perso_y,int pos_x,int pos_x_inv,int pos_y,int j,int i,int direct,int *fin){
    if (!(i == 1 || i == 4 || i == 5 || i == 10 || i == 12 || i == 13 || i == 16 || i == 19)) {
        if(!direct) {
            if (*pos_perso_y > pos_y - (j * 64) && *pos_perso_y < pos_y + 64 - (j * 64) &&
                *pos_perso_x > pos_x + (i * 128) &&
                *pos_perso_x < pos_x + 128 + (i * 128)) {
                *fin=1;
            }
        }
        if(direct) {
            if (*pos_perso_y >= pos_y - (j * 64) && *pos_perso_y < pos_y + 64 - (j * 64) &&
                *pos_perso_x >= pos_x_inv + (i * 128) &&
                *pos_perso_x <= pos_x_inv + 128 + (i * 128)) {
                *fin=1;

            }
        }
    }
}
void out_2(int * pos_perso_x,const int * pos_perso_y,int pos_x,int pos_x_inv,int pos_y,int j,int i,int direct,int *fin){
    if (!(i == 0 || i == 2 || i == 4 || i == 8 || i == 11 || i == 12 || i == 15 || i == 17 || i == 19)) {
        if(!direct) {
            if (*pos_perso_y >= pos_y - (j * 64) && *pos_perso_y < pos_y + 64 - (j * 64) &&
                *pos_perso_x >= pos_x + (i * 128) &&
                *pos_perso_x <= pos_x + 128 + (i * 128)) {
                *fin=1;
            }
        }
        if(direct) {
            if (*pos_perso_y >= pos_y - (j * 64) && *pos_perso_y < pos_y + 64 - (j * 64) &&
                *pos_perso_x >= pos_x_inv + (i * 128) &&
                *pos_perso_x <= pos_x_inv + 128 + (i * 128)) {
                *fin=1;

            }
        }
    }
}


void out_3(int * pos_perso_x,const int * pos_perso_y,int pos_x,int pos_x_inv,int pos_y,int j,int i,int direct,int *fin){
    if (!(i == 5 || i == 6 || i == 7 || i == 10 || i == 2 || i == 17)) {
        if(!direct) {
            if (*pos_perso_y >= pos_y - (j * 64) && *pos_perso_y < pos_y + 64 - (j * 64) &&
                *pos_perso_x >= pos_x + (i * 128) &&
                *pos_perso_x <= pos_x + 128 + (i * 128)) {
                *fin=1;
            }
        }
        if(direct) {
            if (*pos_perso_y >= pos_y - (j * 64) && *pos_perso_y < pos_y + 64 - (j * 64) &&
                *pos_perso_x >= pos_x_inv + (i * 128) &&
                *pos_perso_x <= pos_x_inv + 128 + (i * 128)) {
                *fin=1;

            }
        }
    }
}


void out_4(int * pos_perso_x,const int * pos_perso_y,int pos_x,int pos_x_inv,int pos_y,int j,int i,int direct,int *fin){
    if (!(i == 2 || i == 3 || i == 11 || i == 10 || i == 17 || i == 18)) {
        if(!direct) {
            if (*pos_perso_y >= pos_y - (j * 64) && *pos_perso_y < pos_y + 64 - (j * 64) &&
                *pos_perso_x >= pos_x + (i * 128) &&
                *pos_perso_x <= pos_x + 128 + (i * 128)) {
                *fin=1;
            }
        }
        if(direct) {
            if (*pos_perso_y >= pos_y - (j * 64) && *pos_perso_y < pos_y + 64 - (j * 64) &&
                *pos_perso_x >= pos_x_inv + (i * 128) &&
                *pos_perso_x <= pos_x_inv + 128 + (i * 128)) {
                *fin=1;

            }
        }
    }
}



//
// Created by gammp on 05/05/2023.
//
