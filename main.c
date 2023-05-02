#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "menu/menu.h"
#include "game.h"
#include "settings/settings.h"

int main()
{

  SDL_Surface *screen;
  // backgrounds
  image bg_menu, bg_settings;

  // MENU
  image boat, balloon;
  image play, multiplayer, settings, quit;
  image play_var, multiplayer_var, settings_var, quit_var;

  // SETTINGS
  int volume_offset = 0;
  image settings_menu;
  int volume_steps = 5;

  Mix_Music *music;
  Mix_Chunk *mus;

  SDL_Event event;

  int game = 1;

  int level = 0;
  int volume = 120;
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

  // INITIALISATION MENU
  init_image(&bg_menu, "images/menu/background_without_boat.png", 0, 0);
  init_image(&boat, "images/menu/boat.png", 0, 570);
  init_image(&balloon, "images/menu/balloon.png", 900, 200);
  init_image(&settings, "images/menu/settings_cog.png", 900, 640);
  init_image(&play, "images/menu/buttons/1player.png", 100, 200);
  init_image(&multiplayer, "images/menu/buttons/2players.png", 100, 300);
  init_image(&quit, "images/menu/buttons/exit.png", 100, 400);
  init_image(&play_var, "images/menu/buttons/1player_var.png", 100, 200);
  init_image(&multiplayer_var, "images/menu/buttons/2players_var.png", 100, 300);
  init_image(&quit_var, "images/menu/buttons/exit_var.png", 100, 400);

  init_music(music, "music/menu/Zelda Link to the Past - Hyrule Field (Gameboy 8-bit).mp3", volume);

  // INITIALISATION SETTINGS
  init_image(&bg_settings, "images/settings/settings_background.png", 0, 0);
  init_image(&settings_menu, "images/settings/Settings_menu2.png", 200, 50);

  while (game)
  {
    SDL_GetMouseState(&x, &y);
    // printf("x = %d, y = %d\n", x, y);
    switch (level)
    {
    case -1:
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
            level = 0;
            break;
          case SDLK_KP_PLUS:
            Control_Volume(&volume, &volume_offset, 1, &volume_steps);
            break;
          case SDLK_KP_MINUS:
            Control_Volume(&volume, &volume_offset, -1, &volume_steps);
            break;
          }
        }
      }

      display_background(&bg_settings, screen);
      display_image(&settings_menu, screen);

      break;
    case 0:
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

        case SDL_MOUSEMOTION:
          hover_image(&play, screen, play_var, event.motion.x, event.motion.x);
          hover_image(&multiplayer, screen, multiplayer_var, event.motion.x, event.motion.x);
          hover_image(&quit, screen, quit_var, event.motion.x, event.motion.x);
          hover_image(&settings, screen, settings, event.motion.x, event.motion.x);
          break;
        case SDL_MOUSEBUTTONDOWN:
          click_image(&play, screen, play_var, event.button.x, event.button.y, event, 1, &level, &game);
          click_image(&multiplayer, screen, multiplayer_var, event.button.x, event.button.y, event, 1, &level, &game);
          click_image(&quit, screen, quit_var, event.button.x, event.button.y, event, 0, &level, &game);
          click_image(&settings, screen, settings, event.button.x, event.button.y, event, -1, &level, &game);
          break;
        }
      }

      display_background(&bg_menu, screen);
      anim_boat(&boat, screen);
      anim_balloon(&balloon, screen);
      display_image(&settings, screen);
      display_image(&play, screen);
      display_image(&multiplayer, screen);
      display_image(&quit, screen);

      break;
    default:
      printf("level = %d\n", level);
      game = 0;
      break;
    }
    SDL_Flip(screen);
  }

  // FREE IMAGES

  // MENU
  free_image(&bg_menu);
  free_image(&boat);
  free_image(&balloon);
  free_image(&settings);
  free_image(&play);
  free_image(&multiplayer);
  free_image(&quit);

  // SETTINGS
  free_image(&bg_settings);
  free_image(&settings_menu);

  SDL_Quit();
  return 0;
}
