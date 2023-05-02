#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "menu/menu.h"

int main()
{

  SDL_Surface *screen;
  // backgrounds
  image bg_menu;

  // IMAGES MENU
  image boat;

  SDL_Event event;

  int game = 1;

  int level = 0;
  int x, y;

  if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_TIMER) == -1)
  {
    printf("Could not initialise SDL : %s .\n", SDL_GetError());
    return -1;
  }
  SDL_WM_SetCaption("Erupted Island: A Fight for Justice ", "Erupted Island: A Fight for Justice");
  screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  if (screen == NULL)
  {
    printf("%s\n", SDL_GetError());
  }

  // INITIALISATION BACKGROUND
  init_image(&bg_menu, "images/menu/background_without_boat.png", 0, 0);
  init_image(&boat, "images/menu/boat.png", 0, 570);

  while (game)
  {
    SDL_GetMouseState(&x, &y);
    printf("x = %d, y = %d\n", x, y);
    while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
      case SDL_QUIT:
        game = 0;
        break;
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
        case SDLK_ESCAPE:
          game = 0;
          break;
        }
      }
    }

    switch (level)
    {
    case 0:
      display_background(&bg_menu, screen);
      anim_boat(&boat, screen);
      break;
    }
    SDL_Flip(screen);
  }

  return 0;
}
