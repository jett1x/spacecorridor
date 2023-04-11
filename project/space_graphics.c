#include "sdl2-light.h"
#include "space_graphics.h"
#include "space_logics.h"
#include "space_const.h"
#include <stdlib.h>
#include <stdio.h>

void print_sprite(sprite_t *sprite)
{
    printf("Coordinates of sprite are x:%d y:%d\n", sprite->x, sprite->y);
    printf("The size of sprite is H:%d W:%d\n", sprite->h, sprite->w);
}


void clean_textures(textures_t *textures)
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
    for(size_t i = 0; i < 3; i++)
    {
        for(size_t j = 0; j < 7; j++)
        {
            apply_texture(texture, renderer, sprite->x + METEORITE_SIZE*i, sprite->y + METEORITE_SIZE*j); 
        }
    }
}


void refresh_graphics(SDL_Renderer *renderer, world_t *world,textures_t *textures)
{
    //on vide le renderer
    clear_renderer(renderer);
    //application des textures dans le renderer
    apply_background(renderer, textures->background);
    //application de vaisseau texture dans le renderer
    apply_sprite(renderer, textures->ship, world->ship);
    //application de ligne texture dans le renderer
    apply_sprite(renderer, textures->line, world->line);
    //application de mur des meteorites dans le renderer
    apply_wall(renderer, textures->meteorite, world->wall);
    // on met à jour l'écran
    update_screen(renderer);
}


void clean(SDL_Window *window, SDL_Renderer * renderer, textures_t *textures, world_t * world)
{
    clean_data(world);
    clean_textures(textures);
    clean_sdl(renderer,window);
}
