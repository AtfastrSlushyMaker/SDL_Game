#ifndef SETTINGS_H
#define SETTINGS_H

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "../game.h"
#include "../menu/menu.h"

void Control_Volume(int *volume, int *volume_offset, int key, int *volume_steps);

#endif