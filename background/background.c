#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "background.h"
#include "../player/player.h"
#include "../game.h"
void displayLevel(background backg, SDL_Surface *screen)
{
  SDL_BlitSurface(backg.bg, &backg.camera, screen, &backg.bgPos);
}
void initBackground(background *backg, char *url, char *maskURL)
{
  backg->bg = IMG_Load(url);
  backg->mask = IMG_Load(maskURL);
  backg->bgPos.x = 0;
  backg->bgPos.y = 0;
  backg->camera.x = 0;
  backg->camera.y = 0;
  backg->camera.w = SCREEN_W;
  backg->camera.h = SCREEN_H;
  backg->direction = 0;
}
void scrolling(background *bg, player *p, int col)
{
  int speed = p->velocity;
  ;
  if (p->direction == 0)
  {
    // printf("\n%d,%d",B->camera.x  ,5009 - B->camera.w);
    if ((bg->camera.x < 5000 - bg->camera.w) && (p->playerPos.x >= bg->bgPos.x))
    {
      bg->camera.x += speed;
    }
  }
  if (p->direction == 1)
  {
    if (bg->camera.x - speed > 0)
    {
      bg->camera.x -= speed;
    }
  }
  /*
  if (direction == 2)
  {
    if (B->camera.y > 50)
    {
      B->camera.y -= 10;
    }
  }
  if (direction == 3)
  {
    if (B->camera.y < 194)
    {
      B->camera.y += 10;
    }

  }
  */
}
