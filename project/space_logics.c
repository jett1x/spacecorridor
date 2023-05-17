/// @file           space_logics.c
/// @author         SHCHERBA Denys, OSADTSIV Ivan
/// @brief          File with methods responsible for game logics

#include "space_logics.h"
#include "space_const.h"
#include "space_graphics.h"


int is_game_over(world_t *world)
{
    return world->gameover;
}


void print_sprite(sprite_t *sprite)
{
    printf("Coordinates of sprite are X:%d Y:%f\n", sprite->x, sprite->y);
    printf("The size of sprite is H:%d W:%d\n", sprite->h, sprite->w);
}


bool sprites_collide(sprite_t *sp1, sprite_t *sp2)
{
    if((abs(sp1->x + sp1->w/2 - sp2->x - sp2->w/2) <= (sp1->w + sp2->w)/2) && (abs(sp1->y + sp1->h/2 - sp2->y - sp2->h/2) <= (sp1->h + sp2->h)/2))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


bool handle_sprites_collision(sprite_t *sp1, sprite_t *sp2, world_t *world, SDL_Texture *texture1)
{
    if(sprites_collide(sp1, sp2))
    {
        world->vy = 0;
        clean_texture(texture1);
        world->gameover = 1;
        return 1;
    }
    return 0;
}


void handle_walls_collision(world_t *world, resources_t *textures, SDL_Renderer *renderer)
{
    //handle_sprites_collision(world->ship, world->wall, world, textures->ship);

    if(
        handle_sprites_collision(world->ship, world->wall0, world, textures->ship)
        ||
        handle_sprites_collision(world->ship, world->wall1, world, textures->ship)
        ||
        handle_sprites_collision(world->ship, world->wall2, world, textures->ship)
        ||
        handle_sprites_collision(world->ship, world->wall3, world, textures->ship)
        ||
        handle_sprites_collision(world->ship, world->wall4, world, textures->ship)
        ||
        handle_sprites_collision(world->ship, world->wall5, world, textures->ship)
        )
        {
            text_output_lose(textures, world, renderer);
        }
}


void handle_finish_line_collision(world_t *world, resources_t *textures, SDL_Renderer *renderer)
{
    if(handle_sprites_collision(world->ship, world->line, world, textures->ship))
    {
        printf("You finished in %d seconds\n", (int)(SDL_GetTicks()/1000));
        text_output_win(textures, world, renderer);
    }
}


void update_walls(world_t *world, resources_t *textures)
{
    world->wall0->y += world->vy;
    world->wall1->y += world->vy;
    world->wall2->y += world->vy;
    world->wall3->y += world->vy;
    world->wall4->y += world->vy;
    world->wall5->y += world->vy;
}


void update_data(world_t *world, resources_t *textures, SDL_Renderer *renderer)
{
    world->line->y += world->vy;
    //world->wall->y += world->vy;
    update_walls(world, textures);

    handle_walls_collision(world, textures, renderer);

    handle_finish_line_collision(world, textures, renderer);
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
                if(world->ship->x + SHIP_SIZE * 1.25 < SCREEN_WIDTH)
                {
                    (world->ship->x) += MOVING_STEP;
                    break;
                }
                else
                {
                    break;
                }

            // si la touche appuyée est 'LEFT'
            case SDLK_LEFT:
                if(world->ship->x - SHIP_SIZE * 0.25 > 0)
                {
                    (world->ship->x) -= MOVING_STEP;
                    break;
                }
                else
                {
                    break;
                }

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
