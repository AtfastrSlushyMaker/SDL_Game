#ifndef SAUV_H_INCLUDED
#define SAUV_H_INCLUDED
#include "../player/player.h"
#include"background.h"

void sauvegarder (player p, char * nomfichier);
int charger (player *p , char * nomfichier);

#endif
