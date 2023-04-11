/// @file           space_graphic.h
/// @author         OSADTSIV Ivan, SCHERBA Denys
/// @brief          TP2


#ifndef SPACE_GRAPHIC_H
#define SPACE_GRAPHIC_H

#include "sdl2-light.h"


/// @brief Initiallisation of sprite_t
/// @param sprite 
/// @param x 
/// @param y 
/// @param w 
/// @param h 
void init_sprite(sprite_t *sprite, int x, int y, int w, int h);


/// @brief          Writes to console all the data correspond to particular sprite
/// @param sprite   a sprite you want to get information about
void print_sprite(sprite_t *sprite);


/// @brief          La fonction initialise les données du monde du jeu
/// @param world    les données du monde
void init_data(world_t * world);


/// @brie           La fonction nettoie les données du monde
/// @param world    les données du monde
void clean_data(world_t *world);


/// @brief          La fonction indique si le jeu est fini en fonction des données du monde
/// @param world    les données du monde
/// @return         1 si le jeu est fini, 0 sinon
int is_game_over(world_t *world);


/// @brief          La fonction met à jour les données en tenant compte de la physique du monde
/// @param les      données du monde
void update_data(world_t *world);


/// @brief          La fonction gère les évènements ayant eu lieu et qui n'ont pas encore été traités
/// @param event    paramètre qui contient les événements
/// @param world    les données du monde
void handle_events(SDL_Event *event,world_t *world);


/// @brief          La fonction initialise les textures nécessaires à l'affichage graphique du jeu
/// @param screen   la surface correspondant à l'écran de jeu
/// @param textures les textures du jeu
void  init_textures(SDL_Renderer *renderer, textures_t *textures);


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


/// @brief          fonction qui initialise le jeu: initialisation de la partie graphique (SDL), chargement des textures, initialisation des données
/// @param window   la fenêtre du jeu
/// @param renderer le renderer
/// @param textures les textures
/// @param world    le monde
void init(SDL_Window **window, SDL_Renderer ** renderer, textures_t *textures, world_t * world);
