#ifndef SAUV_H
#define SAUV_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "../player/player.h"

void sauvegarder(player p, char *nomfichier);
void charger(player *p, char *nomfichier);

#endif