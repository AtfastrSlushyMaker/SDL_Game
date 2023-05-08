#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "../player/player.h"

typedef struct
{
	SDL_Surface *bg, *mask;
	SDL_Rect bgPos;
	SDL_Rect camera;
	int direction;
} background;

void initBackground(background *backg,char *url,char *maskURL);
void scrolling(background *bg, player *p, int col);
void displayLevel(background backg, SDL_Surface *screen);
#endif