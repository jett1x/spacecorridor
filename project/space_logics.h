/// @file           space_logics.h
/// @author         OSADTSIV Ivan, SCHERBA Denys
/// @brief          TP2


#ifndef SPACE_GRAPHICS_H
#define SPACE_GRAPHICS_H

#include "sdl2-light.h"



/// @brief           Type qui correspond aux données du monde
typedef struct world_s
{
    int gameover; /*!< Champ indiquant si l'on est à la fin du jeu */
    float vy;       /*!< A field indicate a vertical speed */
    sprite_t * ship;
    sprite_t * line;
    sprite_t * wall;
}world_t;



/// @brief          La fonction indique si le jeu est fini en fonction des données du monde
/// @param world    les données du monde
/// @return         1 si le jeu est fini, 0 sinon
int is_game_over(world_t *world);


/// @brief          La fonction met à jour les données en tenant compte de la physique du monde
/// @param les      données du monde
void update_data(world_t *world);


/// @brie           La fonction nettoie les données du monde
/// @param world    les données du monde
void clean_data(world_t *world);


/// @brief          La fonction gère les évènements ayant eu lieu et qui n'ont pas encore été traités
/// @param event    paramètre qui contient les événements
/// @param world    les données du monde
void handle_events(SDL_Event *event,world_t *world);

#endif
