#ifndef ENEMY_H
#define ENEMY_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "../game.h"

/**
 * @file enemy.h
 * @brief Header for all functions and Structures for the game
 * @author Malek Bsaissa
 * @version LOT 3
 * @date Apr 30,2023
 * @return multiple return
 */

//--------------------ENNEMI--------------------
/**
 * @struct AABB
 * @brief Collison Bounding Box structure
 *
 */

typedef struct
{
  SDL_Rect collision; /*!<Rectangle*/
} AABB;

/**
 * @struct state
 * @brief state structure
 *
 */
typedef struct
{
  int state; /*!<Int*/ // 0 : Waiting, 1 : Following , 2 : Attacking
  int s1;              /*!<Int*/
  int s2;              /*!<Int*/
  int distance;        /*!<Int*/
} state;

/**
 * @struct Ennemi
 * @brief Ennemi structure
 *
 */
typedef struct
{
  image img;       /*!<Image*/
  char *url_right; /*!<Char*/
  char *url_left;  /*!<Char*/
  int direction;   /*!<Int*/
  AABB box_AABB;   /*!<AABB*/
  state state;     /*!<state*/
  int speed;       /*!<Int*/
  int mode;        /*!<Int*/
  int fly;         /*!<Int*/
} Ennemi;

//--------------------PLAYER--------------------
typedef struct
{
  int playerScore;
  SDL_Rect scoreBarPos;
  SDL_Surface *scoreBar;
} playerScore;
typedef struct
{
  int playerHP;
  SDL_Rect hpBarPos;
  SDL_Surface *hpBar;
} playerHealth;
typedef struct
{
  SDL_Surface *currentPlayerState;
  SDL_Surface *player[6][6];
  int direction;
} playerImage;
typedef struct
{
  SDL_Rect playerPos;
  playerScore score;
  playerHealth health;
  playerImage img;
  AABB box_AABB;
  int shoot;
  double speed, acceleration;
} player;

//--------------------Declaration--------------------
void initEnnemi(Ennemi *e, char *url_left, char *url_right, int x, int y, int mode, int fly);
void DisplayEnnemi(Ennemi e, SDL_Surface *screen);
void moveX(Ennemi *e);
void moveY(Ennemi *e);
void EnnemiDirection_GROUND(Ennemi *e, player p);
void EnnemiDirection_AIR(Ennemi *e);
int collisionBB(player p, Ennemi e);
void EnnemyState(Ennemi *e, player p);
void MoveEnnemy(Ennemi *e, player p);
void DirectionRandom(Ennemi *e);
void UpdateEnnemy(Ennemi e[], player *p, int nbEnnemi, SDL_Surface *screen);
#endif