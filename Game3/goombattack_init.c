//
// Created by Basti on 13/05/2023.
//

#include "goombattack.h"

t_game goombattack_init_anim(t_game jeux)
{
    // Animation Personnage 1
    jeux.joueur[0].animation_right[0] = load_bitmap("../images/goombattack/mario_red/mario_standing_right.bmp", NULL);
    jeux.joueur[0].animation_right[1] = load_bitmap("../images/goombattack/mario_red/mario_jumping_right.bmp", NULL);
    jeux.joueur[0].animation_right[2] = load_bitmap("../images/goombattack/mario_red/mario_red_moving/mario_moving1_right.bmp", NULL);
    jeux.joueur[0].animation_right[3] = load_bitmap("../images/goombattack/mario_red/mario_red_moving/mario_moving2_right.bmp", NULL);
    jeux.joueur[0].animation_right[4] = load_bitmap("../images/goombattack/mario_red/mario_red_moving/mario_moving3_right.bmp", NULL);

    jeux.joueur[0].animation_left[0] = load_bitmap("../images/goombattack/mario_red/mario_standing_left.bmp", NULL);
    jeux.joueur[0].animation_left[1] = load_bitmap("../images/goombattack/mario_red/mario_jumping_left.bmp", NULL);
    jeux.joueur[0].animation_left[2] = load_bitmap("../images/goombattack/mario_red/mario_red_moving/mario_moving1_left.bmp", NULL);
    jeux.joueur[0].animation_left[3] = load_bitmap("../images/goombattack/mario_red/mario_red_moving/mario_moving2_left.bmp", NULL);
    jeux.joueur[0].animation_left[4] = load_bitmap("../images/goombattack/mario_red/mario_red_moving/mario_moving3_left.bmp", NULL);


    // Animation Personnage 2
    jeux.joueur[1].animation_right[0] = load_bitmap("../images/goombattack/mario_blue/mario_standing_right.bmp", NULL);
    jeux.joueur[1].animation_right[1] = load_bitmap("../images/goombattack/mario_blue/mario_jumping_right.bmp", NULL);
    jeux.joueur[1].animation_right[2] = load_bitmap("../images/goombattack/mario_blue/mario_moving/mario_moving1_right.bmp", NULL);
    jeux.joueur[1].animation_right[3] = load_bitmap("../images/goombattack/mario_blue/mario_moving/mario_moving2_right.bmp", NULL);
    jeux.joueur[1].animation_right[4] = load_bitmap("../images/goombattack/mario_blue/mario_moving/mario_moving3_right.bmp", NULL);

    jeux.joueur[1].animation_left[0] = load_bitmap("../images/goombattack/mario_blue/mario_standing_left.bmp", NULL);
    jeux.joueur[1].animation_left[1] = load_bitmap("../images/goombattack/mario_blue/mario_jumping_left.bmp", NULL);
    jeux.joueur[1].animation_left[2] = load_bitmap("../images/goombattack/mario_blue/mario_moving/mario_moving1_left.bmp", NULL);
    jeux.joueur[1].animation_left[3] = load_bitmap("../images/goombattack/mario_blue/mario_moving/mario_moving2_left.bmp", NULL);
    jeux.joueur[1].animation_left[4] = load_bitmap("../images/goombattack/mario_blue/mario_moving/mario_moving3_left.bmp", NULL);

    return jeux;
}


t_game goombattack_init(t_game jeux)
{
    jeux.joueur[0].x = SCREEN_W/2 - 50;
    jeux.joueur[0].y = SCREEN_H/2;
    jeux.joueur[1].x = SCREEN_W/2 + 50;
    jeux.joueur[1].y = SCREEN_H/2;

    for (int i = 0; i < 2; i++)
    {
        jeux.joueur[i].dxy = 1;
        jeux.joueur[i].direction = 1;
        jeux.joueur[i].moving = 0;
        jeux.joueur[i].jumping = 0;
        jeux.joueur[i].jump_begin = 0;
        jeux.joueur[i].points = 0;
        jeux.joueur[i].compteur_anim_perso = 0;
    }

    jeux = goombattack_init_anim(jeux);

    for (int i = 0; i < 7; i++)
    {
        jeux.goombas[i].active = 0;
        jeux.goombas[i].lvl = 0;
        jeux.goombas[i].goomba_begin = 0;
        jeux.goombas[i].compteur_anim_goomba = 0;
    }

    jeux.goombas[0].x = 80;
    jeux.goombas[0].y = 128;

    jeux.goombas[1].x = 256;
    jeux.goombas[1].y = 144;

    jeux.goombas[2].x = 400;
    jeux.goombas[2].y = 80;

    jeux.goombas[3].x = 512;
    jeux.goombas[3].y = 176;

    jeux.goombas[4].x = 144;
    jeux.goombas[4].y = 304;

    jeux.goombas[5].x = 336;
    jeux.goombas[5].y = 320;

    jeux.goombas[6].x = 480;
    jeux.goombas[6].y = 304;

    // Seule solution que j'ai trouvé pour empêcher que certain Goomba spawn en étant mort
    for (int i = 0; i < 7; i++)
    {
        jeux.goombas[i].goomba_death = time(NULL);
    }

    jeux.nb_goomba = 1; // 1 A cause du problème

    jeux.goomba_anim[0] = load_bitmap("../images/goombattack/goomba/goomba1.bmp", NULL);
    jeux.goomba_anim[1] = load_bitmap("../images/goombattack/goomba/goomba2.bmp", NULL);
    jeux.goomba_anim[2] = load_bitmap("../images/goombattack/goomba/goomba3.bmp", NULL);

    jeux.game_begin = time(NULL);
    jeux.spawn_goomba_begin = time(NULL);

    return jeux;
}
