/// @file            main.c
/// @brief           Main file responsible for game functionality
/// @author          Mathieu Constant, Denys SHCHERBA, Ivan OSADTSIV
/// @version         1.0
/// @date            10.04.2023


#include "sdl2-light.h"
#include "sdl2-ttf-light.h"

#include "space_logics.h"
#include "space_graphics.h"
#include "space_const.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>



/// @brief          Initiallisation of sprite_t
/// @param sprite   sprite
/// @param x        x coordinate
/// @param y        y coordinate
/// @param w        width
/// @param h        heigth
void init_sprite(sprite_t *sprite, int x, int y, int w, int h)
{
    sprite->x = x;
    sprite->y = y;
    sprite->w = w;
    sprite->h = h;
}


/// @brief          La fonction initialise les données du monde du jeu
/// @param world    les données du monde
void init_data(world_t * world)
{
    //on n'est pas à la fin du jeu

    world->gameover = 0;
    world->vy = INITIAL_SPEED;

    world->ship = malloc(sizeof(sprite_t));
    init_sprite(world->ship, (SCREEN_WIDTH - SHIP_SIZE)/2, SCREEN_HEIGHT - SHIP_SIZE*2, SHIP_SIZE, SHIP_SIZE);

    world->line = malloc(sizeof(sprite_t));
    init_sprite(world->line, 0, FINISH_LINE_HEIGHT, SCREEN_WIDTH, 8);

    //world->wall = malloc(sizeof(sprite_t));
    //init_sprite(world->wall, (SCREEN_WIDTH-METEORITE_SIZE)/2, (SCREEN_HEIGHT - METEORITE_SIZE*3)/2, METEORITE_SIZE*3, METEORITE_SIZE*7);
}


/// @brief          La fonction initialise les sprites de text
/// @param world    les données du monde
void init_text(world_t * world)
{
    world->lose = malloc(sizeof(sprite_t));
    init_sprite(world->lose, (SCREEN_WIDTH-256)/2, (SCREEN_HEIGHT-52)/2, -1, -1);
    world->win = malloc(sizeof(sprite_t));
    init_sprite(world->win, (SCREEN_WIDTH-265)/2, SCREEN_HEIGHT/2-62, -1, -1);
    world->time = malloc(sizeof(sprite_t));
    init_sprite(world->time, (SCREEN_WIDTH-177)/2 - 26, SCREEN_HEIGHT/2, -1, -1);
    for(size_t i = 0; i < 10; i++)
    {
        world->numbers[i] = malloc(sizeof(sprite_t));
        init_sprite(world->numbers[i], (SCREEN_WIDTH+177)/2 - 20, SCREEN_HEIGHT/2, -1, -1);
    }
    world->slow = malloc(sizeof(sprite_t));
    init_sprite(world->slow, (SCREEN_WIDTH+177)/2 - 20, SCREEN_HEIGHT/2, -1, -1);
}


/// @brief           La fonction initialise les murs
/// @param world     les données du monde
void init_walls(world_t * world)
{
    world->wall0 = malloc(sizeof(sprite_t));
    init_sprite(world->wall0, 48 - 1.5 * METEORITE_SIZE, 0, 96, 192);

    world->wall1 = malloc(sizeof(sprite_t));
    init_sprite(world->wall1, 252 - 1.5 * METEORITE_SIZE, 0, 96, 192);

    world->wall2 = malloc(sizeof(sprite_t));
    init_sprite(world->wall2, 16 - 0.5 * METEORITE_SIZE, -352, 32, 160);

    world->wall3 = malloc(sizeof(sprite_t));
    init_sprite(world->wall3, 188 - 1.5 * METEORITE_SIZE, -352, 224, 160);

    world->wall4 = malloc(sizeof(sprite_t));
    init_sprite(world->wall4, 48 - 1.5 * METEORITE_SIZE, -672, 96, 192);

    world->wall5 = malloc(sizeof(sprite_t));
    init_sprite(world->wall5, 252 - 1.5 * METEORITE_SIZE, -672, 96, 192);
}


/// @brief           fonction qui initialise le jeu: initialisation de la partie graphique (SDL), chargement des textures, initialisation des données
/// @param window    la fenêtre du jeu
/// @param renderer  le renderer
/// @param textures  les textures
/// @param world     le monde
void init(SDL_Window **window, SDL_Renderer ** renderer, resources_t *textures, world_t * world)
{
    init_sdl(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    init_data(world);
    init_ttf();
    init_textures(*renderer, textures);
    init_walls(world);
    init_text(world);
}


/// @brief           programme principal qui implémente la boucle du jeu
int main( int argc, char* args[] )
{
    SDL_Event event;
    world_t world;
    resources_t textures;
    SDL_Renderer *renderer;
    SDL_Window *window;

    //initialisation du jeu
    init(&window,&renderer,&textures,&world);
    while(!is_game_over(&world)){ //tant que le jeu n'est pas fini
        
        //gestion des évènements
        handle_events(&event,&world);
        
        //rafraichissement de l'écran
        refresh_graphics(renderer,&world,&textures);

        //mise à jour des données liée à la physique du monde
        update_data(&world, &textures, renderer);
        
        // pause de 10 ms pour controler la vitesse de rafraichissement
        pause(10);
    }
    pause(2000);

    //nettoyage final
    clean(window,renderer,&textures,&world);
    
    
    return 0;
}
