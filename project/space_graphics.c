/// @file           space_graphics.c
/// @author         SHCHERBA Denys, OSADTSIV Ivan
/// @brief          File with methods responsible for game graphics

#include "space_graphics.h"
#include "space_const.h"
#include <stdlib.h>
#include <stdio.h>



void  init_textures(SDL_Renderer *renderer, resources_t *textures)
{
    const char *font_path;
    font_path = "arial.ttf";

    textures->background = load_image("ressources/space-background.bmp", renderer);
    textures->ship = load_image("ressources/spaceship.bmp", renderer);
    textures->line = load_image("ressources/finish_line.bmp", renderer);
    textures->meteorite = load_image("ressources/meteorite.bmp", renderer);

    textures->numbers[0] = load_image("ressources/text/0.bmp", renderer);
    textures->numbers[1] = load_image("ressources/text/1.bmp", renderer);
    textures->numbers[2] = load_image("ressources/text/2.bmp", renderer);
    textures->numbers[3] = load_image("ressources/text/3.bmp", renderer);
    textures->numbers[4] = load_image("ressources/text/4.bmp", renderer);
    textures->numbers[5] = load_image("ressources/text/5.bmp", renderer);
    textures->numbers[6] = load_image("ressources/text/6.bmp", renderer);
    textures->numbers[7] = load_image("ressources/text/7.bmp", renderer);
    textures->numbers[8] = load_image("ressources/text/8.bmp", renderer);
    textures->numbers[9] = load_image("ressources/text/9.bmp", renderer);
    textures->slow = load_image("ressources/text/slow.bmp", renderer);
    textures->win = load_image("ressources/text/u_win.bmp", renderer);
    textures->lose = load_image("ressources/text/loser.bmp", renderer);
    textures->time = load_image("ressources/text/ur_time.bmp", renderer);

    textures->font = load_font(font_path, 14);
}


void clean_textures(resources_t *textures)
{
    clean_texture(textures->background);
    clean_texture(textures->ship);
    clean_texture(textures->line);
    clean_texture(textures->meteorite);
    clean_font(textures->font);
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
            apply_texture(texture, renderer, sprite->x + METEORITE_SIZE*i, sprite->y + METEORITE_SIZE*j); 
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


void apply_timer(SDL_Renderer *renderer, TTF_Font *font)
{
    char *timer;
    timer = malloc(4*sizeof(char));
    sprintf(timer, "%d", ((int)(SDL_GetTicks()/1000)));
    apply_text(renderer, 0, 0, 100, 100, timer, font);
}


void text_output_lose(resources_t * textures, world_t * world, SDL_Renderer *renderer)
{
    apply_sprite(renderer, textures->lose, world->lose);
    update_screen(renderer);
}


void text_output_win(resources_t * textures, world_t * world, SDL_Renderer *renderer)
{
    apply_sprite(renderer, textures->win, world->win);
    apply_sprite(renderer, textures->time, world->time);
    if((int)(SDL_GetTicks()/1000) < 99)
    {
    apply_sprite(renderer, textures->numbers[((int)(SDL_GetTicks()/1000)) / 10], world->numbers[((int)(SDL_GetTicks()/1000)) / 10]);
    world->numbers[((int)(SDL_GetTicks()/1000)) % 10]->x += 25;
    apply_sprite(renderer, textures->numbers[((int)(SDL_GetTicks()/1000)) % 10], world->numbers[((int)(SDL_GetTicks()/1000)) % 10]);
    }
    else
    {
        apply_sprite(renderer, textures->slow, world->slow);
    }
    update_screen(renderer);
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
    //application le timer dans le renderer
    apply_timer(renderer, textures->font);
    // on met à jour l'écran
    update_screen(renderer);
}


void clean(SDL_Window *window, SDL_Renderer * renderer, resources_t *textures, world_t * world){
    clean_data(world);
    clean_textures(textures);
    clean_sdl(renderer,window);
}
