/// @file           test.c
/// @author         SHCHERBA Denys, OSADTSIV Ivan
/// @brief          file to test some important mechanics

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

void test_init_sprite_param(int x, int y, int w, int h)
{
    sprite_t * test;
    test = malloc(sizeof(sprite_t));
    init_sprite(test, x, y, w, h);
    print_sprite(test);
}

void test_init_sprite()
{
    test_init_sprite_param(1, 1, 50, 50);
    test_init_sprite_param(40, 32, 20, 51);
    test_init_sprite_param(14, 18, 88, 30);
    test_init_sprite_param(5, 4, 67, 54);
}

 
int main(int argc, char * argv[]) 
{
    test_init_sprite();
    return 0;
}