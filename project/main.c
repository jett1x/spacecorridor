/**
 * \file            main.c
 * \brief           Programme principal initial du niveau 1
 * \author          Mathieu Constant, Ivan Osadtsiv, Denys Scherba
 * \version         1.0
 * \date            10.04.2023
 */

#include "sdl2-light.h"
#include <stdio.h>


/**
 * \brief           Largeur de l'écran de jeu
 */
#define SCREEN_WIDTH 300

/**
 * \brief           Hauteur de l'écran de jeu
 */
#define SCREEN_HEIGHT 480


/**
 * \brief           Taille d'un vaisseau
 */

#define SHIP_SIZE 32


/**
 * \brief           Taille d'un météorite
*/

#define METEORITE_SIZE 32


/**
 * \brief           Hauteur de la ligne d'arrivée
 */


#define FINISH_LINE_HEIGHT 10


/**
 * \brief           Pas de déplacement horizontal du vaisseau
*/

#define MOVING_STEP 10


/**
  * \brief          Vitesse initiale de déplacement vertical des éléments du jeu 
*/

#define INITIAL_SPEED 2


/**
 * \brief           Représentation pour stocker les textures nécessaires à l'affichage graphique et type qui correspond aux textures du jeu
*/

typedef struct textures_s
{
    SDL_Texture* background; /*!< Texture liée à l'image du fond de l'écran. */
    SDL_Texture* ship;
    SDL_Texture* line;
    SDL_Texture* meteorite;
}textures_t;

/**
 * \brief           Type de sprite
*/
typedef struct sprite_s
{
    int x;
    int y;
    int h;
    int w;
} sprite_t;

/**
 * \brief           Type qui correspond aux données du monde
 */

typedef struct world_s
{
    int gameover; /*!< Champ indiquant si l'on est à la fin du jeu */
    int vy;       /*!< A field indicate a vertical speed */
    sprite_t * ship;
    sprite_t * line;
    sprite_t * wall;
}world_t;


void init_sprite(sprite_t *sprite, int x, int y, int w, int h)
{
    sprite->x = x;
    sprite->y = y;
    sprite->w = w;
    sprite->h = h;
}

/// @brief Writes to console all the data correspond to particular sprite
/// @param sprite a sprite you want to get information about
void print_sprite(sprite_t *sprite)
{
    printf("Coordinates of sprite are x:%d y:%d\n", sprite->x, sprite->y);
    printf("The size of sprite is H:%d W:%d\n", sprite->h, sprite->w);
}

/**
 * \brief           La fonction initialise les données du monde du jeu
 * \param world     les données du monde
 */

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
    init_sprite(world->wall, (SCREEN_WIDTH - METEORITE_SIZE*7)/2, SCREEN_HEIGHT/2 - 1.5*METEORITE_SIZE, METEORITE_SIZE*7, METEORITE_SIZE*3);
}


/**
 * \brief           La fonction nettoie les données du monde
 * \param world     les données du monde
 */


void clean_data(world_t *world){
    /* utile uniquement si vous avez fait de l'allocation dynamique (malloc); la fonction ici doit permettre de libérer la mémoire (free) */
    
}



/**
 * \brief           La fonction indique si le jeu est fini en fonction des données du monde
 * \param world     les données du monde
 * \return          1 si le jeu est fini, 0 sinon
 */

int is_game_over(world_t *world)
{
    return world->gameover;
}



/**
 * \brief           La fonction met à jour les données en tenant compte de la physique du monde
 * \param les       données du monde
 */

void update_data(world_t *world)
{
    world->line->y += world->vy;
}



/**
 * \brief           La fonction gère les évènements ayant eu lieu et qui n'ont pas encore été traités
 * \param event     paramètre qui contient les événements
 * \param world     les données du monde
 */

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
            }
        }
    }
}

/**
 * \brief           La fonction initialise les textures nécessaires à l'affichage graphique du jeu
 * \param screen    la surface correspondant à l'écran de jeu
 * \param textures  les textures du jeu
*/

void  init_textures(SDL_Renderer *renderer, textures_t *textures)
{
    textures->background = load_image( "ressources/space-background.bmp", renderer);
    textures->ship = load_image( "ressources/spaceship.bmp", renderer);
    textures->line = load_image( "ressources/finish_line.bmp", renderer);
    textures->meteorite = load_image( "ressources/meteorite.bmp", renderer);
}

/**
 * \brief           La fonction nettoie les textures
 * \param textures  les textures
*/

void clean_textures(textures_t *textures)
{
    clean_texture(textures->background);
    clean_texture(textures->ship);
    clean_texture(textures->line);
    clean_texture(textures->meteorite);
}

/**
 * \brief           La fonction applique la texture du fond sur le renderer lié à l'écran de jeu
 * \param renderer  le renderer
 * \param texture   la texture liée au fond
*/

void apply_background(SDL_Renderer *renderer, SDL_Texture *texture)
{
    if(texture != NULL){
      apply_texture(texture, renderer, 0, 0);
    }
}

/// @brief          Applies sprint on a screen
/// @param renderer renderer
/// @param texture  texture
/// @param sprite   sprite to apply
void apply_sprite(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite)
{
    apply_texture(texture, renderer, sprite->x, sprite->y);
}

/**
 * \brief           La fonction rafraichit l'écran en fonction de l'état des données du monde
 * \param renderer  le renderer lié à l'écran de jeu
 * \param world     les données du monde
 * \param textures  les textures
 */

void refresh_graphics(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    
    //on vide le renderer
    clear_renderer(renderer);
    //application des textures dans le renderer
    apply_background(renderer, textures->background);
    //application de vaisseau texture dans le renderer
    apply_sprite(renderer, textures->ship, world->ship);
    //application de ligne texture dans le renderer
    apply_sprite(renderer, textures->line, world->line);
    // on met à jour l'écran
    update_screen(renderer);
}



/**
* \brief            fonction qui nettoie le jeu: nettoyage de la partie graphique (SDL), nettoyage des textures, nettoyage des données
* \param window     la fenêtre du jeu
* \param renderer   le renderer
* \param textures   les textures
* \param world      le monde
*/

void clean(SDL_Window *window, SDL_Renderer * renderer, textures_t *textures, world_t * world){
    clean_data(world);
    clean_textures(textures);
    clean_sdl(renderer,window);
}



/**
 * \brief           fonction qui initialise le jeu: initialisation de la partie graphique (SDL), chargement des textures, initialisation des données
 * \param window    la fenêtre du jeu
 * \param renderer  le renderer
 * \param textures  les textures
 * \param world     le monde
 */

void init(SDL_Window **window, SDL_Renderer ** renderer, textures_t *textures, world_t * world){
    init_sdl(window,renderer,SCREEN_WIDTH, SCREEN_HEIGHT);
    init_data(world);
    init_textures(*renderer,textures);
}


/**
 *  \brief          programme principal qui implémente la boucle du jeu
 */


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
        update_data(&world);
        
        //rafraichissement de l'écran
        refresh_graphics(renderer,&world,&textures);
        
        // pause de 10 ms pour controler la vitesse de rafraichissement
        pause(10);
    }
    
    //nettoyage final
    clean(window,renderer,&textures,&world);
    
    
    return 0;
}
