/// @file           space_logics.h
/// @author         OSADTSIV Ivan, SCHERBA Denys
/// @brief          TP2


#ifndef SPACE_GRAPHICS_H
#define SPACE_GRAPHICS_H

#include "sdl2-light.h"
#include "space_graphics.h"


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
