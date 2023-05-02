#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "menu.h"

void init_image(image *IMAGE, char *url, int x, int y)
{
  IMAGE->url = url;
  IMAGE->img = IMG_Load(IMAGE->url);
  IMAGE->pos.x = x;
  IMAGE->pos.y = y;
  IMAGE->pos.w = IMAGE->img->w;
  IMAGE->pos.h = IMAGE->img->h;
};

void display_background(image *IMAGE, SDL_Surface *screen)
{
  SDL_BlitSurface(IMAGE->img, &IMAGE->pos, screen, &IMAGE->pos);
};
void display_image(image *IMAGE, SDL_Surface *screen)
{
  SDL_BlitSurface(IMAGE->img, NULL, screen, &IMAGE->pos);
};

void anim_boat(image *IMAGE, SDL_Surface *screen)
{
  if (IMAGE->pos.x < 500)
  {
    IMAGE->pos.x += 1;
  }
  display_image(IMAGE, screen);
};