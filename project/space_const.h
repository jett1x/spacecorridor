/// @file           space_const.h
/// @author         OSADTSIV Ivan, SCHERBA Denys
/// @brief          TP2


#ifndef SPACE_CONST_H
#define SPACE_CONST_H

#include "sdl2-light.h"


/// @brief           Largeur de l'écran de jeu
#define SCREEN_WIDTH 300


/// @brief           Hauteur de l'écran de jeu
#define SCREEN_HEIGHT 480


/// @brief           Taille d'un vaisseau
#define SHIP_SIZE 32


/// @brief           Taille d'un météorite
#define METEORITE_SIZE 32


/// @brief           Hauteur de la ligne d'arrivée
#define FINISH_LINE_HEIGHT 10


/// @brief           Pas de déplacement horizontal du vaisseau
#define MOVING_STEP 10


/// @brief          Vitesse initiale de déplacement vertical des éléments du jeu 
#define INITIAL_SPEED 2


/// @brief            Pas de changement de vitesse
#define SPEED_DELTA 0.5


/// @brief          Représentation pour stocker les textures nécessaires à l'affichage graphique et type qui correspond aux textures du jeu
typedef struct textures_s
{
    SDL_Texture* background; /*!< Texture liée à l'image du fond de l'écran. */
    SDL_Texture* ship;
    SDL_Texture* line;
    SDL_Texture* meteorite;
}textures_t;


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
}world_t;
