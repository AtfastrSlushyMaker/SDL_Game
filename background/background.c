#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "../player/player.h"
#include "../game.h"
#include "background.h"

void initBackground(background *backg, char *url, char *maskURL)
{
    backg->bg = IMG_Load(url);
    backg->mask = IMG_Load(maskURL);
    backg->bgPos.x = 0;
    backg->bgPos.y = 0;
    backg->camera.x = 0;
    backg->camera.y = 0;
    backg->camera.w = SCREEN_W;
    backg->camera.h = SCREEN_H;
    backg->direction = 0;
}
void displayLevel(background backg, SDL_Surface *screen)
{
    SDL_BlitSurface(backg.bg, &backg.camera, screen, &backg.bgPos);
}
void scrolling(background *backg, player p, int col, int col2, int col3, int col4)
{
    if (backg->direction == 2)
    {
        if (backg->camera.x > 0 && p.playerPos.x <= 5000 && col == 0 && col2 == 0 && col3 == 0 && col4 == 0 && p.up == 3)
            backg->camera.x = backg->camera.x - 60;
        if (backg->camera.x > p.playerPos.x - 640)
        {
            if (backg->camera.x > 0 && p.playerPos.x <= 4800 && col == 0 && col2 == 0 && col3 == 0 && col4 == 0)
                backg->camera.x = backg->camera.x - 10;
            else if (backg->camera.x > 0 && p.playerPos.x > 4800 && col == 0 && col2 == 0 && col3 == 0 && col4 == 0)
                backg->camera.x = backg->camera.x - 1;
        }
    }
    else if (backg->direction == 1)
    {
        if (backg->camera.x < 3820 && p.playerPos.x >= 300 && col == 0 && col2 == 0 && col3 == 0 && col4 == 0 && p.up == 2)
            backg->camera.x = backg->camera.x + 60;
        if (backg->camera.x + 640 < p.playerPos.x)
        {
            if (backg->camera.x < 3820 && p.playerPos.x >= 300 && col == 0 && col2 == 0 && col3 == 0 && col4 == 0)
                backg->camera.x = backg->camera.x + 10;
            else if (backg->camera.x < 3820 && p.playerPos.x < 300 && col == 0 && col2 == 0 && col3 == 0 && col4 == 0)
                backg->camera.x = backg->camera.x + 1;
        }
    }
}
