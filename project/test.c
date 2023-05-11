#include "sdl2-light.h"
#include <stdio.h>

#include "space_logics.h"
#include "space_graphics.h"
#include "space_const.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void init_sprite(sprite_t *sprite, int x, int y, int w, int h)
{
    sprite->x = x;
    sprite->y = y;
    sprite->w = w;
    sprite->h = h;
}

void test_init_sprite_param()
{
    sprite_t * test;
    int val = 1;
    init_sprite(test, val, val, val, val);
    print_sprite(test);
}


int main(int argc, char * argv[]) 
{
    test_init_sprite_param();
    return EXIT_SUCCESS;
}