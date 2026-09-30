//
// Created by Basti on 12/05/2023.
//

#ifndef OFF_GOOMBATTACK_H
#define OFF_GOOMBATTACK_H

#include "../Hub Scrolling/hub.h"
#include "allegro.h"
#include "time.h"
#include "stdlib.h"
#include "unistd.h"

typedef struct
{
    int x;
    int y;
    int dxy;
    int direction;
    int moving;
    int jumping;
    int points;
    int compteur_anim_perso;
    time_t jump_begin;
    BITMAP* animation_left[5];
    BITMAP* animation_right[5];
} goombattack_player;

typedef struct
{
    int active;
    int lvl;
    int x;
    int y;
    int compteur_anim_goomba;
    time_t goomba_begin;
    time_t goomba_death;
} goombattack_goomba;

typedef struct
{
    time_t game_begin;
    goombattack_player joueur[2];

    int nb_goomba;
    goombattack_goomba goombas[7];
    BITMAP* goomba_anim[3];
    time_t spawn_goomba_begin;
} t_game;


int goombattack_main(int* ticket1,int* ticket2,BITMAP * title,SAMPLE* music,SAMPLE* saut,SAMPLE* victory);

t_game goombattack_init(t_game jeu);

t_game moves_goombattack(t_game jeux, BITMAP* map_collision);

t_game jump_goombattack(t_game jeux, BITMAP* map_collision,SAMPLE* saut);



t_game goomba_function_goombattack(t_game jeux);

t_game kill_goomba_goombattack(t_game jeux, int i, int pixel1, int pixel2, int pixel3, int pixel4,SAMPLE* saut);


#endif //OFF_GOOMBATTACK_H
