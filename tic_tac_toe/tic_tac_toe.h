#ifndef TIC_TA_TOE_H
#define TIC_TA_TOE_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include <SDL/SDL_ttf.h>
#include <math.h>

#define S_H 321
#define S_W 321

#define HAUTEUR_CASE 107
#define LARGEUR_CASE 107



typedef struct Tic {
    SDL_Surface* background_image;
    SDL_Surface* player_image;
    SDL_Surface* computer_image;
    
    int tabsuivi[9];
    int first_player;
    int tour;
    TTF_Font* font;
    SDL_Color font_color;
    char text[50];
    SDL_Rect text_position;
} tic;


void initialiserTic(tic *t);
void afficherTic(tic t, SDL_Surface* ecran);
int atilganer(int tabsuivi[]);
void Resultat(int tabsuivi[], SDL_Surface* ecran);
void libererMemoire(tic *t);
int minmax(int tabsuivi[9],int joueur);
void calcul_coup(int tabsuivi[9]);














#endif
