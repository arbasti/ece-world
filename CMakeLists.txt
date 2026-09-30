cmake_minimum_required(VERSION 3.10)
project(PROJET C)

set(CMAKE_C_STANDARD 99)

add_executable(PROJET main.c "Title Screen/title.c" "Title Screen/title.h" Game1/game1.c Game1/game1.h "Hub Scrolling/hub.c" "Hub Scrolling/hub.h" Game1/Bois_alea.c Game1/Bois_alea.h Game2/game2.c Game2/game2.h Joueur/Joueur.c Joueur/Joueur.h Classement/classement.c Classement/classement.h Game3/goombattack.h Game3/goombattack_main.c Game3/goombattack_init.c Game3/goombattack_goomba.c Game3/goombattack_moves.c
        Game4/course_hyppique_main.c Game4/course_hyppique_menu.c)
target_link_libraries(PROJET -lmingw32 allegro-4.4.2-monolith-md-debug.dll)

