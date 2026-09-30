//
// Created by Basti on 12/05/2023.
//

#include "goombattack.h"


t_game spawn_goomba_goombattack(t_game jeux)
{
    if (jeux.nb_goomba != 7)
    {
        int random_goomba = rand() % 7;
        int random_lvl = rand() % 3 + 1;
        while (jeux.goombas[random_goomba].active == 1)
        {
            random_goomba = (random_goomba + 1) % 7;
        }
        jeux.goombas[random_goomba].active = 1;
        jeux.goombas[random_goomba].lvl = random_lvl;
        jeux.nb_goomba += 1;
        jeux.goombas[random_goomba].goomba_begin = time(NULL);
    }

    return jeux;
}


t_game end_goomba_goombattack(t_game jeux)
{
    for (int i = 0; i < 7; i++)
    {
        if (jeux.goombas[i].active == 1)
        {
            time_t goomba_end = time(NULL);
            unsigned long dif = difftime(goomba_end, jeux.goombas[i].goomba_begin);
            if (jeux.goombas[i].lvl == 1)
            {
                if (dif > 10)
                {
                    jeux.goombas[i].active = 0;
                    jeux.nb_goomba -= 1;
                }
            }
            else if (jeux.goombas[i].lvl == 2)
            {
                if (dif > 7.5)
                {
                    jeux.goombas[i].active = 0;
                    jeux.nb_goomba -= 1;
                }
            }
            else if (jeux.goombas[i].lvl == 3)
            {
                if (dif > 5)
                {
                    jeux.goombas[i].active = 0;
                    jeux.nb_goomba -= 1;
                }
            }
        }
    }

    return jeux;
}


t_game goomba_function_goombattack(t_game jeux)
{

    time_t spawn_goomba_end = time(NULL);
    if (difftime(spawn_goomba_end, jeux.spawn_goomba_begin) > 1)
    {
        jeux = spawn_goomba_goombattack(jeux);
        jeux.spawn_goomba_begin = spawn_goomba_end;
    }
    jeux = end_goomba_goombattack(jeux);

    return jeux;
}


t_game kill_goomba_goombattack(t_game jeux, int i, int pixel1, int pixel2, int pixel3, int pixel4,SAMPLE* saut)
{
    pixel1 = getb(pixel1);
    pixel2 = getb(pixel2);
    pixel3 = getb(pixel3);
    pixel4 = getb(pixel4);
    if (pixel1 != 0 && jeux.goombas[pixel1 - 1].active)
    {
        play_sample(saut, 255, 128, 1000, 0);
        jeux.goombas[pixel1 - 1].active = 0;
        jeux.goombas[pixel1 - 1].goomba_death = time(NULL);
        jeux.joueur[i].points += 1;
    }
    else if (pixel2 != 0 && jeux.goombas[pixel2 - 1].active)
    {
        play_sample(saut, 255, 128, 1000, 0);
        jeux.goombas[pixel2 - 1].active = 0;
        jeux.goombas[pixel2 - 1].goomba_death = time(NULL);
        jeux.joueur[i].points += 1;
    }
    else if (pixel3 != 0 && jeux.goombas[pixel3 - 1].active)
    {
        play_sample(saut, 255, 128, 1000, 0);
        jeux.goombas[pixel3 - 1].active = 0;
        jeux.goombas[pixel3 - 1].goomba_death = time(NULL);
        jeux.joueur[i].points += 1;
    }
    else if (pixel4 != 0 && jeux.goombas[pixel4 - 1].active)
    {
        play_sample(saut, 255, 128, 1000, 0);
        jeux.goombas[pixel4 - 1].active = 0;
        jeux.goombas[pixel4 - 1].goomba_death = time(NULL);
        jeux.joueur[i].points += 1;
    }

    return jeux;
}
