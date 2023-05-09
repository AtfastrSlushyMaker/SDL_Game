#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "sauv.h"
#include "../player/player.h"

void sauvegarder(player p, char *nomfichier)
{
	FILE *f;

	f = fopen(nomfichier, "w");
	fprintf(f, "%d %d %d %d \n", p.playerPos.x, p.playerPos.y, p.score.playerScore, p.health.playerHP);
	fclose(f);
}

void charger(player *p, char *nomfichier)
{

	FILE *f = fopen(nomfichier, "r");
	int x, y, health, score;
	if (f == NULL)
	{
		printf("ERROR !");
	}
	else
	{
		printf("loading");
		fscanf(f, "%d %d %d %d\n", &x, &y, &score, &health);

		p->playerPos.y = y;
		p->playerPos.x = x;
		p->health.playerHP = health;
		p->score.playerScore = score;
	}
	fclose(f);
}