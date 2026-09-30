#include <stdio.h>
#include "Title Screen/title.h"
#include "Joueur/Joueur.h"
#include "Game1/game1.h"
#include "Game2/game2.h"
#include "Game3/goombattack.h"
#include "Game4/course_hyppique.h"
#include "Classement/classement.h"
#include "Hub Scrolling/hub.h"

void initialisation_allegro(){
    allegro_init();
    install_keyboard();
    install_mouse();
    install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
    set_color_depth(desktop_color_depth());
    if((set_gfx_mode(GFX_AUTODETECT_WINDOWED,SCREEN_W,SCREEN_H,0,0))!=0)
    { 	allegro_message("Pb de mode graphique") ;
        allegro_exit();
        exit(EXIT_FAILURE); }
}

int main() {
    initialisation_allegro();
    FILE *best1 = NULL;  //Meilleur score du jeu 1
    FILE *best2 = NULL;  //Meilleur score du jeu 2
    best2 = fopen("../Score/Game2/best.txt","r+");
    best1 = fopen("../Score/Game1/Best.txt","r+");
    int caract;  //Pour prendre la chaine de caractère

    char joueur1[10],joueur2[10];
    char * p_joueur1 = (char *) &joueur1;
    char * p_joueur2 = (char *) &joueur2;

    //Score jeu 1
    int score_1_game1 = (int) 999,score_2_game1 = (int) 999;
    int* p_1score1 = &score_1_game1;
    int* p_1score2 = &score_2_game1;

    //Score jeu 2
    int score_1_game2 = (int) 999,score_2_game2 = (int) 999;
    int* p_2score1 = &score_1_game2;
    int* p_2score2 = &score_2_game2;

    //Score jeu 3
    int score_1_game3 = (int) 999,score_2_game3 = (int) 999;
    int* p_3score1 = &score_1_game3;
    int* p_3score2 = &score_2_game3;

    SAMPLE * bcg_music = load_sample("../Music/Country.wav");
    SAMPLE * mario_music = load_sample("../Music/Theme.wav");
    SAMPLE* mario_theme = load_sample("../Music/mario theme.wav");
    SAMPLE * koopa = load_sample("../Music/koopa.wav");
    SAMPLE* tirer = load_sample("../Music/coins.wav");
    SAMPLE* victory = load_sample("../Music/Victory.wav");
    SAMPLE* mario_64 = load_sample("../Music/mario 64.wav");
    SAMPLE* goomba = load_sample("../Music/goombattack.wav");
    SAMPLE* course = load_sample("../Music/course.wav");
    SAMPLE* saut = load_sample("../Music/saut.wav");


    BITMAP * buffer_info = create_bitmap(640,448);
    clear_to_color(buffer_info,makecol(255,0,255));

    //Nombre
    BITMAP *nombre[10];
    char filename5[100];
    for(int i=0;i<10;i++){
        sprintf(filename5,"../Images/Nombre/%d.bmp",i);
        nombre[i]=load_bitmap(filename5,NULL);
        if (!nombre[i]) {
            allegro_message("prb chargement image");
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }

    //Perosnnage
    BITMAP *personnage[4];
    char filename6[100];
    for(int i=0;i<4;i++){
        sprintf(filename6,"../Images/perso_marche/pixil-frame-%d.bmp",i);
        personnage[i]=load_bitmap(filename6,NULL);
        if (!personnage[i]) {
            allegro_message("prb chargement image");
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }

    BITMAP* ouv = load_bitmap("../Images/Title/Mario ouv.bmp",NULL);


    //Images Hub
    BITMAP* coin = load_bitmap("../Images/Hub/coin.bmp",NULL);

    BITMAP * titre,*buffer;

    titre = load_bitmap("../Images/Title/Mario.bmp",NULL);
    buffer = create_bitmap(640,381);
    clear_bitmap(buffer);

    //Images de l'écran titre
    BITMAP *title, *SF,*map_title,*start;
    //title est un buffer

    //Images du Hub centrale
    BITMAP *perso,*map_off,*col,*page;
    //map pour la carte et col pour la map avec les collisions

    //Images du premier jeu
    BITMAP *map_riv,*map_rivbuff,* princess;

    //Images du second jeu
    BITMAP * ballon,*ciel;

    BITMAP * affichagescore;
    affichagescore = load_bitmap("../Images/Hub/affichage_score.bmp",NULL);

    ballon = load_bitmap("../Images/Game2/ballon.bmp",NULL);
    ciel = load_bitmap("../Images/Game2/chateau.bmp",NULL);

    title = create_bitmap(640,448);
    clear_bitmap(title);

    page = create_bitmap(MAP_H,MAP_W);
    clear_bitmap(page);

    SF = load_bitmap("../Images/Title/SF2 title.bmp",NULL);

    map_riv = load_bitmap("../Images/Game1/Map rivière1.bmp",NULL);

    map_rivbuff = load_bitmap("../Images/Game1/Map rivière buff3.bmp",NULL);

    map_title = load_bitmap("../Images/Title/map_title.bmp",NULL);

    map_off = load_bitmap("../Images/Hub/map_official22.bmp",NULL);

    col = load_bitmap("../Images/Hub/map_collision_official22.bmp",NULL);

    princess = load_bitmap("../Images/Game1/Mario/peache.bmp",NULL);

    start = load_bitmap("../Images/Title/Start1.bmp",NULL);

    perso = load_bitmap("../Images/perso.bmp",NULL);

    //Liste des maps pour le jeu 1
    BITMAP *sprites_map[MAX_MAP];
    char filename1[100];
    for(int i=0;i<MAX_MAP;i++){
        sprintf(filename1,"../Images/Game1/Map rivière%d.bmp",i);
        sprites_map[i]=load_bitmap(filename1,NULL);
        if (!sprites_map[i]) {
            allegro_message("prb chargement image ahaha %d",i);
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }

    //Liste des spirtes pour les bouts de bois
    BITMAP *sprites[MAX_BOIS];
    char filename2[100];
    for(int i=0;i<MAX_BOIS;i++){
        sprintf(filename2,"../Images/Game1/Bois%d.bmp",i);
        sprites[i]=load_bitmap(filename2,NULL);
        if (!sprites[i]) {
            allegro_message("prb chargement image");
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }
    //animation mario
    BITMAP *sprites_mario[5];
    char filename3[100];
    for(int i=0;i<5;i++){
        sprintf(filename3,"../Images/Game1/Mario/Mario%d.bmp",i);
        sprites_mario[i]=load_bitmap(filename3,NULL);
        if (!sprites_mario[i]) {
            allegro_message("prb chargement image");
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }

    //animation koopa
    BITMAP *sprites_koopa[2];
    char filename4[100];
    for(int i=0;i<2;i++){
        sprintf(filename4,"../Images/Game2/koopa%d_64.bmp",i);
        sprites_koopa[i]=load_bitmap(filename4,NULL);
        if (!sprites_koopa[i]) {
            allegro_message("prb chargement image");
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }

    int i;
    char val;


    int ticket2;
    int *p_ticket2 = &ticket2;

    int ticket1;
    int *p_ticket1 = &ticket1;

    int debut = 1;

    players joueur = {400, 300, 4, 4};
    map carte = {0, 0};

    int cptimg = 0, tmpimg = 50, imgcourante = 0;

    play_sample(mario_64, 255, 128, 1000, 0);
    while(!key[KEY_ESC]) {
        cptimg++;
        if (cptimg >= tmpimg) {
            cptimg = 0;
            imgcourante++;
            if (imgcourante >= 4) // quand l'indice de l'image courante arrive à NIMAGE
                imgcourante = 0; // on recommence la séquence à partir de 0
        }
        clear_bitmap(title);
        if(!debut) {
            blit(titre, title, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
            blit(title, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
            rest(1000);
            debut =0;
        }
        if (!play_game) {     //Si la variable est à 0,on Affiche l'écran titre
            //A chaque fois qu'on commence une partie où qu'on retourne sur l'écran titre, on initialise tout
            clear_bitmap(title);
            ticket1 = 5;
            ticket2 = 5;
            affichage_ecran(SF, title,buffer,titre, start); //Fonction permettant d'afficher l'écran titre
        }
        if(play_game == 2){
            enregistrement(p_joueur1,p_joueur2);
            /*fseek(fichier, 0, SEEK_END);
            fprintf(fichier,"\n%s",joueur1);
            fprintf(fichier,"\n%s",joueur2);*/
            play_game = 1;
        }

        if (play_game ==1) {
            if (ticket1 == 0 ||ticket2 == 0) {
                play_game = 0;
            }
            int image = getpixel(col,joueur.x,joueur.y);

            joueur = moves_player(joueur,col);

            blit(map_off, page, 0, 0, 0, 0, MAP_W, MAP_H);
            masked_blit(coin,buffer_info,0,0,10,10,SCREEN_W,SCREEN_H);
            masked_blit(coin,buffer_info,0,0,640-64,10,SCREEN_W,SCREEN_H);
            //rectfill(page, joueur.x, joueur.y, joueur.x+10, joueur.y+10, makecol(0, 0, 255));
            masked_blit(personnage[imgcourante],page, 0, 0, joueur.x, joueur.y, SCREEN_W,SCREEN_H);
            carte = moves_camera(joueur, carte);
            textprintf_ex(page, font, carte.x+32, carte.y+10, makecol(255, 255, 255), -1, " %d",ticket1);
            textprintf_ex(page, font, carte.x+640-32, carte.y+10, makecol(255, 255, 255), -1, " %d",ticket2);
            masked_blit(buffer_info,page,0,0,carte.x,carte.y,SCREEN_W,SCREEN_H);

            if(getb(image) == 255 && getg(image) == 2) {
                textprintf_ex(page,font,joueur.x - 50,joueur.y - 30 ,makecol(0,0,0),-1,"Appuyé sur 'P' pour la traversé de la rivière");
                if (key[KEY_P]) {  //Regard si le joueur veut accéder à l'attraction
                    stop_sample(mario_64);
                    ticket1 -= 1;
                    ticket2 -= 1;
                    traverse(sprites_map, map_rivbuff, perso, title, p_ticket1,p_ticket2, sprites, 1, 0,sprites_mario,princess,nombre,bcg_music,p_1score1,p_1score2,joueur1,joueur2,victory);
                    //tir_au_ballon(title,1,p_ticket,ballon,ciel,sprites_koopa,nombre,joueur1,koopa,p_score1,p_score2,0);
                    play_sample(mario_64, 255, 128, 1000, 0);
                }

            }

            if(getb(image) == 255 && getg(image) == 1) {
                textprintf_ex(page,font,joueur.x - 50,joueur.y - 30 ,makecol(0,0,0),-1,"Appuyé sur 'P' pour le tir aux koopas");
                if (key[KEY_P]) {  //Regard si le joueur veut accéder à l'attraction
                    stop_sample(mario_64);
                    ticket1 -= 1;
                    ticket2 -= 1;
                    tir_au_ballon(title,1,p_ticket1,p_ticket2,ballon,ciel,sprites_koopa,nombre,joueur1,joueur2,koopa,p_2score1,p_2score2,0,tirer,victory);
                    play_sample(mario_64, 255, 128, 1000, 0);
                }
            }

            if(getb(image) == 255 && getg(image) == 3) {
                textprintf_ex(page,font,joueur.x - 50,joueur.y - 30 ,makecol(0,0,0),-1,"Appuyé sur 'P' pour la course hyppique");
                if (key[KEY_P]) {  //Regard si le joueur veut accéder à l'attraction
                    stop_sample(mario_64);
                    ticket1 -= 1;
                    ticket2 -= 1;
                    course_hyppique_main(p_ticket1,p_ticket2,course);
                    play_sample(mario_64, 255, 128, 1000, 0);
                }
            }

            if(getb(image) == 255 && getg(image) == 4) {
                textprintf_ex(page,font,joueur.x - 50,joueur.y - 30 ,makecol(0,0,0),-1,"Appuyé sur 'P' pour le goombattack");
                if (key[KEY_P]) {  //Regard si le joueur veut accéder à l'attraction
                    stop_sample(mario_64);
                    ticket1 -= 1;
                    ticket2 -= 1;
                    goombattack_main(p_ticket1,p_ticket2,title,goomba,saut,victory);
                    //tir_au_ballon(title,1,p_ticket1,p_ticket2,ballon,ciel,sprites_koopa,nombre,joueur1,joueur2,koopa,p_2score1,p_2score2,0,tirer,victory);
                    play_sample(mario_64, 255, 128, 1000, 0);
                }
            }

            if(getb(image) == 255 && getg(image) == 254){
                textprintf_ex(page,font,joueur.x - 50,joueur.y - 30 ,makecol(0,0,0),-1,"Appuyé sur 'P' pour voir le classement");
                if(key[KEY_P]) {
                    affichage_score(affichagescore,best2,best1, joueur1, joueur2,score_1_game1,score_2_game1,score_1_game2,score_2_game2);
                }
            }
            if(getb(image) == 255 && getg(image) == 255){
                textprintf_ex(page,font,joueur.x - 50,joueur.y - 30 ,makecol(0,0,0),-1,"Appuyé sur 'P' pour quitter le jeu");
                if(key[KEY_P]) {
                    break;
                }
            }
            blit(page,screen,carte.x,carte.y,0,0,SCREEN_W,SCREEN_H);
        }
    }
    caract = fgetc(best1);

    //Enregistrement meilleur score jeu 1
    fseek(best1, 0, SEEK_SET);
    if(caract == 'N'){
        if(score_1_game2 < score_2_game2){
            fprintf(best1,"%d : %s\n",score_1_game2,joueur1);
        }else{
            fprintf(best1,"%d : %s\n",score_2_game2,joueur2);
        }

    }
    else{
        char c[3];
        int best;
        fgets(c,3,best1);
        best = atoi(c);
        if(score_1_game1 < score_2_game1){
            if(score_1_game1 < best) {
                fseek(best1, 0, SEEK_SET);
                fprintf(best1, "%d : %s\n", score_1_game1, joueur2);
            }
        }else{
            if(score_2_game1 < best) {
                fseek(best1, 0, SEEK_SET);
                fprintf(best1, "%d : %s\n", score_2_game1, joueur2);
            }
        }

    }
    fclose(best1);
    caract = fgetc(best2);
    printf("%c",caract);

    //Enregistrement meilleur score jeu 2
    fseek(best2, 0, SEEK_SET);
    if(caract == 'N'){
        if(score_1_game2 < score_2_game2){
            fprintf(best2,"%d : %s\n",score_1_game2,joueur1);
        }else{
            fprintf(best2,"%d : %s\n",score_2_game2,joueur2);
        }

    }
    else{
        char c[3];
        int best;
        fgets(c,3,best2);
        best = atoi(c);
        if(score_1_game2 < score_2_game2){
            if(score_1_game2 < best) {
                fseek(best2, 0, SEEK_SET);
                fprintf(best2, "%d : %s\n", score_1_game2, joueur1);
            }
        }else{
            if(score_2_game2 < best) {
                fseek(best2, 0, SEEK_SET);
                fprintf(best2, "%d : %s\n", score_2_game2, joueur2);
            }
        }

    }
    fclose(best2);


    allegro_exit();
}END_OF_MAIN()
