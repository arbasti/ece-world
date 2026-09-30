#include "title.h"

int play_game = 0;

void affichage_ecran(BITMAP *SF,BITMAP *title,BITMAP *fond,BITMAP *map,BITMAP* start){
    blit(map,fond,0,0,0/*(SCREEN_W/2)-256/2,100*/,0,SCREEN_W,SCREEN_H);
    //masked_blit(SF, title, 0, 0, (SCREEN_W/2)-160, 150, SCREEN_W, SCREEN_H);
    masked_blit(start,title,0,0,(SCREEN_W/2)-64,391,SCREEN_W,SCREEN_H);
    //textprintf_ex(title, font, 10, 10, makecol(255, 255, 255), -1, "x = %d, y = %d", mouse_x, mouse_y);
    blit(fond, title, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    show_mouse(title);
    blit(title, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    if (mouse_x >= (SCREEN_W/2)-64 && mouse_x <=(SCREEN_W/2)-64+128 && mouse_y >= 391 && mouse_y <=391+43 && mouse_b & 1) {
        play_game = 2;
    }
}


//
// Created by gammp on 24/04/2023.
//
