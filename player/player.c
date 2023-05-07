#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <math.h>
#include "../game.h"
#include "player.h"
void initPlayer1(player *p)
{
    // move right
    p->img.player[0][0] = IMG_Load("images/lot1/Character/right/right1.png");
    p->img.player[0][1] = IMG_Load("images/lot1/Character/right/right2.png");
    p->img.player[0][2] = IMG_Load("images/lot1/Character/right/right3.png");
    p->img.player[0][3] = IMG_Load("images/lot1/Character/right/right4.png");
    p->img.player[0][4] = IMG_Load("images/lot1/Character/right/right5.png");
    p->img.player[0][5] = IMG_Load("images/lot1/Character/right/right6.png");
    // move left
    p->img.player[1][0] = IMG_Load("images/lot1/Character/left/left1.png");
    p->img.player[1][1] = IMG_Load("images/lot1/Character/left/left2.png");
    p->img.player[1][2] = IMG_Load("images/lot1/Character/left/left3.png");
    p->img.player[1][3] = IMG_Load("images/lot1/Character/left/left4.png");
    p->img.player[1][4] = IMG_Load("images/lot1/Character/left/left5.png");
    p->img.player[1][5] = IMG_Load("images/lot1/Character/left/left6.png");
    // jump
    p->img.player[2][0] = IMG_Load("images/lot1/Character/jump/jump1R.png");
    p->img.player[2][1] = IMG_Load("images/lot1/Character/jump/jump2R.png");
    p->img.player[2][2] = IMG_Load("images/lot1/Character/jump/jump3R.png");
    p->img.player[2][3] = IMG_Load("images/lot1/Character/jump/jump1L.png");
    p->img.player[2][4] = IMG_Load("images/lot1/Character/jump/jump2L.png");
    p->img.player[2][5] = IMG_Load("images/lot1/Character/jump/jump3L.png");
    // crouch
    p->img.player[3][0] = IMG_Load("images/lot1/Character/crouchR.png");
    p->img.player[3][1] = IMG_Load("images/lot1/Character/crouchL.png");
    // idle right
    p->img.player[4][0] = IMG_Load("images/lot1/Character/Idle/right/IdleR.png");
    p->img.player[4][1] = IMG_Load("images/lot1/Character/Idle/right/IdleR1.png");
    p->img.player[4][2] = IMG_Load("images/lot1/Character/Idle/right/IdleR2.png");
    p->img.player[4][3] = IMG_Load("images/lot1/Character/Idle/right/IdleR3.png");
    p->img.player[4][4] = IMG_Load("images/lot1/Character/Idle/right/IdleR4.png");
    p->img.player[4][5] = IMG_Load("images/lot1/Character/Idle/right/IdleR5.png");
    p->img.player[4][6] = IMG_Load("images/lot1/Character/Idle/right/IdleR6.png");
    p->img.player[4][7] = IMG_Load("images/lot1/Character/Idle/right/IdleR7.png");
    p->img.player[4][8] = IMG_Load("images/lot1/Character/Idle/right/IdleR8.png");
    // idle left
    p->img.player[5][0] = IMG_Load("images/lot1/Character/Idle/left/IdleL.png");
    p->img.player[5][1] = IMG_Load("images/lot1/Character/Idle/left/IdleL1.png");
    p->img.player[5][2] = IMG_Load("images/lot1/Character/Idle/left/IdleL2.png");
    p->img.player[5][3] = IMG_Load("images/lot1/Character/Idle/left/IdleL3.png");
    p->img.player[5][4] = IMG_Load("images/lot1/Character/Idle/left/IdleL4.png");
    p->img.player[5][5] = IMG_Load("images/lot1/Character/Idle/left/IdleL5.png");
    p->img.player[5][6] = IMG_Load("images/lot1/Character/Idle/left/IdleL6.png");
    p->img.player[5][7] = IMG_Load("images/lot1/Character/Idle/left/IdleL7.png");
    p->img.player[5][8] = IMG_Load("images/lot1/Character/Idle/left/IdleL8.png");
    p->img.currentPlayerState = p->img.player[4][0];
    p->direction = 0;
    p->playerPos.x = 70;
    p->playerPos.y = 600;
    p->playerPos.w = 0;
    p->playerPos.h = 0;
    p->velocity = 3;
    p->acceleration = 0;
    p->up = 0;
    p->down = 0;
    p->isMoving = 0;
    p->IS_HIT = 0;
    p->multiplayer = 0;
    p->hasJumped = 0;
    p->health.playerHP = 10;
    p->score.playerScore = 1000;
    p->box_AABB.collision.x = p->playerPos.x;
    p->box_AABB.collision.y = p->playerPos.y;
}

