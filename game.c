#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

#include "game.h"
#include "menu/menu.h"

void init_image(image *IMAGE, char *url, int x, int y)
{
  IMAGE->url = url;
  IMAGE->img = IMG_Load(IMAGE->url);
  IMAGE->pos.x = x;
  IMAGE->pos.y = y;
  IMAGE->pos.w = IMAGE->img->w;
  IMAGE->pos.h = IMAGE->img->h;
};

void display_background(image *IMAGE, SDL_Surface *screen)
{
  SDL_BlitSurface(IMAGE->img, &IMAGE->pos, screen, &IMAGE->pos);
};
void display_image(image *IMAGE, SDL_Surface *screen)
{
  SDL_BlitSurface(IMAGE->img, NULL, screen, &IMAGE->pos);
};

void play_music(Mix_Music *music, char *url, int volume)
{
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
  {
    printf("%s\n", SDL_GetError());
  }
  music = Mix_LoadMUS(url);
  Mix_HaltMusic();
  Mix_PlayMusic(music, -1);
  Mix_VolumeMusic(volume);
};

void free_image(image *IMAGE)
{
  SDL_FreeSurface(IMAGE->img);
};

void background_music(Mix_Music *music)
{
  Mix_PlayMusic(music, -1);
};

void set_music_on(int *music_on, int *music_1_off, int *music_2_off, int *music_3_off, int *music_4_off)
{
  *music_on = 1;
  *music_1_off = 0;
  *music_2_off = 0;
  *music_3_off = 0;
  *music_4_off = 0;
};

void free_array_image(image *IMAGE, int size)
{
  int i;
  for (i = 0; i < size; i++)
  {
    if (IMAGE[i].img != NULL)
      free_image(&IMAGE[i]);
  }
};