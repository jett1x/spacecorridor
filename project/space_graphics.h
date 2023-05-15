/// @file           space_graphics.h
/// @author         SHCHERBA Denys, OSADTSIV Ivan
/// @brief          File with classes and methods responsible for game graphics

#include "sdl2-light.h"
#include "space_logics.h"
#include "sdl2-ttf-light.h"


#ifndef SPACE_GRAPHICS_H
#define SPACE_GRAPHICS_H


/// @brief          Writes to console all the data correspond to particular sprite
/// @param sprite   a sprite you want to get information about
void print_sprite(sprite_t *sprite);


/// @brief          La fonction nettoie les textures
/// @param textures les textures
void clean_textures(resources_t *textures);


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
void apply_walls(SDL_Renderer *renderer, SDL_Texture *texture, world_t *world);


/// @brief          function responsible for printing out on the screen "You lost" message
/// @param textures game textures
/// @param world    world data
/// @param renderer renderer
void text_output_lose(resources_t * textures, world_t * world, SDL_Renderer *renderer);


/// @brief          function responsible for printing out on the screen "You win" message
/// @param textures game textures
/// @param world    world data
/// @param renderer renderer
void text_output_win(resources_t * textures, world_t * world, SDL_Renderer *renderer);


/// @brief          La fonction rafraichit l'écran en fonction de l'état des données du monde
/// @param renderer le renderer lié à l'écran de jeu
/// @param world    les données du monde
/// @param textures les textures
void refresh_graphics(SDL_Renderer *renderer, world_t *world, resources_t *textures);




/// @brief          fonction qui nettoie le jeu: nettoyage de la partie graphique (SDL), nettoyage des textures, nettoyage des données
/// @param window   la fenêtre du jeu
/// @param renderer le renderer
/// @param textures les textures
/// @param world    le monde
void clean(SDL_Window *window, SDL_Renderer * renderer, resources_t *textures, world_t * world);

#endif
