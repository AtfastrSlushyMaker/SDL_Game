#ifndef MINIMAP_H
#define MINIMAP_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include <SDL/SDL_ttf.h>
#include <math.h>
#include "../player/player.h"
#include "../game.h"
#include "../enemy/enemy.h"










typedef struct Minimap
{
    SDL_Surface *image_miniature;/*!<surface qui represente l'image miniature de la minimap*/
    SDL_Rect position_miniature;/*!<rectangle qui defini sa position*/
    SDL_Surface *image_bonhomme;/*!<surface qui represente l'image du joueur dans la minimap*/
    SDL_Rect position_bonhomme;/*!<rectangle qui definie sa position*/
    SDL_Surface *image_enemie;/*!<surface qui represente l'image de l'enemie dans la minimap*/
    SDL_Rect position_enemie;/*!<rectangle qui definie sa position*/
    SDL_Surface *image_enigme;/*!<surface sui represent l'image de l'enigme dans la minimap */
    SDL_Rect position_enigme;/*!<rectangle qui defini sa position*/
    SDL_Surface *image_enemie2;/*!<surface qui represente l'image de l'enemie dans la minimap*/
    SDL_Rect position_enemie2;/*!<rectangle qui definie sa position*/
} Minimap;















void initminimap(Minimap *m);
void afficheminimap(Minimap m, SDL_Surface *s);
void mettreAJourMinimap(Minimap *m, int joueur_x, int joueur_y);
void Liberer(Minimap *m);
void MAJMinimap(SDL_Rect posJoueur, Minimap *m, SDL_Rect camera, int redimensionnement);
void mettreAJourMinimap_enemie(Minimap *m, int joueur_x, int joueur_y);
void MAJMinimap_enemie(SDL_Rect posJoueur, Minimap *m, SDL_Rect camera, int redimensionnement);
void MAJMinimap_enemie2(SDL_Rect posJoueur, Minimap *m, SDL_Rect camera, int redimensionnement);




void afficher_temps(SDL_Surface *screen, time_t temps_lancement);





int collisionPP(player p, SDL_Surface *Masque);
SDL_Color GetPixel(SDL_Surface *pSurface, int x, int y);







#endif
