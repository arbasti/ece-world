
#include "course_hyppique.h"


void collision_menu1( BITMAP* fond,  BITMAP* map_collision, BITMAP * fleche_Bleu, int *tour, int *pari) {

    int pixel = getpixel(map_collision, mouse_x, mouse_y);

            if ((getb(pixel) == 1) && mouse_b & 1) {
                masked_blit(fleche_Bleu, fond, 0, 0, 105, 250, SCREEN_W, SCREEN_H);
                *pari = 1;

            } else if ((getb(pixel) == 2) && mouse_b & 1) {
                masked_blit(fleche_Bleu, fond, 0, 0, 250, 250, SCREEN_W, SCREEN_H);
                *pari = 2;

            } else if ((getb(pixel) == 3) && mouse_b & 1) {
                masked_blit(fleche_Bleu, fond, 0, 0, 395, 250, SCREEN_W, SCREEN_H);
                *pari = 3;
            } else if ((getb(pixel) == 4) && mouse_b & 1) {
                masked_blit(fleche_Bleu, fond, 0, 0, 525, 250, SCREEN_W, SCREEN_H);
                *pari = 4;
            }

            if (key[KEY_SPACE]){
                *tour = 1;
            }
    }




void collision_menu2( BITMAP* fond,  BITMAP* map_collision, BITMAP * fleche_Rouge, int *pari ) {

    int pixel = getpixel(map_collision, mouse_x, mouse_y);

    if ((getb(pixel) == 1) && mouse_b & 1) {
        masked_blit(fleche_Rouge, fond, 0, 0, 105, 250, SCREEN_W, SCREEN_H);
        *pari = 1;

    } else if ((getb(pixel) == 2) && mouse_b & 1) {
        masked_blit(fleche_Rouge, fond, 0, 0, 250, 250, SCREEN_W, SCREEN_H);
        *pari = 2;

    } else if ((getb(pixel) == 3) && mouse_b & 1) {
        masked_blit(fleche_Rouge, fond, 0, 0, 395, 250, SCREEN_W, SCREEN_H);
        *pari = 3;
    } else if ((getb(pixel) == 4) && mouse_b & 1) {
        masked_blit(fleche_Rouge, fond, 0, 0, 525, 250, SCREEN_W, SCREEN_H);
        *pari = 4;
    }
}



void Menu(int *pari1, int *pari2 ) {

    int choix_J1;
    int choix_J2;

    int tour = 0 ;
    int * p_tour = &tour;
    BITMAP *page;
    page = create_bitmap(SCREEN_W, SCREEN_H);
    clear_bitmap(page);
    BITMAP *page2;
    page2 = create_bitmap(SCREEN_W, SCREEN_H);
    clear_bitmap(page2);
    BITMAP *fleche_B = load_bitmap("../images/course_hyppique/fleche_bleu.bmp", NULL);
    if (!fleche_B ) {
        allegro_message("prb chargement image flecheR");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    BITMAP *fleche_R = load_bitmap("../images/course_hyppique/fleche_rouge.bmp", NULL);
    if (!fleche_R ) {
        allegro_message("prb chargement image flecheR");
        allegro_exit();
        exit(EXIT_FAILURE);
    }


    BITMAP *fond = load_bitmap("../images/course_hyppique/map_menu.bmp", NULL);
    if (!fond) {
        allegro_message("prb chargement imagemap");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *yoshi = load_bitmap("../images/course_hyppique/course_hyppique_perso.bmp", NULL);
    if (!yoshi) {
        allegro_message("prb chargement imagemap");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP* map_collis= load_bitmap("../images/course_hyppique/map_collision.bmp", NULL);
    if (!map_collis) {
        allegro_message("prb chargement imagemap");
        allegro_exit();
        exit(EXIT_FAILURE);
    }


    show_mouse(screen);
    while (!key[KEY_ENTER]) {

        clear_bitmap(page);
        clear_bitmap(page2);

        blit(page2, page, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        blit(map_collis, page, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        masked_blit(yoshi, fond, 0, 0, 10, 180, SCREEN_W, SCREEN_H);
        if (tour == 0) {
            collision_menu1(fond, map_collis, fleche_B, p_tour,pari1);
        }
        if(tour > 0 ) {
            collision_menu2(fond, map_collis, fleche_R, pari2);
        }


        blit(fond, page, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        blit(page, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);



    }

    destroy_bitmap(fond);

}