void initPlayer2(player *p)
{

    // move right
    p->img.player[0][0] = IMG_Load("images/lot1/Character2/right/right1.png");
    p->img.player[0][1] = IMG_Load("images/lot1/Character2/right/right2.png");
    p->img.player[0][2] = IMG_Load("images/lot1/Character2/right/right3.png");
    p->img.player[0][3] = IMG_Load("images/lot1/Character2/right/right4.png");
    p->img.player[0][4] = IMG_Load("images/lot1/Character2/right/right5.png");
    p->img.player[0][5] = IMG_Load("images/lot1/Character2/right/right6.png");
    // move left
    p->img.player[1][0] = IMG_Load("images/lot1/Character2/left/left1.png");
    p->img.player[1][1] = IMG_Load("images/lot1/Character2/left/left2.png");
    p->img.player[1][2] = IMG_Load("images/lot1/Character2/left/left3.png");
    p->img.player[1][3] = IMG_Load("images/lot1/Character2/left/left4.png");
    p->img.player[1][4] = IMG_Load("images/lot1/Character2/left/left5.png");
    p->img.player[1][5] = IMG_Load("images/lot1/Character2/left/left6.png");
    // jump
    p->img.player[2][0] = IMG_Load("images/lot1/Character2/jump/jump1R.png");
    p->img.player[2][1] = IMG_Load("images/lot1/Character2/jump/jump2R.png");
    p->img.player[2][2] = IMG_Load("images/lot1/Character2/jump/jump3R.png");
    p->img.player[2][3] = IMG_Load("images/lot1/Character2/jump/jump1L.png");
    p->img.player[2][4] = IMG_Load("images/lot1/Character2/jump/jump2L.png");
    p->img.player[2][5] = IMG_Load("images/lot1/Character2/jump/jump3L.png");
    // crouch
    p->img.player[3][0] = IMG_Load("images/lot1/Character2/crouchR.png");
    p->img.player[3][1] = IMG_Load("images/lot1/Character2/crouchL.png");
    // idle right
    p->img.player[4][0] = IMG_Load("images/lot1/Character2/Idle/right/IdleR.png");
    p->img.player[4][1] = IMG_Load("images/lot1/Character2/Idle/right/IdleR1.png");
    p->img.player[4][2] = IMG_Load("images/lot1/Character2/Idle/right/IdleR2.png");
    p->img.player[4][3] = IMG_Load("images/lot1/Character2/Idle/right/IdleR3.png");
    p->img.player[4][4] = IMG_Load("images/lot1/Character2/Idle/right/IdleR4.png");
    p->img.player[4][5] = IMG_Load("images/lot1/Character2/Idle/right/IdleR5.png");
    p->img.player[4][6] = IMG_Load("images/lot1/Character2/Idle/right/IdleR6.png");
    p->img.player[4][7] = IMG_Load("images/lot1/Character2/Idle/right/IdleR7.png");
    p->img.player[4][8] = IMG_Load("images/lot1/Character2/Idle/right/IdleR8.png");
    // idle left
    p->img.player[5][0] = IMG_Load("images/lot1/Character2/Idle/left/IdleL.png");
    p->img.player[5][1] = IMG_Load("images/lot1/Character2/Idle/left/IdleL1.png");
    p->img.player[5][2] = IMG_Load("images/lot1/Character2/Idle/left/IdleL2.png");
    p->img.player[5][3] = IMG_Load("images/lot1/Character2/Idle/left/IdleL3.png");
    p->img.player[5][4] = IMG_Load("images/lot1/Character2/Idle/left/IdleL4.png");
    p->img.player[5][5] = IMG_Load("images/lot1/Character2/Idle/left/IdleL5.png");
    p->img.player[5][6] = IMG_Load("images/lot1/Character2/Idle/left/IdleL6.png");
    p->img.player[5][7] = IMG_Load("images/lot1/Character2/Idle/left/IdleL7.png");
    p->img.player[5][8] = IMG_Load("images/lot1/Character2/Idle/left/IdleL8.png");

    p->img.currentPlayerState = p->img.player[4][0];
    p->direction = 0;
    p->playerPos.x = 250;
    p->playerPos.y = 600;
    p->playerPos.w = 0;
    p->playerPos.h = 0;
    p->velocity = 3;
    p->acceleration = 0;
    p->up = 0;
    p->down = 0;
    p->isMoving = 0;
}

