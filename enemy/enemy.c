#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "enemy.h"
#include "../player/player.h"
#include "../game.h"
#include <time.h>
#include "../tic_tac_toe/tic_tac_toe.h"
/**
 * @file enemy.c
 * @brief contains all functions for the game
 * @author Malek Bsaissa
 * @version LOT 3
 * @date Apr 30,2023
 * @return multiple returns
 */

/**
 * @brief init ennemi_ground
 * @param Ennemi e
 * @return void
 */
void initEnnemi(Ennemi *e, char *url_left, char *url_right, int x, int y, int mode, int fly, int max_pos, int min_pos)
{
  e->url_left = url_left;
  e->url_right = url_right;
  e->img.url = url_left;
  e->img.img = IMG_Load(e->img.url);

  e->img.pos.x = x;
  e->img.pos.y = y;
  e->img.pos.w = e->img.img->w;
  e->img.pos.h = e->img.img->h;

  e->direction = 0;
  e->speed = 1;
  e->mode = mode;
  e->state.state = 1; // 0 : Waiting, 1 : Following , 2 : Attacking
  e->state.s1 = 400;
  e->state.s2 = 300;
  e->state.distance = 0;
  e->fly = fly;

  e->max_pos = max_pos;
  e->min_pos = min_pos;

  e->box_AABB.collision.x = e->img.pos.x;
  e->box_AABB.collision.y = e->img.pos.y;
  e->box_AABB.collision.w = e->img.pos.w;
  e->box_AABB.collision.h = e->img.pos.h;
}
/**
 * @brief afficher ennemi
 * @param image Image
 * @param SDL_Surface screen
 * @return void
 */

void DisplayEnnemi(Ennemi e, SDL_Surface *screen)
{
  SDL_BlitSurface(e.img.img, NULL, screen, &e.img.pos);
}
/**
 * @brief Control ennemi_air direction
 * @param Ennemi e
 * @return void
 */
void EnnemiDirection_AIR(Ennemi *e)
{
  int PosMax = 630 - e->img.pos.h;
  int PosMin = +e->img.pos.h;
  if (e->img.pos.y > PosMax)
  {
    e->direction = 1;
  }
  if (e->img.pos.y < PosMin)
  {
    e->direction = 0;
  }
}
/**
 * @brief Move ennemi_air
 * @param Ennemi e
 * @return void
 */
void moveY(Ennemi *e)
{
  EnnemiDirection_AIR(e);
  switch (e->direction)
  {
  case 0:
    e->img.pos.y += e->speed;

    break;
  case 1:
    e->img.pos.y -= e->speed;
    break;
  }
  e->box_AABB.collision.x = e->img.pos.x;
  e->box_AABB.collision.y = e->img.pos.y;
  e->box_AABB.collision.w = e->img.pos.w;
  e->box_AABB.collision.h = e->img.pos.h;
}

/**
 * @brief Collision between player and ennemi
 * @param player p
 * @param Ennemi e
 * @return int 1 if collision 0 if not
 */
int collisionBB(player p, Ennemi e)
{
  if (p.box_AABB.collision.x + p.box_AABB.collision.w < e.box_AABB.collision.x)
    return 0;
  if (p.box_AABB.collision.x > e.box_AABB.collision.x + e.box_AABB.collision.w)
    return 0;
  if (p.box_AABB.collision.y + p.box_AABB.collision.h < e.box_AABB.collision.y)
    return 0;
  if (p.box_AABB.collision.y > e.box_AABB.collision.y + e.box_AABB.collision.h)
    return 0;
  return 1;
}

/**
 * @brief Ennemi state (waiting, following, attacking)
 * @param player p
 * @param Ennemi e
 * @return void
 */
