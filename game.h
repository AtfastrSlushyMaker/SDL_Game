#ifndef MAIN_H
#define MAIN_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_H 720
#define SCREEN_W 1000

typedef struct
{
  char *url;
  SDL_Surface *img;
  SDL_Rect pos;
} image;

typedef struct
{
  SDL_Surface *txt;
  SDL_Rect pos_txt;
  SDL_Colour color_txt;
  TTF_Font *police;
} texte;

void init_image(image *IMAGE, char *url, int x, int y);
void display_background(image *IMAGE, SDL_Surface *screen);
void display_image(image *IMAGE, SDL_Surface *screen);
void play_music(Mix_Music *music, char *url, int volume);
void free_image(image *IMAGE);
void set_music_on(int *music_on, int *music_1_off, int *music_2_off, int *music_3_off, int *music_4_off);
void free_array_image(image *IMAGE, int size);
#endif