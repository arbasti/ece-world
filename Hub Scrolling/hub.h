//
// Created by Basti on 02/05/2023.
//

#ifndef OFF_HEADER_H
#define OFF_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "time.h"

#define SCREEN_W 640
#define SCREEN_H 448
#define MAP_W 2048
#define MAP_H 2048

typedef struct
{
    int x;
    int y;
} coords;

typedef struct
{
    int x;
    int y;
    int dxy;
    int tickets;
    BITMAP* skin;
} players;

typedef struct
{
    int x;
    int y;
} map;

map moves_camera(players joueur, map carte);
players moves_player(players joueur, BITMAP* map_collision);

players pipe_main(players joueur, int pixel);


#endif //OFF_HEADER_H