/// @file           space_logics.h
/// @author         OSADTSIV Ivan, SCHERBA Denys
/// @brief          TP2

#include "sdl2-light.h"
#include "space_graphics.h"
#include "space_graphics.h"

#ifndef SPACE_LOGICS_H
#define SPACE_LOGICS_H

/// @brief          Représentation pour stocker les textures nécessaires à l'affichage graphique et type qui correspond aux textures du jeu
typedef struct textures_s
{
    SDL_Texture* background; /*!< Texture liée à l'image du fond de l'écran. */
    SDL_Texture* ship;
    SDL_Texture* line;
    SDL_Texture* meteorite;
} textures_t;

/// @brief           Type de sprite
typedef struct sprite_s
{
    int x;
    int y;
    int h;
    int w;
} sprite_t;

/// @brief           Type qui correspond aux données du monde
typedef struct world_s
{
    int gameover; /*!< Champ indiquant si l'on est à la fin du jeu */
    float vy;       /*!< A field indicate a vertical speed */
    sprite_t * ship;
    sprite_t * line;
    sprite_t * wall;
} world_t;


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
