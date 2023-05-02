#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "menu.h"
#include "../game.h"

void anim_boat(image *IMAGE, SDL_Surface *screen)
{
  if (IMAGE->pos.x <= 500)
    IMAGE->pos.x += 1;
  display_image(IMAGE, screen);
};

void anim_balloon(image *IMAGE, SDL_Surface *screen)
{
  static int direction = 1;

  IMAGE->pos.y += direction;

  if (IMAGE->pos.y >= 400)
    direction = -1;

  else if (IMAGE->pos.y <= 200)
    direction = 1;

  display_image(IMAGE, screen);
}

void hover_image(image *IMAGE, SDL_Surface *screen, image var, int x, int y)
{
  if (IMAGE->pos.x <= x && IMAGE->pos.x + IMAGE->pos.w >= x && IMAGE->pos.y <= y && IMAGE->pos.y + IMAGE->pos.h >= y)
  {
    display_image(&var, screen);
  }
}

void click_image(image *IMAGE, SDL_Surface *screen, image var, int x, int y, SDL_Event event, int level, int *current_level, int *game)
{
  if (event.button.button == SDL_BUTTON_LEFT && (IMAGE->pos.x <= x && IMAGE->pos.x + IMAGE->pos.w >= x && IMAGE->pos.y <= y && IMAGE->pos.y + IMAGE->pos.h >= y))
  {
    display_image(&var, screen);
    if (level == 0)
      *game = 0;
    else
      *current_level = level;
  }
}