void displayPlayer(SDL_Surface *screen, player p)
{
    SDL_BlitSurface(p.img.currentPlayerState, NULL, screen, &p.playerPos);
}

void movePlayer(player *p, Uint32 dt)
{
    int dx;
    if (p->direction == 0)
    {
        if (p->playerPos.x + 2 < SCREEN_W - 111)
        {
            p->playerPos.x += 2;
            if (p->acceleration > 0)
            {
                dx = (0.5 * p->acceleration * (dt * dt)) + p->velocity * dt;
                p->velocity = dx / dt;
                p->playerPos.x += p->velocity;
            }

            p->img.currentPlayerState = p->img.player[0][(SDL_GetTicks() / 100) % 6];
        }
    }
    else if (p->direction == 1)
    {
        if (p->playerPos.x - 2 > 0)
        {
            p->playerPos.x -= 2;
            if (p->acceleration > 0)
            {
                dx = (0.5 * p->acceleration * (dt * dt)) + p->velocity * dt;
                p->velocity = dx / dt;
                p->playerPos.x -= p->velocity;
            }
            p->img.currentPlayerState = p->img.player[1][(SDL_GetTicks() / 100) % 6];
        }
    }
}

void jumpPlayer(player *p, SDL_Surface *screen, Uint32 dt)
{
    int i, jumpHeight = 200;
    double gravity = 1, dx, dy;
    if (p->up == 1)
    {
        switch (p->direction)
        {
        case 0:
            for (i = 0; i < 3; i++)
            {
                p->img.currentPlayerState = p->img.player[2][i];
                p->playerPos.y = 600 - jumpHeight + i * jumpHeight / 2;
                SDL_BlitSurface(p->img.currentPlayerState, NULL, screen, &(p->playerPos));
                SDL_Delay(150);
            }
            p->img.currentPlayerState = p->img.player[4][0];
            break;
        case 1:
            for (i = 3; i < 6; i++)
            {
                p->img.currentPlayerState = p->img.player[2][i];
                p->playerPos.y = 600 - jumpHeight + (i - 3) * jumpHeight / 2;
                SDL_BlitSurface(p->img.currentPlayerState, NULL, screen, &(p->playerPos));
                SDL_Delay(150);
            }
            p->img.currentPlayerState = p->img.player[5][0];
            break;
        }
        while (p->playerPos.y < 300)
        {
            p->playerPos.y += gravity;
            gravity += 0.5;
            SDL_BlitSurface(p->img.currentPlayerState, NULL, screen, &(p->playerPos));
            SDL_Delay(150);
        }

        p->playerPos.y = 600;
    }
    else if (p->up == 2)
    {
        dx = p->velocity * dt;
        dy = -(int)(sqrt(2 * jumpHeight * gravity * dt));

        if (p->direction == 0 && p->playerPos.x > SCREEN_W - 111)
        {
            p->playerPos.x += dx;
            p->img.currentPlayerState = p->img.player[2][(SDL_GetTicks() / 100) % 3];
        }
        else if (p->direction == 1)
        {
            p->playerPos.x -= dx;
            p->img.currentPlayerState = p->img.player[2][3 + ((SDL_GetTicks() / 100) % 3)];
        }
        p->playerPos.y += dy;

        while (p->playerPos.y < 300)
        {
            if (p->direction == 0)
            {
                p->playerPos.x += dx;
                p->img.currentPlayerState = p->img.player[2][(SDL_GetTicks() / 100) % 3];
            }
            else if (p->direction == 1)
            {
                p->playerPos.x -= dx;
                p->img.currentPlayerState = p->img.player[2][3 + ((SDL_GetTicks() / 100) % 3)];
            }
            p->playerPos.y += dy;
            dy += gravity * dt;
            SDL_BlitSurface(p->img.currentPlayerState, NULL, screen, &(p->playerPos));
            SDL_Delay(20);
        }
        p->playerPos.y = 600;
        if (p->direction == 0)
        {
            p->img.currentPlayerState = p->img.player[4][0];
        }
        else
        {
            p->img.currentPlayerState = p->img.player[5][0];
        }
    }
}

