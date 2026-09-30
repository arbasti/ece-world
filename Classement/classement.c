#include "classement.h"

void affichage_score(BITMAP* title,FILE* best2,FILE* best1,char* joueur1,char* joueur2,int score1_game1,int score2_game1,int score1_game2,int score2_game2){
    char meill_2[100],meill_1[100];
    fseek(best1, 0, SEEK_SET);
    fgets(meill_1,100,best1);
    fseek(best2, 0, SEEK_SET);
    fgets(meill_2,100,best2);
    while(!key[KEY_DEL]){
        textprintf_ex(title,font,20,150,makecol(0,0,0),-1,"Traversé de mario");

        if(score1_game1 == 999){
            textprintf_ex(title,font,20,180,makecol(0,0,0),-1,"%s : Aucun score",joueur1);
        }
        else{
            textprintf_ex(title,font,20,180,makecol(0,0,0),-1,"%s : %d",joueur1,score1_game1);
        }
        if(score2_game1 == 999){
            textprintf_ex(title,font,20,190,makecol(0,0,0),-1,"%s : Aucun score",joueur2);
        }
        else{
            textprintf_ex(title,font,20,190,makecol(0,0,0),-1,"%s: %d",joueur2,score2_game1);
        }
        textprintf_ex(title,font,20,210,makecol(0,0,0),-1,"Meilleur temps :");
        textprintf_ex(title,font,20,220,makecol(0,0,0),-1,"%s",meill_1);



        textprintf_ex(title,font,200,150,makecol(0,0,0),-1,"Tir au koopa");
        if(score1_game2 == 999){
            textprintf_ex(title,font,200,180,makecol(0,0,0),-1,"%s : Aucun score",joueur1);
        }
        else {
            textprintf_ex(title, font, 200, 180, makecol(0,0,0), -1, "%s : %d", joueur1, score1_game2);
        }
        if(score2_game2 == 999){
            textprintf_ex(title,font,200,190,makecol(0,0,0),-1,"%s: Aucun score",joueur2);
        }else {
            textprintf_ex(title, font, 200, 190, makecol(0,0,0), -1, "%s: %d", joueur2, score2_game2);
        }

        textprintf_ex(title,font,200,210,makecol(0,0,0),-1,"Meilleur temps :");
        textprintf_ex(title,font,200,220,makecol(0,0,0),-1,"%s",meill_2);
        blit(title,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }
}

//
// Created by gammp on 19/05/2023.
//
