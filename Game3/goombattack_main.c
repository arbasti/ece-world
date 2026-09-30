//
// Created by Basti on 12/05/2023.
//

#include "goombattack.h"

int goombattack_condition_victoire(goombattack_player joueur[2])
{
    if (joueur[0].points == 20 || joueur[1].points == 20)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int goombattack_main(int* ticket1,int* ticket2,BITMAP * title,SAMPLE * music ,SAMPLE* saut,SAMPLE* victory) {
    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));
    BITMAP *menu3 = load_bitmap("../Images/goombattack/menu_goombattack.bmp", NULL);
    BITMAP *rule = create_bitmap(SCREEN_W, SCREEN_H);

    int game = 0;
    int *p_game = &game;

    // Initialisation du Jeu
    t_game jeux = goombattack_init(jeux);

    // BITMAP buffer d'affichage
    BITMAP *page;
    page = create_bitmap(SCREEN_W, SCREEN_H);
    clear_bitmap(page);

    // Charger la map_goombattack
    BITMAP *fond = load_bitmap("../images/goombattack/map_goombattack.bmp", NULL);
    if (!fond) {
        allegro_message("prb chargement image map_goombattack");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    // Charger la map_goombattack_collision
    BITMAP *map_collision = load_bitmap("../images/goombattack/map_goombattack_collision.bmp", NULL);
    if (!map_collision) {
        allegro_message("prb chargement image map_goombattack_collision");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

while(!key[KEY_ENTER]){
    clear_bitmap(rule);
    blit(menu3, rule, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    blit(rule, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
}
    play_sample(music, 255, 128, 1000, 0);
    while (!game)
    {
        clear_bitmap(page);

        // Déplacement du joueur
        jeux = moves_goombattack(jeux, map_collision);

        // Saut du joueur
        jeux = jump_goombattack(jeux, map_collision,saut);

        // Spawn un Goombas
        jeux = goomba_function_goombattack(jeux);

        // Affichage de la map
        blit(fond, page, 0, 0, 0, 0, SCREEN_W, SCREEN_H);


        // Affichages des Goombas
        for (int i = 0; i < 7; i++)
        {
            if (jeux.goombas[i].active)
            {
                masked_blit(jeux.goomba_anim[jeux.goombas[i].compteur_anim_goomba], page, 0, 0, jeux.goombas[i].x, jeux.goombas[i].y, SCREEN_W, SCREEN_H);
                jeux.goombas[i].compteur_anim_goomba = (jeux.goombas[i].compteur_anim_goomba + 1) % 2;
            }
            else
            {
                if (difftime(time(NULL), jeux.goombas[i].goomba_death) < 1)
                {
                    jeux.nb_goomba -= 1;
                    masked_blit(jeux.goomba_anim[2], page, 0, 0, jeux.goombas[i].x, jeux.goombas[i].y, SCREEN_W, SCREEN_H);
                }
            }
        }


        // Affichage du Joueur
        for (int i = 0; i < 2; i++)
        {
            if (jeux.joueur[i].direction)
            {
                if (!jeux.joueur[i].jumping)
                {
                    if (!jeux.joueur[i].moving)
                    {
                        masked_blit(jeux.joueur[i].animation_right[0], page, 0, 0, jeux.joueur[i].x, jeux.joueur[i].y, SCREEN_W,SCREEN_H);
                    }
                    else
                    {
                        masked_blit(jeux.joueur[i].animation_right[2 + jeux.joueur[i].compteur_anim_perso], page, 0, 0, jeux.joueur[i].x, jeux.joueur[i].y, SCREEN_W,SCREEN_H);
                        jeux.joueur[i].compteur_anim_perso = (jeux.joueur[i].compteur_anim_perso + 1) % 3;
                    }
                }
                else
                {
                    masked_blit(jeux.joueur[i].animation_right[1], page, 0, 0, jeux.joueur[i].x, jeux.joueur[i].y, SCREEN_W,SCREEN_H);
                }
            }
            else
            {
                if (!jeux.joueur[i].jumping)
                {
                    if (!jeux.joueur[i].moving)
                    {
                        masked_blit(jeux.joueur[i].animation_left[0], page, 0, 0, jeux.joueur[i].x, jeux.joueur[i].y, SCREEN_W,SCREEN_H);
                    }
                    else
                    {
                        masked_blit(jeux.joueur[i].animation_left[2 + jeux.joueur[i].compteur_anim_perso], page, 0, 0, jeux.joueur[i].x, jeux.joueur[i].y, SCREEN_W,SCREEN_H);
                        jeux.joueur[i].compteur_anim_perso = (jeux.joueur[i].compteur_anim_perso + 1) % 3;
                    }
                }
                else
                {
                    masked_blit(jeux.joueur[i].animation_left[1], page, 0, 0, jeux.joueur[i].x, jeux.joueur[i].y, SCREEN_W,SCREEN_H);
                }
            }
            // Pour gérer les animations des personnages
            jeux.joueur[i].moving = 0;
        }




        // Afficher le nombre de point à l'écran
        textprintf_ex(page, font, 10, 10, makecol(0, 0, 0), -1, "Joueur 1 :");
        textprintf_ex(page, font, 10, 20, makecol(0, 0, 0), -1, "Point(s) = %d", jeux.joueur[0].points);


        textprintf_ex(page, font, 520, 10, makecol(0, 0, 0), -1, "Joueur 2 :");
        textprintf_ex(page, font, 520, 20, makecol(0, 0, 0), -1, "Point(s) = %d", jeux.joueur[1].points);

        // Afficher le timer
        unsigned long timer = (unsigned long) difftime(time(NULL), jeux.game_begin);
        textprintf_ex(page, font, 10, 440, makecol(0, 0, 0), -1, "Timer = %lds", timer);


        blit(page, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

        game = goombattack_condition_victoire(jeux.joueur);
    }
    stop_sample(music);


    // On regarde qui a gagné
    clear_bitmap(title);
    play_sample(victory, 255, 128, 1000, 0);
    if (jeux.joueur[0].points < jeux.joueur[1].points)
    {
        *ticket1+=2;
        textprintf_ex(title,font,640/2,448/2,makecol(255,255,255),-1," gagne");
        masked_blit(jeux.joueur[1].animation_right[0], title, 0, 0, (640/2)-30, (448/2), SCREEN_W, SCREEN_H);
    }
    if (jeux.joueur[0].points > jeux.joueur[1].points)
    {
        *ticket2+=2;
        textprintf_ex(title,font,640/2,448/2,makecol(255,255,255),-1," gagne");
        masked_blit(jeux.joueur[0].animation_right[0], title, 0, 0, (640/2)-30, (448/2), SCREEN_W, SCREEN_H);
    }

    blit(title,screen,0,0,0,0,SCREEN_W,SCREEN_H);

    rest(11000);
    // Ajouter écran de victoire
    /*
    while (!key[KEY_ENTER])
    {
        clear_bitmap(page);
    }
     */

    return 0;
}
