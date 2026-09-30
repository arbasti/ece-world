#include "game2.h"

typedef struct{
    int pos_ballon_x;
    int pos_ballon_y;

    int direct;
    int chang;
    int inverse;
}koopa_volant;

void tir_au_ballon(BITMAP* title,int turn,int* ticket1,int* ticket2,BITMAP* ballon,BITMAP* ciel,BITMAP* koopa[2],BITMAP* nombre[10],char joueur1[],char joueur2[],SAMPLE* music,int* score_1,int* score_2,int* gamescore2,SAMPLE* sound,SAMPLE* victory){
    srand(time(NULL));
    BITMAP* rule = create_bitmap(SCREEN_W,SCREEN_H);
    BITMAP * menu2 = load_bitmap("../Images/Game2/menu_tir_au_koopa.bmp",NULL);
    koopa_volant liste[MAX_KOOPA];
    for(int i = 0;i<MAX_KOOPA;i++){
        liste[i].pos_ballon_x = rand()%642;
        liste[i].pos_ballon_y = rand()%449;
        liste[i].direct = rand()%2;
        liste[i].chang = rand()%4;
        liste[i].inverse = 0;
    }

    int score1,score2;
    int* p_score2 = &score2;

    int vitesse = 5;

    int nombre_temps=0;

    int compt_temps=0;

    int cptimg = 0, tmpimg = 10, imgcourante = 0;

    int click =0;

    int nb_temps_1,nb_temps_2,nb_temps_3;
    int compt_d,compt_c;

    int tir=0;

    if(turn == 1) {
        while(!key[KEY_ENTER]){
        clear_bitmap(rule);
        blit(menu2, rule, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        blit(rule, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }
    }

    play_sample(music, 255, 128, 1000, 0);
    while(!key[KEY_DEL]){
        clear_bitmap(title);
        rest(10);
        printf("%d\n",compt_temps/60);
        show_mouse(ciel);
        cptimg++;
        if (cptimg >= tmpimg) {
            cptimg = 0;
            imgcourante++;
            if (imgcourante >= 2) // quand l'indice de l'image courante arrive à NIMAGE
                imgcourante = 0; // on recommence la séquence à partir de 0
        }
        blit(ciel,title,0,0,0,0,SCREEN_W,SCREEN_H);
        for(int i =0;i<MAX_KOOPA;i++) {
            if (liste[i].inverse) {
                draw_sprite_h_flip(title, koopa[imgcourante], liste[i].pos_ballon_x, liste[i].pos_ballon_y);
            } else {
                masked_blit(koopa[imgcourante], title, 0, 0, liste[i].pos_ballon_x, liste[i].pos_ballon_y, SCREEN_W,
                            SCREEN_H);
            }
        }
        nb_temps_1 = compt_temps/60;
        compt_d=0,compt_c = 0;
        while(nb_temps_1 > 9) {
            nb_temps_1 -= 10;
            compt_d++;
        }
        nb_temps_2 = compt_d;
        while(nb_temps_2 > 9) {
            nb_temps_2 -= 10;
            compt_c++;
        }
        nb_temps_3 = compt_c;
        while(nb_temps_3 > 9) {
            nb_temps_3 -= 10;
        }
        masked_blit(nombre[nb_temps_3], title, 0, 00, 592-10, 10, SCREEN_W, SCREEN_H);
        masked_blit(nombre[nb_temps_2], title, 0, 00, 608-10, 10, SCREEN_W, SCREEN_H);
        masked_blit(nombre[nb_temps_1], title, 0, 00, 624-10, 10, SCREEN_W, SCREEN_H);

        /*
        textprintf_ex(title,font,10,10,makecol(255,255,255),-1,"direct = %d",liste[0].direct);
        textprintf_ex(title,font,10,20,makecol(255,255,255),-1,"temps = %d",compt_temps/60);
        textprintf_ex(title,font,10,30,makecol(255,255,255),-1,"temps-1 = %d",nombre_temps);
        textprintf_ex(title,font,10,40,makecol(255,255,255),-1,"tir = %d",tir);
        textprintf_ex(title,font,10,50,makecol(255,255,255),-1,"y = %d",liste[0].pos_ballon_y);
        textprintf_ex(title,font,10,60,makecol(255,255,255),-1,"temps = %d",compt_temps/60);
        textprintf_ex(title,font,10,70,makecol(255,255,255),-1,"click = %d",click);
        textprintf_ex(title,font,10,10,makecol(255,255,255),-1,"Temps = %d",compt_temps/60);
        */
         blit(title,screen,0,0,0,0,SCREEN_W,SCREEN_H);

        //Change la direction du ballon;
        for(int i = 0;i<MAX_KOOPA;i++) {
            if ((mouse_x >= liste[i].pos_ballon_x && mouse_x <= liste[i].pos_ballon_x + 64 &&
                 mouse_y >= liste[i].pos_ballon_y && mouse_y <= liste[i].pos_ballon_y + 64
                 && mouse_b) !=0 && !click) {
                play_sample(sound, 255, 128, 1000, 0);
                tir++;
                liste[i].pos_ballon_x = rand() % 641;
                liste[i].pos_ballon_y = 256 + rand() % (413 - 256) - 32;
                liste[i].direct = rand() % 2;
                click = 1;
            }

            if((mouse_b) == 0 && click == 1){
                click = 0;
            }

            if (liste[i].pos_ballon_y+64 < 0) {
                liste[i].pos_ballon_x = rand() % 641;
                liste[i].pos_ballon_y = 448;
                liste[i].direct = rand() % 2;
            }
            if (liste[i].pos_ballon_x > 640 || liste[i].pos_ballon_x < -64) {
                if (liste[i].pos_ballon_x > 0) {
                    liste[i].pos_ballon_x -= 704;
                } else {
                    liste[i].pos_ballon_x += 704;
                }

                //pos_ballon_y = 256 + rand()%(413 - 256) -32;
                liste[i].direct = rand() % 2;
            }

            //Déplacement du ballon
            liste[i].pos_ballon_y -= vitesse;

            if (compt_temps / 10 != nombre_temps) {
                liste[i].direct = rand() % 2;
            }
            if (nombre_temps != compt_temps / 10) {
                nombre_temps = compt_temps / 10;
            }
/*
            if (liste[i].chang % 2 == 0) {
                liste[i].direct = rand() % 2;
                liste[i].chang = 1;
            }*/

            if (liste[i].direct) {
                liste[i].inverse = 0;
                liste[i].pos_ballon_x += vitesse;
            } else {
                liste[i].inverse = 1;
                liste[i].pos_ballon_x -= vitesse;
            }
        }

        compt_temps++;
        //Condition de fin
        if(tir == 1){
            stop_sample(music);
            if(turn == 1) {
                score1=compt_temps/60;
                clear_bitmap(rule);
                textprintf_ex(rule,font,(640/2) - 50,448/2,makecol(255,255,255),-1,"Temps = %d",score1);
                blit(rule,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                rest(3000);
                tir_au_ballon(title,turn +1, ticket1,ticket2, ballon, ciel,koopa,nombre,joueur1,joueur2,music,score_1,score_2,p_score2,sound,victory);
            }
            else{
                *gamescore2=compt_temps/60;
                textprintf_ex(rule,font,(640/2) - 50,448/2,makecol(255,255,255),-1,"Temps = %d",*gamescore2);
                blit(rule,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                rest(3000);
            }
            break;
        }
    }
    stop_sample(music);
    if(turn == 20) {
        if(*score_1 == 999){
            *score_1 = score1;
        }
        else{
            if(*score_1 > score1){
                *score_1 = score1;
            }
        }

        if(*score_2 == 999){
            *score_2 = score2;
        }
        else{
            if(*score_2 > score2){
                *score_2 = score2;
            }
        }

        clear_bitmap(rule);
        if (score2 < score1) {
            *ticket2+=2;
            textprintf_ex(rule,font,640/3,448/2,makecol(255,255,255),-1,"%s gagne",joueur2);
        }
        if(score2 > score1){
            *ticket1+=2;
            textprintf_ex(rule,font,640/3,448/2,makecol(255,255,255),-1,"%s gagne",joueur1);
        }
        if(score2 == score1){
            textprintf_ex(rule,font,(640/2) - 50,448/2,makecol(255,255,255),-1,"Draw");
        }
        blit(rule,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        play_sample(victory, 255, 128, 1000, 0);
        rest(11000);
    }

}

//
// Created by gammp on 12/05/2023.
//
