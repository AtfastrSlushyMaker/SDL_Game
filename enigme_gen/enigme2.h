#ifndef ENIGME_H
#define ENIGME_H
/**

* @file enigme2.h
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <SDL/SDL_mixer.h>
#include "../game.h"
/**
* @struct enigme
* @brief struct for enigme
*/


typedef struct{
    char ques[100];
    char rep1[100];
    char rep2[100];
    char rep3[100];
    int nrep;
}enigme;
void initialiser_audiobref(Mix_Chunk *musicw);
enigme generer();
void afficherenigme(enigme e, SDL_Surface*ecran);
#endif // FONCTION_H_INCLUDED
