#ifndef PLAYER_H
#define PLAYER_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
typedef struct
{
  char *url;
  SDL_Rect displayed_img_pos;
  SDL_Rect screen_img_pos;
  SDL_Surface *img;
} image_lot1;
typedef struct
{
  SDL_Rect collision;
} AABB;

typedef struct
{
  SDL_Rect scorePos;
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
  SDL_Surface *player[6][9];
} playerImage;
typedef struct
{
  SDL_Rect playerPos;
  playerScore score;
  playerHealth health;
  playerImage img;
  double velocity, acceleration;
  int direction;
  int up;
  int down;
  int isMoving;
  int hasJumped;
  AABB box_AABB;
  int shoot;
  int IS_HIT;
  int multiplayer;
} player;

void initPlayer1(player *p);
void initPlayer2(player *p);
void displayPlayer(SDL_Surface *screen, player p);
void movePlayer(player *p, Uint32 dt);
void stopPlayer(player *p, Uint32 *stop_time);
void jumpPlayer(player *p, SDL_Surface *screen, Uint32 dt);
void crouchPlayer(player *p);
void animatePlayer(player *p, Uint32 stop_time);
void handleMovement(SDL_Surface *screen, player *p1, player *p2, Uint32 dt, Uint32 stop_time, int multiplayer, int game, int level);
void initScore(player *p);
void displayScore(SDL_Surface *screen, player *p);
void libPlayer(player *p);
void initHealth(player *p);
void displayHealth(SDL_Surface *screen, player *p, image_lot1 bgIMG);
#endif
