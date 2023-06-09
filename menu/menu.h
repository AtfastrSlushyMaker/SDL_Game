#ifndef MENU_H
#define MENU_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "../game.h"
#include "../player/player.h"

void anim_boat(image *IMAGE, SDL_Surface *screen);
void anim_balloon(image *IMAGE, SDL_Surface *screen);
void hover_image(image *IMAGE, SDL_Surface *screen, image var, int x, int y);
void click_image(image *IMAGE, SDL_Surface *screen, image var, int x, int y, SDL_Event event, int level, int *current_level, int *game,int *multiplayer,player *p);
void anim_title(image *IMAGE, SDL_Surface *screen);

#endif