#include "sdl2-light.h"
#include <stdio.h>

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
void init_sprite(sprite_t *sprite, int x, float y, int w, int h)
{
    sprite->x = x;
    sprite->y = y;
    sprite->w = w;
    sprite->h = h;
}

void test_init_sprite_param()
{
    sprite_t * test;
    int val1 = 1;
    int val2 = 50;
    test = malloc(sizeof(sprite_t));
    init_sprite(test, val1, val1, val2, val2);
    print_sprite(test);
}

 
int main(int argc, char * argv[]) 
{
    test_init_sprite_param();
    return 0;
}