//
// Created by Basti on 12/05/2023.
//

#include "goombattack.h"

t_game moves_goombattack(t_game jeux, BITMAP* map_collision)
{
    int pixel1;
    int pixel2;

    for (int i = 0; i < 2; i++)
    {
        if (i == 0)
        {
            if (key[KEY_W]) // Z
            {
                pixel1 = getpixel(map_collision, jeux.joueur[i].x, jeux.joueur[i].y - jeux.joueur[i].dxy);
                pixel2 = getpixel(map_collision, jeux.joueur[i].x + 31, jeux.joueur[i].y - jeux.joueur[i].dxy);
                if ( (getr(pixel1) != 255 && getr(pixel2) != 255) || jeux.joueur[i].jumping )
                {
                    jeux.joueur[i].y -= jeux.joueur[i].dxy;
                    jeux.joueur[i].moving = 1;
                }
            }

            if (key[KEY_S])
            {
                pixel1 = getpixel(map_collision, jeux.joueur[i].x, jeux.joueur[i].y + jeux.joueur[i].dxy + 31);
                pixel2 = getpixel(map_collision, jeux.joueur[i].x + 31, jeux.joueur[i].y + jeux.joueur[i].dxy + 31);
                if ( (getr(pixel1) != 255 && getr(pixel2) != 255) || jeux.joueur[i].jumping )
                {
                    jeux.joueur[i].y += jeux.joueur[i].dxy;
                    jeux.joueur[i].moving = 1;
                }
            }

            if (key[KEY_A]) // Q
            {
                pixel1 = getpixel(map_collision, jeux.joueur[i].x - jeux.joueur[i].dxy, jeux.joueur[i].y);
                pixel2 = getpixel(map_collision, jeux.joueur[i].x - jeux.joueur[i].dxy, jeux.joueur[i].y + 31);
                if ( (getr(pixel1) != 255 && getr(pixel2) != 255) || jeux.joueur[i].jumping )
                {
                    jeux.joueur[i].x -= jeux.joueur[i].dxy;
                    jeux.joueur[i].moving = 1;
                    jeux.joueur[i].direction = 0;
                }
            }

            if (key[KEY_D])
            {
                pixel1 = getpixel(map_collision, jeux.joueur[i].x + jeux.joueur[i].dxy + 31, jeux.joueur[i].y);
                pixel2 = getpixel(map_collision, jeux.joueur[i].x + jeux.joueur[i].dxy + 31, jeux.joueur[i].y + 31);
                if ( (getr(pixel1) != 255 && getr(pixel2) != 255) || jeux.joueur[i].jumping )
                {
                    jeux.joueur[i].x += jeux.joueur[i].dxy;
                    jeux.joueur[i].moving = 1;
                    jeux.joueur[i].direction = 1;
                }
            }
        }
        else
        {
            if (key[KEY_I]) // Haut
            {
                pixel1 = getpixel(map_collision, jeux.joueur[i].x, jeux.joueur[i].y - jeux.joueur[i].dxy);
                pixel2 = getpixel(map_collision, jeux.joueur[i].x + 31, jeux.joueur[i].y - jeux.joueur[i].dxy);
                if ( (getr(pixel1) != 255 && getr(pixel2) != 255) || jeux.joueur[i].jumping )
                {
                    jeux.joueur[i].y -= jeux.joueur[i].dxy;
                    jeux.joueur[i].moving = 1;
                }
            }

            if (key[KEY_K]) // Bas
            {
                pixel1 = getpixel(map_collision, jeux.joueur[i].x, jeux.joueur[i].y + jeux.joueur[i].dxy + 31);
                pixel2 = getpixel(map_collision, jeux.joueur[i].x + 31, jeux.joueur[i].y + jeux.joueur[i].dxy + 31);
                if ( (getr(pixel1) != 255 && getr(pixel2) != 255) || jeux.joueur[i].jumping )
                {
                    jeux.joueur[i].y += jeux.joueur[i].dxy;
                    jeux.joueur[i].moving = 1;
                }
            }

            if (key[KEY_J]) // Gauche
            {
                pixel1 = getpixel(map_collision, jeux.joueur[i].x - jeux.joueur[i].dxy, jeux.joueur[i].y);
                pixel2 = getpixel(map_collision, jeux.joueur[i].x - jeux.joueur[i].dxy, jeux.joueur[i].y + 31);
                if ( (getr(pixel1) != 255 && getr(pixel2) != 255) || jeux.joueur[i].jumping )
                {
                    jeux.joueur[i].x -= jeux.joueur[i].dxy;
                    jeux.joueur[i].moving = 1;
                    jeux.joueur[i].direction = 0;
                }
            }

            if (key[KEY_L]) // Droite
            {
                pixel1 = getpixel(map_collision, jeux.joueur[i].x + jeux.joueur[i].dxy + 31, jeux.joueur[i].y);
                pixel2 = getpixel(map_collision, jeux.joueur[i].x + jeux.joueur[i].dxy + 31, jeux.joueur[i].y + 31);
                if ( (getr(pixel1) != 255 && getr(pixel2) != 255) || jeux.joueur[i].jumping )
                {
                    jeux.joueur[i].x += jeux.joueur[i].dxy;
                    jeux.joueur[i].moving = 1;
                    jeux.joueur[i].direction = 1;
                }
            }
        }


        if (jeux.joueur[i].x < 0)
        {
            jeux.joueur[i].x = 0;
        }
        else if (jeux.joueur[i].x > SCREEN_W)
        {
            jeux.joueur[i].x = SCREEN_W;
        }
        else if (jeux.joueur[i].y < 0)
        {
            jeux.joueur[i].y = 0;
        }
        else if (jeux.joueur[i].y > SCREEN_W)
        {
            jeux.joueur[i].y = SCREEN_W;
        }
    }


    return jeux;
}


t_game jump_goombattack(t_game jeux, BITMAP* map_collision,SAMPLE* saut)
{
    for (int i = 0; i < 2; i++)
    {
        if (jeux.joueur[i].jumping == 1)
        {
            time_t jump_end = time(NULL);
            if (difftime(jump_end, jeux.joueur[i].jump_begin) > 1)
            {
                int pixel1 = getpixel(map_collision, jeux.joueur[i].x, jeux.joueur[i].y);
                int pixel2 = getpixel(map_collision, jeux.joueur[i].x + 31, jeux.joueur[i].y);
                int pixel3 = getpixel(map_collision, jeux.joueur[i].x, jeux.joueur[i].y + 31);
                int pixel4 = getpixel(map_collision, jeux.joueur[i].x + 31, jeux.joueur[i].y + 31);

                if (getr(pixel1) == 255 || getr(pixel2) == 255 || getr(pixel3) == 255 || getr(pixel4) == 255)
                {
                    jeux.joueur[i].jumping = 1;
                    jeux.joueur[i].jump_begin = time(NULL);
                    jeux = kill_goomba_goombattack(jeux, i, pixel1, pixel2, pixel3, pixel4,saut);
                }
                else
                {
                    jeux.joueur[i].jumping = 0;
                }
            }
        }


        if (i == 0 && key[KEY_SPACE] && !jeux.joueur[i].jumping)
        {
            jeux.joueur[i].jumping = 1;
            jeux.joueur[i].jump_begin = time(NULL);
        }
        else if (i == 1 && key[KEY_ENTER] && !jeux.joueur[i].jumping)
        {
            jeux.joueur[i].jumping = 1;
            jeux.joueur[i].jump_begin = time(NULL);
        }
    }

    return jeux;
}
