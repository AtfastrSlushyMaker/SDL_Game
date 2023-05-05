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

void Control_Volume(int *volume, int key, int *volume_steps);
void init_fire_amber(image fire[]);
void anim_fire_amber(image fire[], SDL_Surface *screen);
void volume_image(int volume, SDL_Surface *screen, image muted, image not_muted);
void display_volume_slider(image volume_slider[], SDL_Surface *screen, int volume_steps);
#endif