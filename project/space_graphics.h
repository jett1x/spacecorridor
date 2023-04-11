/// @file           space_graphics.h
/// @author         OSADTSIV Ivan, SCHERBA Denys
/// @brief          TP2


#ifndef SPACE_GRAPHICS_H
#define SPACE_GRAPHICS_H

#include "sdl2-light.h"


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


/// @brief          Writes to console all the data correspond to particular sprite
/// @param sprite   a sprite you want to get information about
void print_sprite(sprite_t *sprite);


/// @brief          La fonction nettoie les textures
/// @param textures les textures
void clean_textures(textures_t *textures);


/// @brief          La fonction applique la texture du fond sur le renderer lié à l'écran de jeu
/// @param renderer le renderer
/// @param texture  la texture liée au fond
void apply_background(SDL_Renderer *renderer, SDL_Texture *texture);


/// @brief          Applies sprite on a screen
/// @param renderer renderer
/// @param texture  texture
/// @param sprite   sprite to apply
void apply_sprite(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite);


/// @brief          Applies a wall of sprites on a screen
/// @param renderer renderer
/// @param texture  texture
/// @param sprite   sprite to apply
void apply_wall(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite);


/// @brief          La fonction rafraichit l'écran en fonction de l'état des données du monde
/// @param renderer le renderer lié à l'écran de jeu
/// @param world    les données du monde
/// @param textures les textures
void refresh_graphics(SDL_Renderer *renderer, world_t *world,textures_t *textures);


/// @brief          fonction qui nettoie le jeu: nettoyage de la partie graphique (SDL), nettoyage des textures, nettoyage des données
/// @param window   la fenêtre du jeu
/// @param renderer le renderer
/// @param textures les textures
/// @param world    le monde
void clean(SDL_Window *window, SDL_Renderer * renderer, textures_t *textures, world_t * world);

#endif
