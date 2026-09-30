
#include "course_hyppique.h"


void victoire (player yoshi1,player yoshi2,player yoshi3,player yoshi4, BITMAP * fond, BITMAP *yosh1 ,BITMAP * yosh2,BITMAP * yosh3,BITMAP * yosh4, BITMAP *page, int *gagnant, int pari1,int pari2,int*ticket1,int *ticket2,int* ajout) {


        if (yoshi1.x >= 540) {

            blit(fond, page, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

            masked_blit(yosh1, fond, 0, 0, 300, 180, SCREEN_W, SCREEN_H);
            yoshi3.dx =yoshi3.x = 0;
            yoshi4.dx =yoshi4.x = 0;
            yoshi2.dx =yoshi2.x = 0;
                if (pari1 == 1) {
                    *ticket1 += 2;
                    *ajout = 1;

                }
                if (pari2 == 1) {
                    *ticket2 += 2;
                    *ajout = 1;
                }
                *gagnant = 1;


        }
        if (yoshi2.x >= 540) {


            blit(fond, page, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

            masked_blit(yosh2, fond, 0, 0, 300, 180, SCREEN_W, SCREEN_H);
            yoshi1.dx = yoshi1.x =0;
            yoshi3.dx = yoshi3.x =0;
            yoshi4.dx = yoshi4.x =0;
            printf("%d\n",pari1);
                if (pari1 == 2) {
                    *ticket1 += 2;
                    *ajout = 1;

                }
                if (pari2 == 2) {
                    *ticket2 += 2;
                    *ajout = 1;
                }
                *gagnant = 1;

        }
        if (yoshi3.x >= 540) {

            blit(fond, page, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

            masked_blit(yosh3, fond, 0, 0, 300, 180, SCREEN_W, SCREEN_H);
            

            yoshi2.dx =yoshi2.x = 0;
            yoshi1.dx =yoshi1.x = 0;
            yoshi4.dx =yoshi4.x = 0;
            printf("%d\n",pari1);
                if (pari1 == 3) {
                    *ticket1 += 2;
                    *ajout = 1;

                }
                if (pari2 == 3) {
                    *ticket2 += 2;
                    *ajout = 1;
                }
                *gagnant = 1;

        }
        if (yoshi4.x >= 540) {


            blit(fond, page, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

            masked_blit(yosh4, fond, 0, 0, 300, 180, SCREEN_W, SCREEN_H);
            yoshi2.dx = yoshi2.x = 0;
            yoshi1.dx =yoshi1.x =0;
            yoshi3.dx =yoshi3.x =0;
            printf("%d\n",pari1);
                if (pari1 == 4) {
                    *ticket1 += 2;
                    *ajout = 1;

                }
                if (pari2 == 4) {
                    *ticket2 += 2;
                    *ajout = 1;
                }
                *gagnant = 1;
        }




}



player vitesse_joueur (player yosh) {
    if ( yosh.x <=  100) {
        yosh.dx = (rand() % 8) + 1;
        yosh.x += yosh.dx;
    }
    else if ( yosh.x <= 200) {
        yosh.dx = (rand() % 8) + 1;
        yosh.x += yosh.dx;
    }else if ( yosh.x <= 300)
        {
            yosh.dx = (rand() % 8) + 1;
            yosh.x += yosh.dx;

        } else if ( yosh.x <= 400)
    {
        yosh.dx = (rand() % 8) + 1;
        yosh.x += yosh.dx;

    } else if ( yosh.x <= 540) {
        yosh.dx = (rand() % 8) + 1;
        yosh.x += yosh.dx;
    }

    return yosh;
}





void course_hyppique_main(int *ticket1,int* ticket2,SAMPLE* music)
{
    srand(time(NULL));

    set_color_depth(desktop_color_depth());
    if ((set_gfx_mode(GFX_AUTODETECT_WINDOWED, SCREEN_W, SCREEN_H, 0, 0)) != 0) {
        allegro_message("Pb de mode graphique");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    // Charger un sprite
    BITMAP *sprite1[NB_IMAGES_Course];
    BITMAP *sprite2[NB_IMAGES_Course];
    BITMAP *sprite3[NB_IMAGES_Course];
    BITMAP *sprite4[NB_IMAGES_Course];



    BITMAP *page;
    page = create_bitmap(SCREEN_W, SCREEN_H);
    clear_bitmap(page);
    int compteur_animation = 0;
    char filename[100];

    // Charger un fond

    BITMAP *fond = load_bitmap("../images/course_hyppique/map_course.bmp", NULL);
    if (!fond) {
        allegro_message("prb chargement image de la");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *fond_fin = load_bitmap("../images/course_hyppique/map_fin.bmp", NULL);
    if (!fond_fin) {
        allegro_message("prb chargement image de la");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    // Boucle de jeu
    for (int i = 0; i < NB_IMAGES_Course; ++i) {
        // sprite avec i
        sprintf(filename, "../images/course_hyppique/YoshiRouge/yoshi%d.bmp", i);
        sprite1[i] = load_bitmap(filename, NULL);

        if (!sprite1[i]) {
            allegro_message("prb chargement image rouge");
            allegro_exit();
            exit(EXIT_FAILURE);
        }

    }
    for (int i = 0; i < NB_IMAGES_Course; ++i) {
        // sprite avec i
        sprintf(filename, "../images/course_hyppique/yoshiBleue/yoshiBleue%d.bmp", i);
        sprite2[i] = load_bitmap(filename, NULL);

        if (!sprite2[i]) {
            allegro_message("prb chargement image bleue");
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < NB_IMAGES_Course; ++i) {
        // sprite avec i
        sprintf(filename, "../images/course_hyppique/yoshiJaune/yoshiJaune%d.bmp", i);
        sprite3[i] = load_bitmap(filename, NULL);

        if (!sprite3[i]) {
            allegro_message("prb chargement image jaune");
            allegro_exit();
            exit(EXIT_FAILURE);
        }

    }

    for (int i = 0; i < NB_IMAGES_Course; ++i) {
        // sprite avec i
        sprintf(filename, "../images/course_hyppique/yoshiGris/yoshiGris%d.bmp", i);
        sprite4[i] = load_bitmap(filename, NULL);

        if (!sprite4[i]) {
            allegro_message("prb chargement image gris");
            allegro_exit();
            exit(EXIT_FAILURE);
        }

    }
/*
    int pari1[4] ;
    int pari2[4] ;
    int * p_pari1 = &pari1;
    int * p_pari2 = &pari2;*/
    int ajout=0;
    int *p_ajout = &ajout;
    int pari1,pari2;
    int *p_pari1 = &pari1;
    int *p_pari2 = &pari2;
    Menu(p_pari1,p_pari2);
    int gagnant = 0;
    int *p_gagnant = &gagnant;
    player yosh1 = {0,140, 0};
    player yosh2 = {0,170, 0};
    player yosh3 = {0,200, 0};
    player yosh4 = {0,240, 0};

    play_sample(music, 255, 128, 1000, 0);
    while (!key[KEY_DEL]) {



            clear_bitmap(page);
            if(!gagnant){


            yosh1 = vitesse_joueur(yosh1);
            yosh2 = vitesse_joueur(yosh2);
            yosh3 = vitesse_joueur(yosh3);
            yosh4 = vitesse_joueur(yosh4);

            }


            //Afficher le sprite
            blit(fond, page, 0, 0, 0, 0, fond->w, fond->h);


            draw_sprite(page, sprite1[compteur_animation], yosh1.x, yosh1.y);
            draw_sprite(page, sprite2[compteur_animation], yosh2.x, yosh2.y);
            draw_sprite(page, sprite3[compteur_animation], yosh3.x, yosh3.y);
            draw_sprite(page, sprite4[compteur_animation], yosh4.x, yosh4.y);
            rest(30);
            victoire(yosh1, yosh2, yosh3, yosh4, fond_fin, sprite1[1], sprite2[0], sprite3[0], sprite4[0], page, p_gagnant, pari1, pari2,ticket1,ticket2,p_ajout);

            blit(page, screen, 0, 0, 0, 0, fond->w, fond->h);
            compteur_animation = (compteur_animation + 1) % NB_IMAGES_Course;


            // Montrer la souris à l'écran
            show_mouse(fond);
        }
    stop_sample(music);
}

