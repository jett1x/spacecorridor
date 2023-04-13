#include "space_logics.h"
#include "space_const.h"
#include "space_graphics.h"
#include "sdl2-light.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int is_game_over(world_t *world)
{
    return world->gameover;
}


bool sprites_collide(sprite_t *sp1, sprite_t *sp2)
{
    if((abs(sp1->x - sp2->x) <= (sp1->w + sp2->w)/2) && (abs(sp1->y - sp2->y) <= (sp1->h + sp2->h)/2))
    {
        printf("COLLISION\n");
        return 1;
    }
    else
    {
        return 0;
    }
}


void handle_sprites_collision(sprite_t *sp1, sprite_t *sp2, world_t *world, SDL_Texture *texture1)
{
    bool make_dissapear = 0;
    if(sprites_collide(sp1, sp2))
    {
        world->vy = 0;
        make_dissapear = 1;
    }

    if(make_dissapear)
    {
        clean_texture(texture1);
    }
}


void update_data(world_t *world, textures_t *textures)
{
    world->line->y += world->vy;
    world->wall->y += world->vy;

    handle_sprites_collision(world->ship, world->wall, world, textures->ship);
}


void clean_data(world_t *world)
{
    /* utile uniquement si vous avez fait de l'allocation dynamique (malloc); la fonction ici doit permettre de libérer la mémoire (free) */
}


void handle_events(SDL_Event *event,world_t *world)
{
    Uint8 *keystates;
    while( SDL_PollEvent( event ) ) 
    {
        
        //Si l'utilisateur a cliqué sur le X de la fenêtre
        if( event->type == SDL_QUIT ) 
        {
            //On indique la fin du jeu
            world->gameover = 1;
        }
       
         //si une touche est appuyée
         if(event->type == SDL_KEYDOWN){
            switch (event->key.keysym.sym)
            {
            //si la touche appuyée est 'D'
            case SDLK_d:
                printf("La touche D est appuyée\n");
                break;
            // si la touche appuyée est 'RIGHT'
            case SDLK_RIGHT:
                (world->ship->x) += MOVING_STEP;
                break;
            // si la touche appuyée est 'LEFT'
            case SDLK_LEFT:
                (world->ship->x) -= MOVING_STEP;
                break;
            // si la touche appuyée est 'ESC'
            case SDLK_ESCAPE:
                world->gameover = 1;
                break;
            // si la touche appuyée est 'DOWN'
            case SDLK_DOWN:
                (world->vy) -= SPEED_DELTA;
                break;
            // si la touche appuyée est 'UP'
            case SDLK_UP:
                (world->vy) += SPEED_DELTA;
                break;
            }
        }
    }
}
