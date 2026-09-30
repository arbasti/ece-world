//
// Created by GAB on 07/05/2023.
//

#ifndef OFF_COURSE_HYPPIQUE_H
#define OFF_COURSE_HYPPIQUE_H

#include "../Hub Scrolling/hub.h"
#include "allegro.h"
#include "time.h"
#define NB_IMAGES_Course 3

typedef struct {
    int x;
    int y;
    int dx;

} player;

// course_hyppique_main.c
void course_hyppique_main(int *ticket1,int* ticket2,SAMPLE* music);


// course_hyppique_menu.c
void collision_menu1( BITMAP* fond,  BITMAP* map_collision, BITMAP * fleche_Bleu, int *tour, int *pari  );
void collision_menu2( BITMAP* fond,  BITMAP* map_collision, BITMAP * fleche_Rouge , int *pari );
void Menu(int *pari1, int *pari2);

#endif //OFF_COURSE_HYPPIQUE_H