void EnnemyState(Ennemi *e, player p)
{
  // 0 : Waiting, 1 : Following , 2 : Attacking
  // s1 : following_threshold, s2 : attacking_threshold , d: distance

  e->state.distance = abs(p.box_AABB.collision.x - (e->box_AABB.collision.x + e->box_AABB.collision.w));

  switch (e->state.state)
  {
  case 0:
    if (e->state.distance > e->state.s1)
    {
      e->state.state = 0;
    }
    if (e->state.s2 < e->state.distance && e->state.distance <= e->state.s1)
    {
      e->state.state = 1;
    }
    break;

  case 1:
    if (e->state.s2 < e->state.distance && e->state.distance <= e->state.s1)
    {
      e->state.state = 1;
    }
    else if (e->state.distance > e->state.s1)
    {
      e->state.state = 0;
    }
    else if (e->state.distance <= e->state.s2)
    {
      e->state.state = 2;
    }
    break;

  case 2:
    if (0 < e->state.distance && e->state.distance <= e->state.s2)
    {
      e->state.state = 2;
    }
    else if (e->state.distance > e->state.s1)
    {
      e->state.state = 0;
    }
    else if (e->state.distance <= 0)
    {
      e->state.state = 1;
    }
    break;
  }
}
/**
 * @brief Controls ennemi_ground direction
 * @param player p
 * @param Ennemi e
 * @return void
 */
void EnnemiDirection_GROUND(Ennemi *e, player p)
{
  int PosMax = SCREEN_W - e->img.pos.w;
  int PosMin = 0;
  if ((e->img.pos.x > PosMax) || (p.box_AABB.collision.x < e->box_AABB.collision.x))
  {
    e->direction = 1;
    e->img.url = e->url_left;
  }
  if ((e->img.pos.x < PosMin) || (p.box_AABB.collision.x > e->box_AABB.collision.x))
  {
    e->direction = 0;
    e->img.url = e->url_right;
  }
  if (p.shoot == 1)
  {
    e->speed = 4;
    switch (e->direction)
    {
    case 0:
      e->direction = 1;
      e->img.url = e->url_left;
      break;
    case 1:
      e->direction = 0;
      e->img.url = e->url_right;
      break;
    }
    if (e->img.pos.x > PosMax || e->img.pos.x < PosMin)
    {
      e->speed = 0;
      e->state.state = 0;
    }
  }
}
/**
 * @brief Move ennemi_ground on x axis
 * @param Ennemi e
 * @return void
 */
void moveX(Ennemi *e)
{
  switch (e->direction)
  {
  case 0:
    e->img.pos.x += e->speed;
    break;
  case 1:
    e->img.pos.x -= e->speed;
    break;
  }

  e->img.img = IMG_Load(e->img.url);
  e->box_AABB.collision.x = e->img.pos.x;
  e->box_AABB.collision.y = e->img.pos.y;
  e->box_AABB.collision.w = e->img.pos.w;
  e->box_AABB.collision.h = e->img.pos.h;
}
/**
 * @brief Move ennemi_ground
 * @param player p
 * @param Ennemi e
 * @return void
 */
void MoveEnnemy(Ennemi *e, player p)
{
  // 0 : Waiting, 1 : Following, 2 : Attacking
  EnnemyState(e, p);
  switch (e->state.state)
  {
  case 0:
    e->speed = 0;
    break;
  case 1:
    e->speed = 1;
    break;
  case 2:
    e->speed = 3;
    break;
  }
  EnnemiDirection_GROUND(e, p);
  moveX(e);
}

/**
 * @brief Random direction
 * @param Ennemi e
 * @return void
 */
void DirectionRandom(Ennemi *e)
{
  e->speed = 1;
  int PosMax = e->max_pos - e->img.pos.w;
  int PosMin = e->min_pos + e->img.pos.w;
  if (e->img.pos.x > PosMax)
  {
    e->direction = 1;
    e->img.url = e->url_left;
  }
  if (e->img.pos.x < PosMin)
  {
    e->direction = 0;
    e->img.url = e->url_right;
  }
}

void UpdateEnnemy(Ennemi *e, player *p, SDL_Surface *screen)
{
  int r = rand() % 3;
  if (collisionBB(*p, *e))
  {
    switch (r)
    {
    case 0:

      break;
    case 1:

      break;
    case 2:

      break;
    default:
      p->score.playerScore -= 100;
      break;
    }
  }

  switch (e->fly)
  {
  case 1:
    moveY(e);
    break;
  case 0:
    switch (e->mode)
    {
    case 0:
      DirectionRandom(e);
      break;
    case 1:
      MoveEnnemy(e, *p);
      break;
    }
    break;
  }
  DisplayEnnemi(*e, screen);
}

void scroll_enemy(Ennemi *E, int direction, int step)
{
  if (direction == 1)
  {
    E->img.pos.x += step;
    E->max_pos += step;
    E->min_pos += step;
  }
  else if (direction == 0)
  {
    E->img.pos.x -= step;
    E->max_pos -= step;
    E->min_pos -= step;
  }
}