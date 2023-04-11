#include "sdl2-light.h"
#include "space_graphic.h"
#include "space_const.h"

void print_sprite(sprite_t *sprite)
{
    printf("Coordinates of sprite are x:%d y:%d\n", sprite->x, sprite->y);
    printf("The size of sprite is H:%d W:%d\n", sprite->h, sprite->w);
}


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
    init_sprite(world->wall, (SCREEN_WIDTH-3*METEORITE_SIZE)/2, (SCREEN_HEIGHT - METEORITE_SIZE*7)/2, METEORITE_SIZE*7, METEORITE_SIZE*3);
}


void clean_data(world_t *world)
{
    /* utile uniquement si vous avez fait de l'allocation dynamique (malloc); la fonction ici doit permettre de libérer la mémoire (free) */
}


int is_game_over(world_t *world)
{
    return world->gameover;
}


void update_data(world_t *world)
{
    world->line->y += world->vy;
    world->wall->y += world->vy;
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


void  init_textures(SDL_Renderer *renderer, textures_t *textures)
{
    textures->background = load_image( "ressources/space-background.bmp", renderer);
    textures->ship = load_image( "ressources/spaceship.bmp", renderer);
    textures->line = load_image( "ressources/finish_line.bmp", renderer);
    textures->meteorite = load_image( "ressources/meteorite.bmp", renderer);
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


void init(SDL_Window **window, SDL_Renderer ** renderer, textures_t *textures, world_t * world)
{
    init_sdl(window,renderer,SCREEN_WIDTH, SCREEN_HEIGHT);
    init_data(world);
    init_textures(*renderer,textures);
}
