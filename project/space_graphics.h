/// @file           space_graphics.h
/// @author         OSADTSIV Ivan, SCHERBA Denys
/// @brief          TP2

#include "sdl2-light.h"
#include "space_logics.h"


#ifndef SPACE_GRAPHICS_H
#define SPACE_GRAPHICS_H


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

/// @brief          no
/// @param renderer no
/// @param texture  no
/// @param sprite   no
void apply_walls(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite);


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
