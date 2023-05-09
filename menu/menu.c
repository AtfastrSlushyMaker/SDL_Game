#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "menu.h"
#include "../game.h"
#include "../player/player.h"
#include "../enigmetxt/sauv.h"

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

  if (IMAGE->pos.y >= 300)
    direction = -1;

  else if (IMAGE->pos.y <= 200)
    direction = 1;
  IMAGE->pos.x = (IMAGE->pos.x + 1) % (SCREEN_W * 1);
  display_image(IMAGE, screen);
}

void hover_image(image *IMAGE, SDL_Surface *screen, image var, int x, int y)
{

  if (x >= IMAGE->pos.x && x <= IMAGE->pos.x + IMAGE->pos.w && y >= IMAGE->pos.y && y <= IMAGE->pos.y + IMAGE->pos.h)
  {
    display_image(&var, screen);
  }
}

void click_image(image *IMAGE, SDL_Surface *screen, image var, int x, int y, SDL_Event event, int level, int *current_level, int *game, int *multiplayer,player *p)
{
  if (event.button.button == SDL_BUTTON_LEFT && (IMAGE->pos.x <= x && IMAGE->pos.x + IMAGE->pos.w >= x && IMAGE->pos.y <= y && IMAGE->pos.y + IMAGE->pos.h >= y))
  {
    display_image(&var, screen);
    if (level == -10)
      *game = 0;
    else if (level == 69)
      *multiplayer = 1;
    else if (level==-2)
      charger(p,"load.txt");
    else
      *current_level = level;
  }
}

void anim_title(image *IMAGE, SDL_Surface *screen)
{
  static int direction_title = 1;

  IMAGE->pos.y += direction_title;

  if (IMAGE->pos.y >= 50)
    direction_title = -1;

  else if (IMAGE->pos.y <= 25)
    direction_title = 1;

  display_image(IMAGE, screen);
}