#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "../game.h"
#include "../menu/menu.h"
#include "settings.h"
#include <time.h>

void Control_Volume(int *volume, int key, int *volume_steps)
{
  int max_volume = 120;
  int step_size = max_volume / 4;

  if ((*volume) <= max_volume && (*volume) >= 0 && (*volume_steps) < 5 && (*volume_steps) >= 0)
  {
    if (key == 1)
    {
      if ((*volume_steps) < 4)
      {
        (*volume) += step_size;
        (*volume_steps)++;
      }
      else if ((*volume_steps) == 4 && (*volume) < max_volume)
      {
        (*volume) = max_volume;
        (*volume_steps)++;
      }
    }

    if (key == -1)
    {
      if ((*volume_steps) > 0)
      {
        (*volume) -= step_size;
        (*volume_steps)--;
      }
      else if ((*volume_steps) == 0 && (*volume) > 0)
      {
        (*volume) = 0;
      }
    }
  }

  Mix_VolumeMusic((*volume));
}

void init_fire_amber(image fire[])
{
  int i;
  int random_x, random_y;

  for (i = 0; i < 15; i++)
  {
    // srand(time(NULL));
    random_x = (rand() % SCREEN_W);
    random_y = (rand() % SCREEN_H);
    init_image(&fire[i], "images/settings/fire_amber.png", random_x, random_y);
  }
}

void anim_fire_amber(image fire[], SDL_Surface *screen)
{
  int i;
  int r;
  srand(time(NULL));
  for (i = 0; i < 15; i++)
  {
    r = (rand() % 5) + 1;
    fire[i].pos.x = (fire[i].pos.x + r) % SCREEN_W;
    r = (rand() % 5) + 1;
    fire[i].pos.y = (fire[i].pos.y + r) % SCREEN_H;
    display_image(&fire[i], screen);
  }
}

void volume_image(int volume, SDL_Surface *screen, image muted, image not_muted)
{
  if (volume == 0)
  {
    display_image(&muted, screen);
  }
  else
  {
    display_image(&not_muted, screen);
  }
}

void display_volume_slider(image volume_slider[], SDL_Surface *screen, int volume_steps)
{
  switch (volume_steps)
  {
  case 0:
    display_image(&volume_slider[0], screen);
    break;
  case 1:
    display_image(&volume_slider[1], screen);
    break;
  case 2:
    display_image(&volume_slider[2], screen);
    break;
  case 3:
    display_image(&volume_slider[3], screen);
    break;
  case 4:
    display_image(&volume_slider[4], screen);
    break;
  default:
    break;
  }
}