void crouchPlayer(player *p)
{
    if (!p->down)
    {
        if (p->direction == 0)
            p->img.currentPlayerState = p->img.player[3][0];
        else if (p->direction == 1)
            p->img.currentPlayerState = p->img.player[3][1];
        p->playerPos.y += 23;
    }
    p->down = 1;
}

void animatePlayer(player *p, Uint32 stop_time)
{
    static int anim_frame = 1;
    static Uint32 last_time = 0;
    Uint32 current_time = SDL_GetTicks();
    Uint32 elapsed_time = current_time - last_time;
    if (p->isMoving == 0 && elapsed_time >= 100 && current_time - stop_time >= 1500)
    {
        if (p->direction == 0)
        {
            p->img.currentPlayerState = p->img.player[4][anim_frame];
        }
        else if (p->direction == 1)
        {
            p->img.currentPlayerState = p->img.player[5][anim_frame];
        }
        last_time = current_time;
        anim_frame++;
        if (anim_frame > 8)
        {
            anim_frame = 1;
        }
    }
}

void stopPlayer(player *p, Uint32 *stop_time)
{
    if (p->direction == 0)
        p->img.currentPlayerState = p->img.player[4][0];
    else if (p->direction == 1)
        p->img.currentPlayerState = p->img.player[5][0];
    *stop_time = SDL_GetTicks();
    p->isMoving = 0;
    p->up = 0;
    p->down = 0;
    p->playerPos.y = 600;
    p->acceleration = 0;
}

void libPlayer(player *p)
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (p->img.player[i][j] != NULL)
            {
                SDL_FreeSurface(p->img.player[i][j]);
            }
        }
    }
}

void initScore(player *p)
{
    p->score.playerScore = 100;
    p->score.scorePos.x = 710;
    p->score.scorePos.y = 55;
    p->score.scoreBarPos.x = 620;
    p->score.scoreBarPos.y = 3;
    p->score.scoreBar = IMG_Load("images/lot1/scoreBar.png");
    if (p->score.scoreBar == NULL)
    {
        printf("Failed to load score bar image: %s\n", IMG_GetError());
    }
}

void displayScore(SDL_Surface *screen, player *p)
{
    char scoreStr[10];
    sprintf(scoreStr, "%d", p->score.playerScore);
    SDL_Color color = {255, 255, 255};
    TTF_Font *font = TTF_OpenFont("fonts/8-bit-hud.ttf", 20);
    if (font == NULL)
    {
        printf("Failed to load font: %s\n", TTF_GetError());
    }
    SDL_Surface *text = TTF_RenderText_Solid(font, scoreStr, color);
    SDL_Rect textPos = {p->score.scorePos.x, p->score.scorePos.y};
    // SDL_BlitSurface(bgIMG.img, &p->score.scoreBarPos, screen, &p->score.scoreBarPos);
    SDL_BlitSurface(p->score.scoreBar, NULL, screen, &p->score.scoreBarPos);
    SDL_BlitSurface(text, NULL, screen, &textPos);
    TTF_CloseFont(font);
    SDL_FreeSurface(text);
}

void initHealth(player *p)
{
    p->health.playerHP = 3;
    p->health.hpBarPos.x = 900;
    p->health.hpBarPos.y = 55;
    switch (p->health.playerHP)
    {
    case 3:
        p->health.hpBar = IMG_Load("images/lot1/hpBar3.png");
        break;
    case 2:
        p->health.hpBar = IMG_Load("images//lot1/hpBar2.png");
        break;
    case 1:
        p->health.hpBar = IMG_Load("images/lot1/hpBar1.png");
        break;
    case 0:
        p->health.hpBar = IMG_Load("images/lot1/hpBar0.png");
        break;
    }
}

void displayHealth(SDL_Surface *screen, player *p, image_lot1 bgIMG)
{
    SDL_BlitSurface(p->health.hpBar, NULL, screen, &p->health.hpBarPos);
}

