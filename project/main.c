/// @file            main.c
/// @brief           Programme principal initial du niveau 1
/// @author          Mathieu Constant, Ivan Osadtsiv, Denys Scherba
/// @version         1.0
/// @date            10.04.2023


#include "sdl2-light.h"
#include <stdio.h>

#include "space_logics.h"
#include "space_graphics.h"
#include "space_const.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>



/// @brief Initiallisation of sprite_t
/// @param sprite 
/// @param x 
/// @param y 
/// @param w 
/// @param h 
void init_sprite(sprite_t *sprite, int x, int y, int w, int h)
{
    sprite->x = x;
    sprite->y = y;
    sprite->w = w;
    sprite->h = h;
}


/// @brief           La fonction initialise les données du monde du jeu
/// @param world     les données du monde
void init_data(world_t * world)
{
    //on n'est pas à la fin du jeu

    world->gameover = 0;
    world->vy = INITIAL_SPEED;

    world->ship = malloc(sizeof(sprite_t));
    init_sprite(world->ship, (SCREEN_WIDTH - SHIP_SIZE)/2, SCREEN_HEIGHT - SHIP_SIZE*2, SHIP_SIZE, SHIP_SIZE);

    world->line = malloc(sizeof(sprite_t));
    init_sprite(world->line, 0, FINISH_LINE_HEIGHT, SCREEN_WIDTH, 8);

    world->wall = malloc(sizeof(sprite_t));
    init_sprite(world->wall, (SCREEN_WIDTH-METEORITE_SIZE)/2, (SCREEN_HEIGHT - METEORITE_SIZE*3)/2, METEORITE_SIZE*3, METEORITE_SIZE*7);
}


/// @brief           La fonction initialise les textures nécessaires à l'affichage graphique du jeu
/// @param screen    la surface correspondant à l'écran de jeu
/// @param textures  les textures du jeu
void  init_textures(SDL_Renderer *renderer, textures_t *textures)
{
    textures->background = load_image( "ressources/space-background.bmp", renderer);
    textures->ship = load_image( "ressources/spaceship.bmp", renderer);
    textures->line = load_image( "ressources/finish_line.bmp", renderer);
    textures->meteorite = load_image( "ressources/meteorite.bmp", renderer);
}

/// @brief Function for creating 6 walls
/// @param world 
void init_walls(world_t * world){
    //
}


/// @brief           fonction qui initialise le jeu: initialisation de la partie graphique (SDL), chargement des textures, initialisation des données
/// @param window    la fenêtre du jeu
/// @param renderer  le renderer
/// @param textures  les textures
/// @param world     le monde
void init(SDL_Window **window, SDL_Renderer ** renderer, textures_t *textures, world_t * world)
{
    init_sdl(window,renderer,SCREEN_WIDTH, SCREEN_HEIGHT);
    init_data(world);
    init_textures(*renderer,textures);
}


/// @brief          programme principal qui implémente la boucle du jeu
int main( int argc, char* args[] )
{
    SDL_Event event;
    world_t world;
    textures_t textures;
    SDL_Renderer *renderer;
    SDL_Window *window;

    //initialisation du jeu
    init(&window,&renderer,&textures,&world);
    while(!is_game_over(&world)){ //tant que le jeu n'est pas fini
        
        //gestion des évènements
        handle_events(&event,&world);
        
        //mise à jour des données liée à la physique du monde
        update_data(&world, &textures);
        
        //rafraichissement de l'écran
        refresh_graphics(renderer,&world,&textures);
        
        // pause de 10 ms pour controler la vitesse de rafraichissement
        pause(10);
    }
    
    //nettoyage final
    clean(window,renderer,&textures,&world);
    
    
    return 0;
}
