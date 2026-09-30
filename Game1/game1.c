#include "game1.h"
#include "bois_alea.h"

void traverse(BITMAP* map[MAX_MAP],BITMAP* map_buff,BITMAP* person,BITMAP* title,int* ticket1,int*ticket2,BITMAP* sprites[MAX_BOIS],int turn,int* score2,BITMAP* mario[5],BITMAP* princess,BITMAP* nombre[10],SAMPLE* music,int* score_1,int* score_2,char joueur1[],char joueur2[],SAMPLE* victory) {

    BITMAP *rule = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* menu1 = load_bitmap("../Images/Game1/menu.bmp",NULL);
    //Initialisation de la position des bouts de bois
    int pos_y = 448 - 192;
    int pos_x;
    int pos_x_inv;

    int pos_x_lent = -3 * 640;
    int pos_x_inv_lent = 0;
    int pos_x_norm = -3 * 640;
    int pos_x_inv_norm = 0;
    int pos_x_rap = -3 * 640;
    int pos_x_inv_rap = 0;

    int dx_lent = 1;
    int dx_norm = 2;
    int dx_rap = 3;

    int deplacement;

    int fin_de_jeu = 0;
    int *p_fin = &fin_de_jeu;

    //Initialisation de la position de la map
    int pos_map_y = 0;
    //Initialisation de la position de la grenouille
    int pos_perso_x = 0;
    int pos_perso_y = 448 - 32;

    int *p_pos_perso_x = &pos_perso_x;
    int *p_pos_perso_y = &pos_perso_y;
    //Activation de la touche directionnelle
    int appuie_up = 0;
    int appuie_down = 0;
    int appuie_right = 0;
    int appuie_left = 0;
    //Pour l'animation
    int cptimg = 0, tmpimg = 50, imgcourante = 0;
    int cpt = 0, tmp = 10, tmp2 = 50, imgc = 0;

    int mouv = 0;
    int inverse = 0;

    int scroll = 0;
    int debut = 1;
    int fin = 0;
    int debut_comptage = 0;
    srand(time(NULL));
    int compt_temps = 0, temps = 60 * 6;
    int compt_chrono = 0;

    int nb_temps_1, nb_temps_2, nb_temps_3;
    int compt_d, compt_c;

    int liste_placement[TEMP];
    for (int k = 0; k < TEMP; k++) {
        liste_placement[k] = rand() % 4; //rand() % 4
    }

    int liste_inver[TEMP];
    for (int k = 0; k < TEMP; k++) {
        liste_inver[k] = rand() % 2; //rand() % 2
    }

    int liste_vit[TEMP];
    for (int k = 0; k < TEMP; k++) {
        liste_vit[k] = rand() % 3; //rand() % 3
    }

    //Score des deux joueurs
    int score_joueur1 = 0, score_joueur2 = 0;
    int *p_score2 = &score_joueur2;

    if(turn == 1) {
        while(!key[KEY_ENTER]) {
            clear_bitmap(rule);
            blit(menu1, rule, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
            blit(rule, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        }
    }

    play_sample(music, 255, 128, 1000, 1);
    while (!key[KEY_DEL]) { //Tant que le joueur ne veut pas partir ou n'as pas fini
        clear_bitmap(title);
        rest(10);
        /*if (debut_comptage) {
            compt_temps++;
            printf("%d\n", compt_temps / 60);
            if (compt_temps > temps && pos_map_y == 0) {
                fin = 1;
            }
        }*/
        /*
        if (scroll) {
            compt_temps++;
            printf("%d\n", compt_temps);
            if (compt_temps > temps && pos_map_y == 0) {
                fin = 1;
            }
        }*/
        if (debut) {
            /*if (pos_perso_y < 384) {
                scroll = 1;
            }
            if (pos_map_y == 512 && scroll == 1) {
                debut = 0;
            }*/
            if (pos_perso_y < 128) {
                debut_comptage = 1;
            }
            blit(map[0], title, 0, 0, 0, pos_map_y, SCREEN_W, SCREEN_H);
            blit(map[1], title, 0, 0, 0, pos_map_y - 448, SCREEN_W, SCREEN_H);
        }
        if (fin) {
            blit(map[1], title, 0, 0, 0, pos_map_y, SCREEN_W, SCREEN_H);
            blit(map[2], title, 0, 0, 0, pos_map_y - 448, SCREEN_W, SCREEN_H);
            masked_blit(princess, title, 0, 0, 320, (pos_map_y - 448)+64, SCREEN_W, SCREEN_H);
        }

        if (!debut && !fin) {
            blit(map[1], title, 0, 0, 0, pos_map_y, SCREEN_W, SCREEN_H);
            blit(map[1], title, 0, 0, 0, pos_map_y - 448, SCREEN_W, SCREEN_H);
            if(pos_map_y == 448){
                pos_map_y = 0;
                fin = 1;
            }
        }

        cptimg++;
        if (cptimg >= tmpimg) {
            cptimg = 0;
            imgcourante++;
            if (imgcourante >= MAX_BOIS) // quand l'indice de l'image courante arrive à NIMAGE
                imgcourante = 0; // on recommence la séquence à partir de 0
        }
        cpt++;
        compt_chrono++;

        for (int j = 0; j < TEMP; j++) { //10 * (TEMP+1)
            for (int i = 0; i < 20; i++) {
                if (liste_placement[j] == 0) {
                    if (!liste_inver[j]) {
                        if (liste_vit[j] == 0) {
                            placement_1(j, i, pos_x_lent, pos_y, imgcourante, sprites, title);
                        }
                        if (liste_vit[j] == 1) {
                            placement_1(j, i, pos_x_norm, pos_y, imgcourante, sprites, title);
                        }
                        if (liste_vit[j] == 2) {
                            placement_1(j, i, pos_x_rap, pos_y, imgcourante, sprites, title);
                        }
                    }
                    if (liste_inver[j]) {
                        if (liste_vit[j] == 0) {
                            placement_1(j, i, pos_x_inv_lent, pos_y, imgcourante, sprites, title);
                        }
                        if (liste_vit[j] == 1) {
                            placement_1(j, i, pos_x_inv_norm, pos_y, imgcourante, sprites, title);
                        }
                        if (liste_vit[j] == 2) {
                            placement_1(j, i, pos_x_inv_rap, pos_y, imgcourante, sprites, title);
                        }
                    }
                }
                if (liste_placement[j] == 1) {
                    if (!liste_inver[j]) {
                        if (liste_vit[j] == 0) {
                            placement_2(j, i, pos_x_lent, pos_y, imgcourante, sprites, title);
                        }
                        if (liste_vit[j] == 1) {
                            placement_2(j, i, pos_x_norm, pos_y, imgcourante, sprites, title);
                        }
                        if (liste_vit[j] == 2) {
                            placement_2(j, i, pos_x_rap, pos_y, imgcourante, sprites, title);
                        }

                    }
                    if (liste_inver[j]) {
                        if (liste_vit[j] == 0) {
                            placement_2(j, i, pos_x_inv_lent, pos_y, imgcourante, sprites, title);
                        }
                        if (liste_vit[j] == 1) {
                            placement_2(j, i, pos_x_inv_norm, pos_y, imgcourante, sprites, title);
                        }
                        if (liste_vit[j] == 2) {
                            placement_2(j, i, pos_x_inv_rap, pos_y, imgcourante, sprites, title);
                        }
                    }
                }
                if (liste_placement[j] == 2) {
                    if (!liste_inver[j]) {
                        if (liste_vit[j] == 0) {
                            placement_3(j, i, pos_x_lent, pos_y, imgcourante, sprites, title);
                        }
                        if (liste_vit[j] == 1) {
                            placement_3(j, i, pos_x_norm, pos_y, imgcourante, sprites, title);
                        }
                        if (liste_vit[j] == 2) {
                            placement_3(j, i, pos_x_rap, pos_y, imgcourante, sprites, title);
                        }

                    }
                    if (liste_inver[j]) {
                        if (liste_vit[j] == 0) {
                            placement_3(j, i, pos_x_inv_lent, pos_y, imgcourante, sprites, title);
                        }
                        if (liste_vit[j] == 1) {
                            placement_3(j, i, pos_x_inv_norm, pos_y, imgcourante, sprites, title);
                        }
                        if (liste_vit[j] == 2) {
                            placement_3(j, i, pos_x_inv_rap, pos_y, imgcourante, sprites, title);
                        }
                    }
                }
                if (liste_placement[j] == 3) {
                    if (!liste_inver[j]) {
                        if (liste_vit[j] == 0) {
                            placement_4(j, i, pos_x_lent, pos_y, imgcourante, sprites, title);
                        }
                        if (liste_vit[j] == 1) {
                            placement_4(j, i, pos_x_norm, pos_y, imgcourante, sprites, title);
                        }
                        if (liste_vit[j] == 2) {
                            placement_4(j, i, pos_x_rap, pos_y, imgcourante, sprites, title);
                        }

                    }
                    if (liste_inver[j]) {
                        if (liste_vit[j] == 0) {
                            placement_4(j, i, pos_x_inv_lent, pos_y, imgcourante, sprites, title);
                        }
                        if (liste_vit[j] == 1) {
                            placement_4(j, i, pos_x_inv_norm, pos_y, imgcourante, sprites, title);
                        }
                        if (liste_vit[j] == 2) {
                            placement_4(j, i, pos_x_inv_rap, pos_y, imgcourante, sprites, title);
                        }
                    }
                }
            }
        }
        //Pour la position des différents bouts de bois, on changera directement dans le blit

        //Dans les conditions suivantes, on regarde si la grenouille est sur un bout de bois. Si c'est le cas, elle
        // suivra la direction de celle-ci
        for (int j = 0; j < TEMP; j++) {
            for (int i = 0; i < 20; i++) {
                if (liste_placement[j] == 0) {
                    if (liste_vit[j] == 0) {
                        deplacement = dx_lent;
                        pos_x = pos_x_lent;
                        pos_x_inv = pos_x_inv_lent;
                    }
                    if (liste_vit[j] == 1) {
                        deplacement = dx_norm;
                        pos_x = pos_x_norm;
                        pos_x_inv = pos_x_inv_norm;
                    }
                    if (liste_vit[j] == 2) {
                        deplacement = dx_rap;
                        pos_x = pos_x_rap;
                        pos_x_inv = pos_x_inv_rap;
                    }
                    collision_1(p_pos_perso_x, p_pos_perso_y, pos_x, pos_x_inv, pos_y, j, i,
                                liste_inver[j], deplacement);
                    out_1(p_pos_perso_x, p_pos_perso_y, pos_x, pos_x_inv, pos_y, j, i, liste_inver[j], p_fin);

                }
                if (liste_placement[j] == 1) {
                    if (liste_vit[j] == 0) {
                        deplacement = dx_lent;
                        pos_x = pos_x_lent;
                        pos_x_inv = pos_x_inv_lent;
                    }
                    if (liste_vit[j] == 1) {
                        deplacement = dx_norm;
                        pos_x = pos_x_norm;
                        pos_x_inv = pos_x_inv_norm;

                    }
                    if (liste_vit[j] == 2) {
                        deplacement = dx_rap;
                        pos_x = pos_x_rap;
                        pos_x_inv = pos_x_inv_rap;
                    }
                    collision_2(p_pos_perso_x, p_pos_perso_y, pos_x, pos_x_inv, pos_y, j, i,
                                liste_inver[j], deplacement);
                    out_2(p_pos_perso_x, p_pos_perso_y, pos_x, pos_x_inv, pos_y, j, i, liste_inver[j], p_fin);
                }
                if (liste_placement[j] == 2) {
                    if (liste_vit[j] == 0) {
                        deplacement = dx_lent;
                        pos_x = pos_x_lent;
                        pos_x_inv = pos_x_inv_lent;
                    }
                    if (liste_vit[j] == 1) {
                        deplacement = dx_norm;
                        pos_x = pos_x_norm;
                        pos_x_inv = pos_x_inv_norm;
                    }
                    if (liste_vit[j] == 2) {
                        deplacement = dx_rap;
                        pos_x = pos_x_rap;
                        pos_x_inv = pos_x_inv_rap;
                    }
                    collision_3(p_pos_perso_x, p_pos_perso_y, pos_x, pos_x_inv, pos_y, j, i,
                                liste_inver[j], deplacement);
                    out_3(p_pos_perso_x, p_pos_perso_y, pos_x, pos_x_inv, pos_y, j, i, liste_inver[j], p_fin);
                }
                if (liste_placement[j] == 3) {
                    if (liste_vit[j] == 0) {
                        deplacement = dx_lent;
                        pos_x = pos_x_lent;
                        pos_x_inv = pos_x_inv_lent;
                    }
                    if (liste_vit[j] == 1) {
                        deplacement = dx_norm;
                        pos_x = pos_x_norm;
                        pos_x_inv = pos_x_inv_norm;
                    }
                    if (liste_vit[j] == 2) {
                        deplacement = dx_rap;
                        pos_x = pos_x_rap;
                        pos_x_inv = pos_x_inv_rap;
                    }
                    collision_4(p_pos_perso_x, p_pos_perso_y, pos_x, pos_x_inv, pos_y, j, i,
                                liste_inver[j], deplacement);
                    out_4(p_pos_perso_x, p_pos_perso_y, pos_x, pos_x_inv, pos_y, j, i, liste_inver[j], p_fin);
                }
            }
        }

        nb_temps_1 = compt_chrono / 60;
        compt_d = 0, compt_c = 0;
        while (nb_temps_1 > 9) {
            nb_temps_1 -= 10;
            compt_d++;
        }
        nb_temps_2 = compt_d;
        while (nb_temps_2 > 9) {
            nb_temps_2 -= 10;
            compt_c++;
        }
        nb_temps_3 = compt_c;
        while (nb_temps_3 > 9) {
            nb_temps_3 -= 10;
        }
        masked_blit(nombre[nb_temps_3], title, 0, 0, 592 - 10, 10, SCREEN_W, SCREEN_H);
        masked_blit(nombre[nb_temps_2], title, 0, 0, 608 - 10, 10, SCREEN_W, SCREEN_H);
        masked_blit(nombre[nb_temps_1], title, 0, 0, 624 - 10, 10, SCREEN_W, SCREEN_H);
        /*
        textprintf_ex(title, font, 10, 10, makecol(255, 255, 255), -1, "y = %d", pos_map_y);
        textprintf_ex(title, font, 10, 20, makecol(255, 255, 255), -1, "debut = %d", debut);
        textprintf_ex(title, font, 10, 30, makecol(255, 255, 255), -1, "fin = %d", fin);
        textprintf_ex(title, font, 10, 40, makecol(255, 255, 255), -1, "scroll = %d", scroll);
        textprintf_ex(title, font, 10, 50, makecol(255, 255, 255), -1, "perso.y = %d", *p_pos_perso_y);
        textprintf_ex(title, font, 10, 60, makecol(255, 255, 255), -1, "y bois = %d", pos_y);
        textprintf_ex(title, font, 10, 70, makecol(255, 255, 255), -1, "x bois = %d", pos_x_lent);
        textprintf_ex(title, font, 10, 80, makecol(255, 255, 255), -1, "fin = %d", fin);
        textprintf_ex(title, font, 10, 90, makecol(255, 255, 255), -1, "debut = %d", debut);
        */

         if (inverse) {
            draw_sprite_h_flip(title, mario[imgc], pos_perso_x, pos_perso_y);
        } else {
            masked_blit(mario[imgc], title, 0, 0, pos_perso_x, pos_perso_y, SCREEN_W, SCREEN_H);
        }
        if (imgc != 0 && imgc != 4) {
            cpt++;
            if (cpt >= tmp) {
                cpt = 0;
                imgc++;
                if (imgc >= 4) { // quand l'indice de l'image courante arrive à NIMAGE
                    imgc = 0; // on recommence la séquence à partir de 0
                }
            }
        }
        if (imgc == 4) {
            cpt++;
            if (cpt >= tmp2) {
                cpt = 0;
                imgc = 0;
            }
        }
        blit(title, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

        //Si le bout de bois arrive à la fin de l'écran, on réinitialise sa position (Il en va de même pour le sens opposé)
        if (pos_x_lent > 0) {
            pos_x_lent = -3 * 640;
        } else {
            pos_x_lent += dx_lent;
        }
        if (pos_x_inv_lent < -3 * 640) {
            pos_x_inv_lent = 0;
        } else {
            pos_x_inv_lent -= dx_lent;
        }

        if (pos_x_norm > 0) {
            pos_x_norm = -3 * 640;
        } else {
            pos_x_norm += dx_norm;
        }
        if (pos_x_inv_norm < -3 * 640) {
            pos_x_inv_norm = 0;
        } else {
            pos_x_inv_norm -= dx_norm;
        }

        if (pos_x_rap > 0) {
            pos_x_rap = -3 * 640;
        } else {
            pos_x_rap += dx_rap;
        }
        if (pos_x_inv_rap < -3 * 640) {
            pos_x_inv_rap = 0;
        } else {
            pos_x_inv_rap -= dx_rap;
        }

        //Déplacement de la map
        /*
        if (!fin) {
            if (scroll) {
                if (pos_map_y == 512) {
                    pos_map_y = 0;
                } else {
                    pos_map_y++;
                    pos_perso_y++;
                    pos_y++;
                }
            }
        }
        if (fin) {
            if (pos_map_y != 512) {
                pos_map_y++;
                pos_perso_y++;
                pos_y++;
            }
        }
         */

        if (!fin) {
            if (pos_perso_y < 128) {
                if (pos_map_y == 448) {
                    pos_map_y = 0;
                    debut = 0;
                } else {
                    pos_map_y++;
                    pos_perso_y++;
                    pos_y++;
                }
            }
        }

        if (fin) {
            if (pos_map_y != 448 && pos_perso_y < 128) {
                pos_map_y++;
                pos_perso_y++;
                pos_y++;
            }
        }

        //Choix de la direction prise par le joueur
        if (key[KEY_UP] && appuie_up == 0) {
            if (pos_perso_y > 0) {
                imgc = 4;
                pos_perso_y -= 32;
                appuie_up = 1;
            }
        }
        //Cela permet de ne faire avancé la grenouille qu'une fois
        if (!key[KEY_UP] && appuie_up == 1) {
            appuie_up = 0;
        }
        if (key[KEY_DOWN] && appuie_down == 0) {
            if (pos_perso_y < 448 - 32) {
                imgc = 1;
                pos_perso_y += 32;
                appuie_down = 1;
            }
        }
        if (!key[KEY_DOWN] && appuie_down == 1) {
            appuie_down = 0;
        }
        if (key[KEY_LEFT] && appuie_left == 0) {
            if (pos_perso_x > 0) {
                imgc = 1;
                inverse = 1;
                pos_perso_x -= 32;
                appuie_left = 1;
            }
        }
        if (!key[KEY_LEFT] && appuie_left == 1) {
            appuie_left = 0;
        }
        if (key[KEY_RIGHT] && appuie_right == 0) {
            if (pos_perso_x < 640 - 32) {
                imgc = 1;
                inverse = 0;
                pos_perso_x += 32;
                appuie_right = 1;
            }
        }
        if (!key[KEY_RIGHT] && appuie_right == 1) {
            appuie_right = 0;
        }

        if (fin && pos_map_y == 448) {
            int image = getpixel(map_buff,pos_perso_x,pos_perso_y);
            if(getb(image) == 255) {
                stop_sample(music);
                if (turn == 1) {
                    score_joueur1 = compt_chrono / 60;
                    clear_bitmap(rule);
                    textprintf_ex(rule, font, 640 / 3, 448 / 2, makecol(255, 255, 255), -1, "Temps = %d",
                                  score_joueur1);
                    blit(rule, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                    rest(3000);
                    traverse(map, map_buff, person, title, ticket1,ticket2, sprites, turn + 1, p_score2, mario,princess, nombre, music,score_1,score_2,joueur1,joueur2,victory);
                } else {
                    *score2 = compt_chrono / 60;
                    clear_bitmap(rule);
                    textprintf_ex(rule, font, 640 / 3, 448 / 2, makecol(255, 255, 255), -1, "Temps = %d",
                                  *score2);
                    blit(rule, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                    rest(3000);
                }
                break;
            }
        }



        //Condition de game over
        if (fin_de_jeu || pos_perso_x > 640 || pos_perso_x < -32 || pos_perso_y == 448) {
            stop_sample(music);
            if (turn == 1) {
                score_joueur1 = 0;
                clear_bitmap(rule);
                textprintf_ex(rule, font, 640 / 3, 448 / 2, makecol(255, 255, 255), -1, "Temps = %d",
                              score_joueur1);
                blit(rule, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                rest(3000);
                traverse(map, map_buff, person, title, ticket1,ticket2, sprites, turn + 1, p_score2, mario,princess, nombre, music,score_1,score_2,joueur1,joueur2,victory);
            } else {
                *score2 = 0;
                clear_bitmap(rule);
                textprintf_ex(rule, font, 640 / 3, 448 / 2, makecol(255, 255, 255), -1, "Temps = %d", *score2);
                blit(rule, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                rest(3000);
            }
            break;
            }
        }
        if (turn == 1)
            stop_sample(music);{
            if(*score_1 == 999){
                *score_1 = score_joueur1;
            }
            else{
                if(*score_1 > score_joueur1 && !score_joueur1){
                    *score_1 = score_joueur1;
                }
            }

            if(*score_2 == 999){
                *score_2 = score_joueur2;
            }
            else{
                if(*score_2 > score_joueur2 && !score_joueur2){
                    *score_2 = score_joueur2;
                }
            }

            clear_bitmap(rule);
            if (score_joueur1 > score_joueur2) {
                if(!score_joueur2) {
                    *ticket2+=2;
                    textprintf_ex(rule, font, 640 / 3, 448 / 2, makecol(255, 255, 255), -1, "%s win",joueur1);
                }
                else{
                    *ticket1+=2;
                    textprintf_ex(rule, font, 640 / 3, 448 / 2, makecol(255, 255, 255), -1, "%s win",joueur2);
                }
            }

            if (score_joueur1 == score_joueur2) {
                textprintf_ex(rule, font, (640 / 2) - 50, 448 / 2, makecol(255, 255, 255), -1, "Draw");
            }

            if (score_joueur1 < score_joueur2) {
                if(!score_joueur1) {
                    *ticket2+=2;
                    textprintf_ex(rule, font, 640 / 3, 448 / 2, makecol(255, 255, 255), -1, "%s win",joueur2);
                }
                else{
                    *ticket1+=2;
                    textprintf_ex(rule, font, 640 / 3, 448 / 2, makecol(255, 255, 255), -1, "%s win",joueur1);
                }
            }
            blit(rule, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
            play_sample(victory, 255, 128, 1000, 0);
            rest(11000);
        }

}


//
// Created by gammp on 28/04/2023.
//
