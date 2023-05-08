#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include <math.h>
#include "minimap.h"
#include "../player/player.h"
#include "../game.h"
#include "../enemy/enemy.h"

























void initminimap(Minimap *m)
{

    m->image_miniature = IMG_Load("images/minimap/1mini.png");

    m->image_enigme = IMG_Load("images/minimap/enigme.png");
    if (m->image_enigme == NULL)
    {
        printf("Erreur de chargement de l'image de l'enigme : %s", IMG_GetError());
        return;
    }

    m->image_enemie = IMG_Load("images/minimap/enemie.png");
    if (m->image_enemie == NULL)
    {
        printf("Erreur de chargement de l'image de l'ennemi : %s", IMG_GetError());
        return;
    }

    m->image_bonhomme = IMG_Load("images/minimap/player_small.png");

    m->image_enemie2= IMG_Load("images/minimap/enemie.png");
     

    m->position_miniature.x = 0;
    m->position_miniature.y = 0;
    m->position_miniature.w = 100;
    m->position_miniature.h = 100;
    m->position_bonhomme.x = m->position_miniature.w / 2 - m->image_bonhomme->w / 2;
    m->position_bonhomme.y = m->position_miniature.h / 2 - m->image_bonhomme->h / 2;
    m->position_bonhomme.w = m->image_bonhomme->w;
    m->position_bonhomme.h = m->image_bonhomme->h;

    m->position_enigme.x = m->position_miniature.w / 2 - m->image_bonhomme->w / 2 +50;
    m->position_enigme.y = m->position_miniature.h / 2 - m->image_bonhomme->h / 2 + 15;
    m->position_enigme.w = m->image_enigme->w;
    m->position_enigme.h = m->image_enigme->h;

    m->position_enemie.x = m->position_miniature.w / 2 - m->image_bonhomme->w / 2 + 200;
    m->position_enemie.y = m->position_miniature.h / 2 - m->image_bonhomme->h / 2 + 15;
    m->position_enemie.w = m->image_enemie->w;
    m->position_enemie.h = m->image_enemie->h;


    m->position_enemie2.x = m->position_miniature.w / 2 - m->image_bonhomme->w / 2 + 100;
    m->position_enemie2.y = m->position_miniature.h / 2 - m->image_bonhomme->h / 2 +15;
    m->position_enemie2.w = m->image_enemie->w;
    m->position_enemie2.h = m->image_enemie->h;




}

void afficheminimap(Minimap m, SDL_Surface *s)
{

    SDL_BlitSurface(m.image_miniature, NULL, s, &m.position_miniature);

    SDL_BlitSurface(m.image_bonhomme, NULL, s, &m.position_bonhomme);

    SDL_BlitSurface(m.image_enemie, NULL, s, &m.position_enemie);

 SDL_BlitSurface(m.image_enemie2, NULL, s, &m.position_enemie2);

    SDL_BlitSurface(m.image_enigme, NULL, s, &m.position_enigme);
}

void Liberer(Minimap *m)
{
    if (m)
    {
        if (m->image_miniature)
        {
            SDL_FreeSurface(m->image_miniature);
            m->image_miniature = NULL;
        }
        if (m->image_bonhomme)
        {
            SDL_FreeSurface(m->image_bonhomme);
            m->image_bonhomme = NULL;
        }
        free(m);
    }
}

// BEL SCROLLING



void MAJMinimap(SDL_Rect posJoueur, Minimap *m, SDL_Rect camera, int redimensionnement)
{

    SDL_Rect posJoueurABS;
    posJoueurABS.x = posJoueur.x + camera.x;
    posJoueurABS.y = posJoueur.y + camera.y;

    SDL_Rect posJoueurMini;
    posJoueurMini.x = posJoueurABS.x / redimensionnement;
    posJoueurMini.y = posJoueurABS.y / redimensionnement;

    m->position_bonhomme = posJoueurMini;
}

void MAJMinimap_enemie(SDL_Rect posJoueur, Minimap *m, SDL_Rect camera, int redimensionnement)
{

    SDL_Rect posJoueurABS;
    posJoueurABS.x = posJoueur.x + camera.x;
    posJoueurABS.y = posJoueur.y + camera.y;

    SDL_Rect posJoueurMini;
    posJoueurMini.x = posJoueurABS.x / redimensionnement;
    posJoueurMini.y = posJoueurABS.y / redimensionnement;

    m->position_enemie = posJoueurMini;
}
void MAJMinimap_enemie2(SDL_Rect posJoueur, Minimap *m, SDL_Rect camera, int redimensionnement)
{

    SDL_Rect posJoueurABS;
    posJoueurABS.x = posJoueur.x + camera.x;
    posJoueurABS.y = posJoueur.y + camera.y;

    SDL_Rect posJoueurMini;
    posJoueurMini.x = posJoueurABS.x / redimensionnement;
    posJoueurMini.y = posJoueurABS.y / redimensionnement;

    m->position_enemie2 = posJoueurMini;
}


void afficher_temps(SDL_Surface *screen, time_t temps_lancement)
{
    TTF_Font *police = TTF_OpenFont("fonts/Raleway-BoldItalic.ttf", 32);

    char temps[30];

    int secondes = (int)difftime(time(NULL), temps_lancement);
    int minutes = secondes / 60;
    secondes = secondes % 60;

    sprintf(temps, "Temps: %02d:%02d", minutes, secondes);

    SDL_Color couleur = {255, 255, 255};
    SDL_Rect position = {800, 0, 0, 0};

    SDL_Surface *texte = TTF_RenderText_Blended(police, temps, couleur);
    SDL_BlitSurface(texte, NULL, screen, &position);
    SDL_FreeSurface(texte);
}


SDL_Color GetPixel(SDL_Surface *pSurface, int x, int y)
{
    SDL_Color color;
    Uint32 col = 0;
    char *pPosition = (char *)pSurface->pixels;
    pPosition += y * pSurface->pitch;
    pPosition += x * pSurface->format->BytesPerPixel;
    memcpy(&col, pPosition, pSurface->format->BytesPerPixel);
    SDL_GetRGB(col, pSurface->format, &color.r, &color.g, &color.b);
    return color;
}

int collisionPP(player p, SDL_Surface *Masque)
{

    int collision, i;
    collision = 0;

    SDL_Rect pos[8];
    SDL_Color pixel;

    pos[0].x = p.playerPos.x;
    pos[0].y = p.playerPos.y;
    pos[1].x = (p.playerPos.x + p.playerPos.w) / 2;
    pos[1].y = p.playerPos.y;
    pos[2].x = p.playerPos.x + p.playerPos.w;
    pos[2].y = p.playerPos.y;
    pos[3].x = p.playerPos.x;
    pos[3].y = p.playerPos.y;
    pos[4].x = p.playerPos.x;
    pos[4].y = (p.playerPos.y + p.playerPos.h) / 2;
    pos[5].x = (p.playerPos.x + p.playerPos.w) / 2;
    pos[5].y = p.playerPos.y + p.playerPos.h;
    pos[6].x = p.playerPos.x + p.playerPos.w;
    pos[6].y = p.playerPos.y + p.playerPos.h;
    pos[7].x = p.playerPos.x + p.playerPos.w;
    pos[7].y = (p.playerPos.y + p.playerPos.h) / 2;

    for (i = 0; i < 8; i++)
    {
        pixel = GetPixel(Masque, pos[i].x, pos[i].y);
        if (pixel.r == 0 && pixel.g == 0 && pixel.b == 0)
        {
            collision = 1;
            break;
        }
    }

    return collision;
}

