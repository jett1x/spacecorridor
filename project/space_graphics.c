/// @file           space_graphics.c
/// @author         SHCHERBA Denys, OSADTSIV Ivan
/// @brief          File with methods responsible for game graphics

#include "sdl2-light.h"
#include "space_graphics.h"
#include "space_logics.h"
#include "sdl2-ttf-light.h"
#include "space_const.h"
#include <stdlib.h>
#include <stdio.h>

void print_sprite(sprite_t *sprite)
{
    printf("Coordinates of sprite are X:%d Y:%d\n", sprite->x, sprite->y);
    printf("The size of sprite is H:%d W:%d\n", sprite->h, sprite->w);
}


void clean_textures(resources_t *textures)
{
    clean_texture(textures->background);
    clean_texture(textures->ship);
    clean_texture(textures->line);
    clean_texture(textures->meteorite);
}


void apply_background(SDL_Renderer *renderer, SDL_Texture *texture)
{
    if(texture != NULL){
      apply_texture(texture, renderer, 0, 0);
    }
}


void apply_sprite(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite)
{
    apply_texture(texture, renderer, sprite->x, sprite->y);
}


void apply_wall(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite)
{
    for(size_t i = 0; i < (sprite->w / METEORITE_SIZE); i++)
    {
        for(size_t j = 0; j < (sprite->h / METEORITE_SIZE); j++)
        {
            apply_texture(texture, renderer, (sprite->x - METEORITE_SIZE) + METEORITE_SIZE*i, (sprite->y - 3*METEORITE_SIZE) + METEORITE_SIZE*j); 
        }
    }
}

void apply_walls(SDL_Renderer *renderer, SDL_Texture *texture, world_t *world)
{   
    apply_wall(renderer, texture, world->wall0);
    apply_wall(renderer, texture, world->wall1);
    apply_wall(renderer, texture, world->wall2);
    apply_wall(renderer, texture, world->wall3);
    apply_wall(renderer, texture, world->wall4);
    apply_wall(renderer, texture, world->wall5);
}

void refresh_graphics(SDL_Renderer *renderer, world_t *world,resources_t *textures){
    
    //on vide le renderer
    clear_renderer(renderer);
    //application des textures dans le renderer
    apply_background(renderer, textures->background);
    //application de vaisseau texture dans le renderer
    apply_sprite(renderer, textures->ship, world->ship);
    //application de ligne texture dans le renderer
    apply_sprite(renderer, textures->line, world->line);
    //application de mur des meteorites dans le renderer
    //apply_wall(renderer, textures->meteorite, world->wall);
    //application des murs des meteorites dans le renderer
    apply_walls(renderer, textures->meteorite, world);
    // on met à jour l'écran
    update_screen(renderer);
}


void clean(SDL_Window *window, SDL_Renderer * renderer, resources_t *textures, world_t * world){
    clean_data(world);
    clean_textures(textures);
    clean_sdl(renderer,window);
}




