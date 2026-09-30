//
// Created by Basti on 02/05/2023.
//

#include "hub.h"

map moves_camera(players joueur, map carte)
{
    carte.x = joueur.x - SCREEN_W/2;
    carte.y = joueur.y - SCREEN_H/2;

    if (carte.x < 0)
    {
        carte.x = 0;
    }
    if (carte.x > 2048)
    {
        carte.x = 2048;
    }
    if (carte.y < 0)
    {
        carte.y = 0;
    }
    if (carte.y > 2048)
    {
        carte.y = 2048;
    }

    //printf("Carte x : %d", carte.x);
    //printf("Carte y : %d", carte.y);

    return carte;
}

players moves_player(players joueur, BITMAP* map_collision)
{
    int pixel;

    if (key[KEY_UP])
    {
        pixel = getpixel(map_collision, joueur.x, joueur.y);
        if (getr(pixel) != 255)
        {
            joueur.y -= joueur.dxy;
        }
    }

    if (key[KEY_DOWN])
    {
        pixel = getpixel(map_collision, joueur.x, joueur.y + 16);
        if (getr(pixel) != 255)
        {
            joueur.y += joueur.dxy;
        }
    }

    if (key[KEY_LEFT])
    {
        pixel = getpixel(map_collision, joueur.x, joueur.y);
        if (getr(pixel) != 255)
        {
            joueur.x -= joueur.dxy;
        }
    }

    if (key[KEY_RIGHT])
    {
        pixel = getpixel(map_collision, joueur.x +24, joueur.y);
        if (getr(pixel) != 255)
        {
            joueur.x += joueur.dxy;
        }
    }

    return joueur;
}
