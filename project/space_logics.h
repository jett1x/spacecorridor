/// @file           space_logics.h
/// @author         SHCHERBA Denys, OSADTSIV Ivan
/// @brief          File with classes and methods responsible for game logics

#include "sdl2-light.h"
#include "SDL2/SDL.h"

#include "sdl2-ttf-light.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#ifndef SPACE_LOGICS_H
#define SPACE_LOGICS_H

/// @brief          Représentation pour stocker les textures nécessaires à l'affichage graphique et type qui correspond aux textures du jeu
typedef struct resources_s
{
    SDL_Texture* background; /*!< Texture liée à l'image du fond de l'écran. */
    SDL_Texture* ship;
    SDL_Texture* line;
    SDL_Texture* meteorite;
    SDL_Texture* numbers[10];
    SDL_Texture* win;
    SDL_Texture* lose;
    SDL_Texture* slow;
    SDL_Texture* time;
    TTF_Font* font;
} resources_t;

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
    int gameover;   /*!< Champ indiquant si l'on est à la fin du jeu */
    float vy;       /*!< A field indicate a vertical speed */
    sprite_t * ship;
    sprite_t * line;
    //sprite_t * wall;
    sprite_t * wall0;
    sprite_t * wall1;
    sprite_t * wall2;
    sprite_t * wall3;
    sprite_t * wall4;
    sprite_t * wall5;
    sprite_t * numbers[10];
    sprite_t * win;
    sprite_t * lose;
    sprite_t * slow;
    sprite_t * time;
} world_t;


/// @brief          La fonction indique si le jeu est fini en fonction des données du monde
/// @param world    les données du monde
/// @return         1 si le jeu est fini, 0 sinon
int is_game_over(world_t *world);


/// @brief          checks if sprites collide
/// @param sp1      sprite 1
/// @param sp2      sprite 2
/// @return         1 if sprites collide, else 0
bool sprites_collide(sprite_t *sp1, sprite_t *sp2);


/// @brief          if sprites collide, resets vertical velocity to 0
/// @param sp1      sprite 1
/// @param sp2      sprite 2
/// @param world    world
/// @param texture1 texture of the first sprite
/// @return         1 if sprites collide, else 0
bool handle_sprites_collision(sprite_t *sp1, sprite_t *sp2, world_t *world, SDL_Texture *texture1);


/// @brief          checks if ship collide with walls
/// @param world    world
/// @param textures textures
/// @param renderer renderer
void handle_walls_collision(world_t *world, resources_t *textures, SDL_Renderer *renderer);


/// @brief          checks if ship reached the finish line
/// @param world    world
/// @param ship     ship texture
void handle_finish_line_collision(world_t *world, SDL_Texture *ship);


/// @brief          La fonction met à jour les données en tenant compte de la physique du monde
/// @param world    données du monde
/// @param textures textures
/// @param renderer renderer
void update_data(world_t *world, resources_t *textures, SDL_Renderer *renderer);


/// @brief          La fonction nettoie les données du monde
/// @param world    les données du monde
void clean_data(world_t *world);


/// @brief          La fonction gère les évènements ayant eu lieu et qui n'ont pas encore été traités
/// @param event    paramètre qui contient les événements
/// @param world    les données du monde
void handle_events(SDL_Event *event,world_t *world);

#endif
