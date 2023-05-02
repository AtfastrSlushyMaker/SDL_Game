#ifndef MENU_H
#define MENU_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "../game.h"

void anim_boat(image *IMAGE, SDL_Surface *screen);
void anim_balloon(image *IMAGE, SDL_Surface *screen);

void free_image(image *IMAGE);

#endif