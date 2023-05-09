/**

* @file enigme2.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "enigme2.h"
#include <SDL/SDL_mixer.h>
#include "../game.h"
/**
* @file enigme2.c
* @brief Testing Program.
* @author C Team
* @version 0.1
* @date Apr 01, 2015
*
* Testing program for background scrollilng
*
*/
/**
* @brief To genrate a random ques b .
* @param scren the screen
* @param b the background
* @return enigme
*/
enigme generer()
{
	enigme e;
	int x, y;
	int x1, y1;
	int p, o, j;
	float s, w, a;
	char sign[6] = "+-/*^%";
	srand(time(NULL));
	int i = rand() % 6;
	int k = rand() % 4;
	e.nrep = rand() % 3;
	int z = 1 + rand() % 4;
	int n = 1 + rand() % 4;
	x = rand() % 101;
	y = 1 + rand() % 101;
	x1 = rand() % 101;
	y1 = 1 + rand() % 60;
	p = 1 + rand() % 6;
	o = 1 + rand() % 6;
	j = 1 + rand() % 6;
	int p1, o1, po;
	switch (i)
	{
	case 0:
		s = (x) + (y);
		w = s - z;
		a = s + n;
		sprintf(e.ques, "calculer %d %c %d : ", x, sign[i], y);
		break;
	case 1:
		s = (x) - (y);
		w = s - n;
		a = s + z;
		sprintf(e.ques, "Calculer %d %c %d : ", x, sign[i], y);
		break;
	case 2:
		s = (float)x / y;
		w = s - 1;
		a = s + 1;
		sprintf(e.ques, "Calculer %d %c %d : ", x, sign[i], y);
		break;
	case 3:
		s = x * y;
		w = s - n;
		a = s + z;
		sprintf(e.ques, "Calculer %d %c %d : ", x, sign[i], y);
		break;
	case 5:
		p = y1 * x1;
		s = (float)p / 100;
		w = s - n;
		a = s + z;
		sprintf(e.ques, "Calculer %d %c de  %d : ", y1, sign[i], x1);
		break;
	case 4:

		switch (k)
		{
		case 1:
			s = pow(p, o);
			w = s - n;
			a = s + z;
			sprintf(e.ques, "Calculer %d ^ %d : ", p, o);
			break;
		case 2:

			p1 = pow(p, 2);
			o1 = pow(o, 2);
			po = 2 * (p * o);
			s = p1 + o1 + po;
			w = s - n;
			a = s + z;
			sprintf(e.ques, "Calculer (%d + %d )^2: ", p, o);
			break;
		case 3:

			p1 = pow(p, 2);
			o1 = pow(o, 2);
			po = 2 * (p * o);
			s = (p1 - po) + o1;
			w = s - n;
			a = s + z;
			sprintf(e.ques, "Calculer (%d - %d )^2: ", p, o);
			break;
		}
	}

	switch (e.nrep)
	{
	case 0:
		sprintf(e.rep1, "Reponse 1 : %.1f", s);
		sprintf(e.rep2, "Reponse 2 : %.1f", w);
		sprintf(e.rep3, "Reponse 3 : %.1f", a);
		break;
	case 1:
		sprintf(e.rep1, "Reponse 1 : %.1f", w);
		sprintf(e.rep2, "Reponse 2 : %.1f", s);
		sprintf(e.rep3, "Reponse 3 : %.1f", a);
		break;
	case 2:
		sprintf(e.rep1, "Reponse 1 : %.1f", a);
		sprintf(e.rep2, "Reponse 2 : %.1f", w);
		sprintf(e.rep3, "Reponse 3 : %.1f", s);
		break;
	}
	return e;
}
/**
* @brief To show the random ques b .
* @param scren the screen
* @param b the background
* @return void
*/
void afficherenigme(enigme e, SDL_Surface *screen)
{
	SDL_Surface *menu = NULL, *ques = NULL, *res1 = NULL, *res2 = NULL, *res3 = NULL, *msgf = NULL, *msgv = NULL, *msgh = NULL, *msgt = NULL;

	SDL_Rect posmenu, posques, posres1, posres2, posres3, posv, posf, posrep, posmsgf, posmsgv, posmsgh, posc1, posc2, posc3;
	SDL_Event event;
	SDL_Surface *couche[2], *c = NULL;
	TTF_Font *font = NULL;
	SDL_Color color = {0, 0, 0};
	Mix_Chunk *musicw = NULL, *musicr = NULL, *musich = NULL;
	int boucle = 1;
	e = generer();
	int ch, v;
	int score = 100;
	TTF_Init();
	int x1, i, nbvie;
	SDL_Init(SDL_INIT_VIDEO);
	couche[0] = IMG_Load("images/enigme_gen/casevrai.png");
	couche[1] = IMG_Load("images/enigme_gen/casefaux.png");
	c = IMG_Load("images/enigme_gen/casevide.png");
	font = TTF_OpenFont("fonts/Take Coffee.ttf", 20);
	ques = TTF_RenderText_Blended(font, e.ques, color);
	res1 = TTF_RenderText_Blended(font, e.rep1, color);
	res2 = TTF_RenderText_Blended(font, e.rep2, color);
	res3 = TTF_RenderText_Blended(font, e.rep3, color);
	msgf = TTF_RenderText_Blended(font, "Faux ", color);
	msgv = TTF_RenderText_Blended(font, "Vrai", color);
	msgh = TTF_RenderText_Blended(font, "vous aver choisie le help", color);

	menu = IMG_Load("images/enigme_gen/bgfinal.png");
	posmenu = (SDL_Rect){0, 0, 0, 0};
	SDL_BlitSurface(menu, NULL, screen, &posmenu);
	posc1 = (SDL_Rect){50, 135, 0, 0};
	posc2 = (SDL_Rect){50, 185, 0, 0};
	posc3 = (SDL_Rect){50, 235, 0, 0};
	posv = (SDL_Rect){50, 0, 0, 0};
	posf = (SDL_Rect){50, 0, 0, 0};
	posques = (SDL_Rect){130, 50, 0, 0};
	posres1 = (SDL_Rect){130, 150, 0, 0};
	posres2 = (SDL_Rect){130, 200, 0, 0};
	posres3 = (SDL_Rect){130, 250, 0, 0};
	posmsgf = (SDL_Rect){130, 300, 0, 0};
	posmsgv = (SDL_Rect){130, 300, 0, 0};
	posmsgh = (SDL_Rect){130, 350, 0, 0};

	switch (e.nrep)
	{
	case 0:
		posv.y = posres1.y - 15;
		break;
	case 1:
		posv.y = posres2.y - 15;
		break;
	case 2:
		posv.y = posres3.y - 15;
		break;
	}

	while (boucle != 0)
	{

		if (SDL_PollEvent(&event))
		{

			switch (event.type)
			{
				
			case SDL_MOUSEBUTTONDOWN:
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					if ((event.button.x >= 125 && event.button.x <= 170) && (event.button.y >= 135 && event.button.y <= 184))
					{
						ch = 0;
						posf.y = posres1.y - 15;

						if (ch != e.nrep)
						{
							score--;
							v = 1;
							posrep = posf;
							SDL_BlitSurface(couche[v], NULL, screen, &posrep);
						}
						else
						{
							v = 0;
							score++;
							posrep = posv;
							SDL_BlitSurface(couche[v], NULL, screen, &posrep);
							SDL_BlitSurface(msgv, NULL, screen, &posmsgv);
							SDL_Flip(screen);
							SDL_Delay(1000);
						}
						if (v != 0)
						{

							SDL_BlitSurface(msgf, NULL, screen, &posmsgf);
							SDL_Flip(screen);
							SDL_Delay(1000);
							v = 0;
							SDL_BlitSurface(couche[v], NULL, screen, &posv);
							SDL_Flip(screen);
							SDL_Delay(1000);
						}
						boucle = 0;
					}
					if ((event.button.x >= 125 && event.button.x <= 170) && (event.button.y >= 185 && event.button.y <= 234))
					{
						ch = 1;
						posf.y = posres2.y - 15;

						if (ch != e.nrep)
						{
							score--;
							v = 1;
							posrep = posf;
							SDL_BlitSurface(couche[v], NULL, screen, &posrep);
						}
						else
						{
							v = 0;
							score++;
							posrep = posv;
							SDL_BlitSurface(couche[v], NULL, screen, &posrep);
							SDL_BlitSurface(msgv, NULL, screen, &posmsgv);
							SDL_Flip(screen);
							SDL_Delay(1000);
						}
						if (v != 0)
						{

							SDL_BlitSurface(msgf, NULL, screen, &posmsgf);
							SDL_Flip(screen);
							SDL_Delay(1000);
							v = 0;
							SDL_BlitSurface(couche[v], NULL, screen, &posv);
							SDL_Flip(screen);
							SDL_Delay(1000);
						}
						boucle = 0;
					}
					if ((event.button.x >= 125 && event.button.x <= 170) && (event.button.y >= 235 && event.button.y <= 285))
					{
						ch = 2;
						posf.y = posres3.y - 15;

						if (ch != e.nrep)
						{
							score--;
							v = 1;
							posrep = posf;
							SDL_BlitSurface(couche[v], NULL, screen, &posrep);
						}
						else
						{
							v = 0;
							score++;
							posrep = posv;
							SDL_BlitSurface(couche[v], NULL, screen, &posrep);
							SDL_BlitSurface(msgv, NULL, screen, &posmsgv);
							SDL_Flip(screen);
							SDL_Delay(1000);
						}
						if (v != 0)
						{

							SDL_BlitSurface(msgf, NULL, screen, &posmsgf);
							SDL_Flip(screen);
							SDL_Delay(1000);
							v = 0;
							SDL_BlitSurface(couche[v], NULL, screen, &posv);
							SDL_Flip(screen);
							SDL_Delay(1000);
						}
						boucle = 0;
					}
				}
				break;

			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_a:
					boucle = 0;
					break;
				case SDLK_KP1:
					ch = 0;
					posf.y = posres1.y - 15;
					if (ch != e.nrep)
					{
						score--;
						v = 1;
						posrep = posf;
						SDL_BlitSurface(couche[v], NULL, screen, &posrep);
						SDL_Flip(screen);
						SDL_Delay(1000);
						Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
						musicw = Mix_LoadWAV("music/wrong.wav");
						Mix_PlayChannel(-1, musicw, 0);
						Mix_FreeChunk(musicw);
					}
					else
					{
						v = 0;
						score++;
						posrep = posv;
						SDL_BlitSurface(couche[v], NULL, screen, &posrep);
						SDL_BlitSurface(msgv, NULL, screen, &posmsgv);
						SDL_Flip(screen);
						SDL_Delay(1000);
						Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
						musicr = Mix_LoadWAV("music/right.wav");
						Mix_PlayChannel(-1, musicr, 0);
						Mix_FreeChunk(musicr);
					}
					if (v != 0)
					{
						SDL_BlitSurface(msgf, NULL, screen, &posmsgf);
						SDL_Flip(screen);
						SDL_Delay(1000);

						v = 0;
						SDL_BlitSurface(couche[v], NULL, screen, &posv);
						SDL_Flip(screen);
						SDL_Delay(1000);
					}
					boucle = 0;
					break;
				case SDLK_KP2:
					ch = 1;
					posf.y = posres2.y - 15;
					if (ch != e.nrep)
					{
						score--;
						v = 1;
						posrep = posf;
						SDL_BlitSurface(couche[v], NULL, screen, &posrep);
						Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
						musicw = Mix_LoadWAV("music/wrong.wav");
						Mix_PlayChannel(-1, musicw, 0);
						Mix_FreeChunk(musicw);
					}
					else
					{
						v = 0;
						score++;
						posrep = posv;
						SDL_BlitSurface(couche[v], NULL, screen, &posrep);
						SDL_BlitSurface(msgv, NULL, screen, &posmsgv);
						SDL_Flip(screen);
						SDL_Delay(1000);
						Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
						musicr = Mix_LoadWAV("music/right.wav");
						Mix_PlayChannel(-1, musicr, 0);
						Mix_FreeChunk(musicr);
					}
					if (v != 0)
					{
						SDL_BlitSurface(msgf, NULL, screen, &posmsgf);
						SDL_Flip(screen);
						SDL_Delay(1000);
						v = 0;
						SDL_BlitSurface(couche[v], NULL, screen, &posv);
						SDL_Flip(screen);
						SDL_Delay(1000);
					}
					boucle = 0;
					break;
				case SDLK_KP3:
					ch = 2;
					posf.y = posres3.y - 15;
					if (ch != e.nrep)
					{
						score--;
						v = 1;
						posrep = posf;
						SDL_BlitSurface(couche[v], NULL, screen, &posrep);
						Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
						musicw = Mix_LoadWAV("music/wrong.wav");
						Mix_PlayChannel(-1, musicw, 0);
						Mix_FreeChunk(musicw);
					}
					else
					{
						v = 0;
						score++;
						posrep = posv;
						SDL_BlitSurface(couche[v], NULL, screen, &posrep);
						SDL_BlitSurface(msgv, NULL, screen, &posmsgv);
						SDL_Flip(screen);
						SDL_Delay(1000);
						Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
						musicr = Mix_LoadWAV("music/right.wav");
						Mix_PlayChannel(-1, musicr, 0);
						Mix_FreeChunk(musicr);
					}
					if (v != 0)
					{
						SDL_BlitSurface(msgf, NULL, screen, &posmsgf);
						SDL_Flip(screen);
						SDL_Delay(1000);
						v = 0;
						SDL_BlitSurface(couche[v], NULL, screen, &posv);
						SDL_Flip(screen);
						SDL_Delay(1000);
					}
					boucle = 0;
					break;
				case SDLK_h:
					SDL_BlitSurface(msgh, NULL, screen, &posmsgh);
					int v = 0;
					SDL_BlitSurface(couche[v], NULL, screen, &posv);
					Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
					musich = Mix_LoadWAV("music/help.wav");
					Mix_PlayChannel(-1, musich, 0);
					Mix_FreeChunk(musich);
					break;
				}

				break;
			}
		}
		SDL_BlitSurface(c, NULL, screen, &posc1);
		SDL_BlitSurface(c, NULL, screen, &posc2);
		SDL_BlitSurface(c, NULL, screen, &posc3);
		SDL_BlitSurface(ques, NULL, screen, &posques);
		SDL_BlitSurface(res1, NULL, screen, &posres1);
		SDL_BlitSurface(res2, NULL, screen, &posres2);
		SDL_BlitSurface(res3, NULL, screen, &posres3);
		SDL_Flip(screen);
	}
	TTF_CloseFont(font);
	TTF_Quit;
	SDL_FreeSurface(couche[0]);
	SDL_FreeSurface(couche[1]);
	SDL_FreeSurface(ques);
	SDL_FreeSurface(res1);
	SDL_FreeSurface(res2);
	SDL_FreeSurface(res3);
}
