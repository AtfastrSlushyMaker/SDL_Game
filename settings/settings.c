#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "../game.h"
#include "../menu/menu.h"
#include "settings.h"

void Control_Volume(int *volume, int volume_offset, int key)
{
  static int volume_steps = 5;

  if ((*volume) <= 120 && (*volume) >= 0)
  {
    if (key == 1)
    {
      if (volume_steps < 5)
      {
        (*volume) += 20;
        volume_steps++;
        (*volume_offset) += 50;
      }
    }

    if (key == -1)
    {
      if (volume_steps >= 0)
      {
        (*volume) -= 20;
        volume_steps--;
        (*volume_offset) -= 50;
      }
    }
  }
  Mix_VolumeMusic((*volume));
}