/*void handleMovement(SDL_Surface *screen, player *p, Uint32 dt, Uint32 stop_time,int multiplayer);
{
   const Uint8 *keys = SDL_GetKeyState(NULL);
   SDL_Event event;

   while (SDL_PollEvent(&event))
   {
       switch (event.type)
       {
       case SDL_KEYDOWN:
           switch (event.key.keysym.sym)
           {
           case SDLK_d:
               p1->isMoving = 1;
               p1->direction = 0;
               movePlayer(p1, dt);
               if (keys[SDLK_d] && keys[SDLK_LSHIFT])
               {
                   if (p1->acceleration < 0.05)
                       p1->acceleration += 0.05;
               }
               break;
           case SDLK_q:
               p1->isMoving = 1;
               p1->direction = 1;
               movePlayer(p1, dt);
               if (keys[SDLK_q] && keys[SDLK_LSHIFT])
               {
                   if (p1->acceleration < 0.05)
                       p1->acceleration += 0.05;
               }
               break;
           case SDLK_z:
               p1->isMoving = 1;
               if (keys[SDLK_d] && keys[SDLK_z])
               {
                   p1->direction = 0;
                   p1->up = 2;
                   jumpPlayer(p1, screen, dt);
                   p1->hasJumped = 1;
               }
               else if (keys[SDLK_q] && keys[SDLK_z])
               {
                   p1->direction = 1;
                   p1->up = 2;
                   jumpPlayer(p1, screen, dt);
                   p1->hasJumped = 1;
               }
               else if (!p1->hasJumped)
               {
                   p1->up = 1;
                   jumpPlayer(p1, screen, dt);
               }
               p1->hasJumped = 0;
               break;
           case SDLK_s:
               p1->isMoving = 1;
               crouchPlayer(p1);
               break;
           case SDLK_RIGHT:
               p2->isMoving = 1;
               p2->direction = 0;
               movePlayer(p2, dt);
               if (keys[SDLK_RIGHT] && keys[SDLK_RSHIFT])
               {
                   if (p2->acceleration < 0.05)
                       p2->acceleration += 0.05;
               }
               break;
           case SDLK_LEFT:
               p2->isMoving = 1;
               p2->direction = 1;
               movePlayer(p2, dt);
               if (keys[SDLK_LEFT] && keys[SDLK_RSHIFT])
               {
                   if (p2->acceleration < 0.05)
                       p2->acceleration += 0.05;
               }
               break;
           case SDLK_UP:
               p2->isMoving = 1;
               if (keys[SDLK_RIGHT] && keys[SDLK_UP])
               {
                   p2->direction = 0;
                   p2->up = 2;
                   jumpPlayer(p2, screen, dt);
                   p2->hasJumped = 1;
               }
               else if (keys[SDLK_LEFT] && keys[SDLK_UP])
                               {
                   p2->direction = 1;
                   p2->up = 2;
                   jumpPlayer(p2, screen, dt);
                   p2->hasJumped = 1;
               }
               else if (!p2->hasJumped)
               {
                   p2->up = 1;
                   jumpPlayer(p2, screen, dt);
               }
               p2->hasJumped = 0;
               break;
           case SDLK_DOWN:
               p2->isMoving = 1;
               crouchPlayer(p2);
               break;
           }
           break;
            case SDL_MOUSEBUTTONDOWN:
                       player1.shoot = 1;
                       break;
                   case SDL_MOUSEBUTTONUP:
                       player1.shoot = 0;
                       break;
       case SDL_KEYUP:
           switch (event.key.keysym.sym)
           {
           case SDLK_LSHIFT:
               p1->acceleration = 0;
               p2->acceleration = 0;
               break;
           case SDLK_d:
               p1->isMoving = 0;
               p1->acceleration -= 0.01;
               stopPlayer(p1, &stop_time);
               break;
           case SDLK_q:
               p1->isMoving = 0;
               p1->acceleration -= 0.01;
               stopPlayer(p1, &stop_time);
               break;
           case SDLK_s:
               p1->isMoving = 0;
               stopPlayer(p1, &stop_time);
               break;
           case SDLK_RIGHT:
               p2->isMoving = 0;
               p2->acceleration -= 0.01;
               stopPlayer(p2, &stop_time);
               break;
           case SDLK_LEFT:
               p2->isMoving = 0;
               p2->acceleration -= 0.01;
               stopPlayer(p2, &stop_time);
               break;
           case SDLK_DOWN:
               p2->isMoving = 0;
               stopPlayer(p2, &stop_time);
               break;
           }
       }
   }
}*/
