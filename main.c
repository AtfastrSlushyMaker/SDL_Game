#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "menu/menu.h"
#include "game.h"
#include "settings/settings.h"
#include "enemy/enemy.h"
#include "player/player.h"
#include "background/background.h"

int main()
{
  // SCREEN
  SDL_Surface *screen;

  // backgrounds
  image bg_menu, bg_settings;
  background bg_lvl1, bg_lvl2, bg_lvl3;

  // MENU
  image boat, balloon;
  image play, multiplayer_image, settings, quit, title, load_game;
  image play_var, multiplayer_image_var, settings_var, quit_var, load_game_var;

  int tab_active = 0;
  int tab_index = 0;

  // SETTINGS

  image settings_menu;
  image fire_amber[20];
  image muted;
  image not_muted;
  int volume_steps = 4;
  image volume_slider[5];
  image back_arrow;

  // PLAYER
  player player1;
  player player2;
  int multiplayer = 0;
  Uint32 dt, t_prev, stop_time;

  // MUSIC
  Mix_Music *menu_music = NULL;
  int menu_music_on = 0;
  Mix_Music *settings_music = NULL;
  int settings_music_on = 0;
  Mix_Music *level1_music = NULL;
  int level1_music_on = 0;
  Mix_Music *level2_music = NULL;
  int level2_music_on = 0;
  Mix_Music *level3_music = NULL;
  int level3_music_on = 0;

  Mix_Music *music;
  Mix_Chunk *mus;

  // EVENTS
  SDL_Event event;

  int game = 1;

  int level = 0;
  int volume = 120;
  int mouseX, mouseY;

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
  TTF_Init();
  // INITALISATION PLAYERS
  initPlayer1(&player1);
  initPlayer2(&player2);

  // INITIALISATION MENU
  init_image(&bg_menu, "images/menu/background_without_boat.png", 0, 0);
  init_image(&boat, "images/menu/boat.png", 0, 570);
  init_image(&balloon, "images/menu/balloon.png", 900, 200);
  init_image(&settings, "images/menu/settings_cog.png", 900, 640);
  init_image(&play, "images/menu/buttons/1player.png", 100, 200);
  init_image(&title, "images/menu/buttons/title.png", 125, 50);
  init_image(&multiplayer_image, "images/menu/buttons/2players.png", 100, 300);
  init_image(&load_game, "images/menu/buttons/load_game.png", 100, 400);
  init_image(&quit, "images/menu/buttons/exit.png", 100, 500);
  init_image(&play_var, "images/menu/buttons/1player_var.png", 100, 200);
  init_image(&multiplayer_image_var, "images/menu/buttons/2players_var.png", 100, 300);
  init_image(&load_game_var, "images/menu/buttons/load_game_var.png", 100, 400);
  init_image(&quit_var, "images/menu/buttons/exit_var.png", 100, 500);

  // INITIALISATION SETTINGS
  init_image(&bg_settings, "images/settings/settings_background.png", 0, 0);
  init_image(&settings_menu, "images/settings/Settings_menu.png", 200, 50);
  init_fire_amber(fire_amber);
  init_image(&muted, "images/settings/muted.png", 400, 200);
  init_image(&not_muted, "images/settings/speaker.png", 400, 200);
  init_image(&volume_slider[0], "images/settings/volume_slider/slider1.png", 280, 350);
  init_image(&volume_slider[1], "images/settings/volume_slider/slider2.png", 280, 350);
  init_image(&volume_slider[2], "images/settings/volume_slider/slider3.png", 280, 350);
  init_image(&volume_slider[3], "images/settings/volume_slider/slider4.png", 280, 350);
  init_image(&volume_slider[4], "images/settings/volume_slider/slider5.png", 280, 350);
  init_image(&back_arrow, "images/settings/back_arrow.png", 50, SCREEN_H / 2 - 50);

  // INTIALISATION LEVELS
  initBackground(&bg_lvl1, "images/background/Background_LVL_1 .png", "images/background/Background_LVL_1 .png");
  SDL_EnableKeyRepeat(5, 5);
  while (game)
  {
    SDL_GetMouseState(&mouseX, &mouseY);
     //printf("x = %d, y = %d\n", mouseX, mouseY);
    switch (level)
    {
    case -1: // SETTINGS
      if (!settings_music_on)
      {
        play_music(settings_music, "music/settings/(8-bit NES-style) Floater Land (Buoy Base Galaxy) Super Mario Galaxy.mp3", volume);
        set_music_on(&settings_music_on, &menu_music_on, &level1_music_on, &level2_music_on, &level3_music_on);
      }

      display_background(&bg_settings, screen);
      anim_fire_amber(fire_amber, screen);
      display_image(&settings_menu, screen);
      display_image(&back_arrow, screen);
      volume_image(volume, screen, muted, not_muted);
      display_volume_slider(volume_slider, screen, volume_steps);

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
            Control_Volume(&volume, 1, &volume_steps);
            break;
          case SDLK_KP_MINUS:
            Control_Volume(&volume, -1, &volume_steps);
            break;
          }
          break;
        case SDL_MOUSEBUTTONDOWN:
          click_image(&back_arrow, screen, back_arrow, mouseX, mouseY, event, 0, &level, &game, &multiplayer);
        }
      }

      break;
    case 0: // MENU

      if (!menu_music_on)
      {
        play_music(menu_music, "music/menu/Zelda Link to the Past - Hyrule Field (Gameboy 8-bit).mp3", volume);
        set_music_on(&menu_music_on, &settings_music_on, &level1_music_on, &level2_music_on, &level3_music_on);
      }
      display_background(&bg_menu, screen);
      anim_boat(&boat, screen);
      anim_balloon(&balloon, screen);
      display_image(&settings, screen);
      display_image(&play, screen);
      display_image(&multiplayer_image, screen);
      display_image(&load_game, screen);
      display_image(&quit, screen);
      anim_title(&title, screen);

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
          case SDLK_TAB:
            tab_active = !tab_active;
            break;
          }
          break;
        case SDL_MOUSEBUTTONDOWN:
          click_image(&play, screen, play_var, event.button.x, event.button.y, event, 1, &level, &game, &multiplayer);
          click_image(&multiplayer_image, screen, multiplayer_image_var, event.button.x, event.button.y, event, 69, &level, &game, &multiplayer);
          click_image(&quit, screen, quit_var, event.button.x, event.button.y, event, -10, &level, &game, &multiplayer);
          click_image(&settings, screen, settings, event.button.x, event.button.y, event, -1, &level, &game, &multiplayer);
          click_image(&load_game, screen, load_game_var, event.button.x, event.button.y, event, -2, &level, &game, &multiplayer);
          break;
        default:
          break;
        }
      }
      // HOVER BUTTONS
      hover_image(&play, screen, play_var, mouseX, mouseY);
      hover_image(&multiplayer_image, screen, multiplayer_image_var, mouseX, mouseY);
      hover_image(&load_game, screen, load_game_var, mouseX, mouseY);
      hover_image(&quit, screen, quit_var, mouseX, mouseY);
      break;
    case 1: // LEVEL 1
      t_prev = SDL_GetTicks();
      displayLevel(bg_lvl1, screen);

      displayPlayer(screen, player1);
      displayScore(screen, &player1);
      // displayHealth(screen, &player1, IMAGE_BACKGROUND_LEVEL_1);
      animatePlayer(&player1, stop_time);
      if (multiplayer)
      {
        printf("jawna boobs");
        displayPlayer(screen, player2);
      }
        handleMovement(screen, &player1, &player2, dt, stop_time, 1,game,level);
        scrolling(&bg_lvl1,&player1,0);
     
      dt = SDL_GetTicks() - t_prev;

      break;
    case 2: // LEVEL 2

      break;
    case 3: // LEVEL 3

      break;
    default:
      printf("Error level = %d Does Not Exist\n", level);
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
  free_image(&multiplayer_image);
  free_image(&quit);
  free_image(&title);
  free_image(&play_var);
  free_image(&multiplayer_image_var);
  free_image(&quit_var);
  free_image(&load_game);
  free_image(&load_game_var);

  // SETTINGS
  free_image(&bg_settings);
  free_image(&settings_menu);
  free_image(&muted);
  free_image(&not_muted);
  free_image(&back_arrow);
  free_image(&volume_slider[0]);
  free_image(&volume_slider[1]);
  free_image(&volume_slider[2]);
  free_image(&volume_slider[3]);
  free_image(&volume_slider[4]);
  free_array_image(fire_amber, 20);

  // FREE MUSIC
  Mix_FreeMusic(menu_music);
  Mix_FreeMusic(settings_music);
  Mix_FreeMusic(level1_music);
  Mix_FreeMusic(level2_music);
  Mix_FreeMusic(level3_music);

  SDL_Quit();
  return 0;
}
