#include "enigmetf.h"
/**
 * @file enigmetf.c
 * @brief contient les fonctions de l'enigme txt.
 * @author WALAA
 * @version 0.1
 * @date Apr 01, 2023
 *
 * Testing program for enigmetext
 *
 */

/**
 * @brief initialiser enigme en mode aléatoire , initalisation du font .
 * @param char *nomfichier[]
 *@param enigmetf *e
 * @return void
 */
void InitEnigme(enigmetf *e, char nomfichier[])
{

	FILE *fquestion = NULL;
	FILE *freponse = NULL;
	FILE *fvraireponse = NULL;

	e->pos_selected = 0;
	e->background = IMG_Load("images/enigmetxt/back.jpg");
	e->button = IMG_Load("images/enigmetxt/button1.png");
	e->button_s = IMG_Load("images/enigmetxt/button_s1.png");

	TTF_Init();

	SDL_Color couleur = {0, 0, 0};
	(*e).police = TTF_OpenFont("fonts/arial.ttf", 30);
	e->police1 = TTF_OpenFont("fonts/arial.ttf", 20);

	char questionn[50];

	srand(time(NULL));
	e->num_question = rand() % 4;

	while (e->num_question == 0)
	{
		srand(time(NULL));
		e->num_question = rand() % 4;
	}

	char reponse[50];

	int min, max, vrep;
	switch (e->num_question)
	{
	case 1:
	{
		min = 3;
		max = 5;
		vrep = 12;

		break;
	}
	case 2:
	{
		min = 6;
		max = 8;
		vrep = 13;
		break;
	}
	case 3:
	{
		min = 9;
		max = 11;
		vrep = 14;
		break;
	}
	}

	fquestion = fopen(nomfichier, "r+");
	if (fquestion != NULL)
	{

		int test = 1;
		while (fgets(questionn, 50, fquestion) && (test != e->num_question))
		{
			test++;
		}
		fclose(fquestion);
	}

	fquestion = fopen(nomfichier, "r+");
	if (fquestion != NULL)
	{
		int testr = 0;
		while (fgets((reponse), 50, fquestion) && (testr < max))
		{

			if (testr >= min)
			{
				e->reponses[testr - min] = TTF_RenderText_Blended(e->police1, reponse, couleur);
			}
			testr++;
		}
		fclose(fquestion);
	}

	fquestion = fopen(nomfichier, "r+");
	if (fquestion != NULL)
	{
		int testrv = 1;
		while (fgets((reponse), 50, fquestion))
		{

			if (testrv == vrep)
			{
				printf("%s\n", reponse);
				e->reponses[2] = TTF_RenderText_Blended(e->police1, reponse, couleur);
			}
			testrv++;
		}
		fclose(fquestion);
	}

	srand(time(NULL));
	e->positionVraiReponse = rand() % 4;
	while (e->positionVraiReponse == 0)
	{
		srand(time(NULL));
		e->positionVraiReponse = rand() % 4;
	}
	printf("%d\n", e->positionVraiReponse);

	e->question = TTF_RenderText_Blended(e->police, questionn, couleur);

	e->pos_question.x = 270;
	e->pos_question.y = 270;

	e->pos_reponse1.x = 375;
	e->pos_reponse1.y = 522;

	e->pos_reponse2.x = 177;
	e->pos_reponse2.y = 648;

	e->pos_reponse3.x = 566;
	e->pos_reponse3.y = 651;

	e->pos_reponse1txt.x = e->pos_reponse1.x + 50;
	e->pos_reponse1txt.y = 522 + 30;

	e->pos_reponse2txt.x = 177 + 50;
	e->pos_reponse2txt.y = 648 + 30;

	e->pos_reponse3txt.x = 566 + 50;
	e->pos_reponse3txt.y = 651 + 30;

	(*e).image_clock = IMG_Load("images/enigmetxt/clock1.png");

	e->pos_image_clock.x = 900;
	e->pos_image_clock.y = 50;

	e->single_Clock.w = 57;
	e->single_Clock.h = 81;
	e->single_Clock.x = 0;
	e->single_Clock.y = 0;

	e->clock_num = 0;
}
/**
 * @brief afficher les questions des enigmes aléatoirement.
 * @param char SDL_Surface *ecran
 *@param enigmetf e
 * @return void
 */

void afficherEnigme(enigmetf e, SDL_Surface *ecran)
{

	SDL_BlitSurface(e.background, NULL, ecran, NULL);

	displayClock(e, ecran);
	SDL_BlitSurface(e.question, NULL, ecran, &e.pos_question);

	switch (e.positionVraiReponse)
	{
	case 1:
	{

		switch (e.pos_selected)
		{
		case 1:
		{
			SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse1);

			SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);

			SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);

			SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse1txt);

			SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse2txt);

			SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
		}
		break;
		case 2:
		{
			SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);

			SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse2);

			SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);

			SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse1txt);

			SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse2txt);

			SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
		}
		break;
		case 3:
		{
			SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);

			SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);

			SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse3);

			SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse1txt);

			SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse2txt);

			SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
		}
		break;
		default:
		{
			SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);

			SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);

			SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);

			SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse1txt);

			SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse2txt);

			SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
		}
		}
		break;
	}
	case 2:
	{
		switch (e.pos_selected)
		{
		case 1:
		{
			SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse1);

			SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);

			SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);

			SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);

			SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse2txt);

			SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
		}
		break;
		case 2:
		{
			SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);

			SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse2);

			SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);

			SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);

			SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse2txt);

			SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
		}
		break;
		case 3:
		{
			SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);

			SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);

			SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse3);

			SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);

			SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse2txt);

			SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
		}
		break;
		default:
		{
			SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);

			SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);

			SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);

			SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);

			SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse2txt);

			SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
		}
		}
		break;
	}
	case 3:
	{
		switch (e.pos_selected)
		{
		case 1:
		{
			SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse1);

			SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);

			SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);

			SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);

			SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse2txt);

			SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse3txt);
		}
		break;
		case 2:
		{
			SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);

			SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse2);

			SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);

			SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);

			SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse2txt);

			SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse3txt);
		}
		break;
		case 3:
		{
			SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);

			SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);

			SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse3);

			SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);

			SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse2txt);

			SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse3txt);
		}
		break;
		default:
		{
			SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);

			SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);

			SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);

			SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);

			SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse2txt);

			SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse3txt);
		}
		}

		break;
	}
	}

	SDL_Delay(100);
}
/**
 * @brief  veifier enigme .
 * @param char SDL_Surface *ecran
 *@param enigmetf *e
 * @return void
 */
void verify_enigme(enigmetf *e, SDL_Surface *ecran)
{

	SDL_Rect pos = {160, 330};
	if (e->positionVraiReponse == e->pos_selected)
	{

		SDL_Surface *great;
		great = IMG_Load("images/enigmetxt/great.png");
		printf("BINGO\n");
		SDL_BlitSurface(great, NULL, ecran, &pos);
		SDL_Flip(ecran);
	}
	else
	{
		SDL_Surface *wrong;
		wrong = IMG_Load("images/enigmetxt/false.png");
		SDL_BlitSurface(wrong, NULL, ecran, &pos);

		printf("FALSE\n");
	}
	SDL_Delay(1000);
}
/**
 * @brief afficher le  clock .
 * @param char SDL_Surface *ecran
 *@param enigmetf e
 * @return void
 */
void displayClock(enigmetf e, SDL_Surface *ecran)
{

	SDL_BlitSurface(e.image_clock, &(e.single_Clock), ecran, &e.pos_image_clock);
}
/**
 * @brief  animer l'image  de clock .
 *@param enigmetf *e
 * @return void  */

void animer(enigmetf *e)
{

	if (e->clock_num >= 0 && e->clock_num < 8)
	{
		e->single_Clock.x = e->clock_num * e->single_Clock.w;
		e->clock_num++;
	}

	if (e->clock_num == 8)
	{
		e->single_Clock.x = e->clock_num * e->single_Clock.w;
		e->clock_num = 0;
	}
}

/**
 * @brief libérer enigme txt.
 *@param enigmetf e
 * @return void
 */

void free_Surface_enigme(enigmetf e)
{

	SDL_FreeSurface(e.background);
	SDL_FreeSurface(e.question);
	SDL_FreeSurface(e.reponses[0]);
	SDL_FreeSurface(e.reponses[1]);
	SDL_FreeSurface(e.reponses[2]);
	SDL_FreeSurface(e.button);
	SDL_FreeSurface(e.button_s);
}

int enigme_tf(enigmetf e, SDL_Surface *screen)
{
	SDL_Surface *great;
	SDL_Surface *wrong;
	SDL_Rect pos = {160, 330};
	int bingoo = 0;
	int c = 1;
	SDL_Event event;

	while (c)
	{
		animer(&e);
		afficherEnigme(e, screen);
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
			{
				free_Surface_enigme(e);
			}
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_a:
					e.pos_selected = 1;
					c = 0;
					break;

				case SDLK_b:
					e.pos_selected = 2;
					c = 0;
					break;

				case SDLK_c:
					e.pos_selected = 3;
					c = 0;
					break;

				case SDLK_RETURN:
					verify_enigme(&e, screen);
					return 0;
					break;
				}
				break;
			case SDL_MOUSEMOTION:
			{
				printf("Souris en position %d %d\n", event.motion.x, event.motion.y);
			}
			case SDL_MOUSEBUTTONUP:
			{
				if ((event.motion.x > 375 && event.motion.x < 615) && (event.motion.y > 520 && event.motion.y < 610))
				{
					e.pos_selected = 1;
					if (event.button.button == SDL_BUTTON_LEFT)
					{
						if (bingoo == 1)
						{
							printf("GREAT\n");
							SDL_BlitSurface(great, NULL, screen, &pos);
							SDL_Flip(screen);
							c=0;
						}
						else
						{
							SDL_BlitSurface(wrong, NULL, screen, &pos);
							SDL_Flip(screen);
							printf("false\n");
							c=0;
						}
						SDL_Delay(2000);

						return 0;
					}
				}
				else if ((event.motion.x > 178 && event.motion.x < 411) && (event.motion.y > 649 && event.motion.y < 734))
				{
					e.pos_selected = 2;
					if (event.button.button == SDL_BUTTON_LEFT)
					{
						if (bingoo == 1)
						{
							printf("GREAT\n");
							SDL_BlitSurface(great, NULL, screen, &pos);
							SDL_Flip(screen);
							c=0;
						}
						else
						{
							SDL_BlitSurface(wrong, NULL, screen, &pos);
							SDL_Flip(screen);
							printf("false\n");
							c=0;
						}
						SDL_Delay(2000);

						return 0;
					}
				}
				else if ((event.motion.x > 568 && event.motion.x < 800) && (event.motion.y > 656 && event.motion.y < 731))
				{
					e.pos_selected = 3;
					if (event.button.button == SDL_BUTTON_LEFT)
					{
						if (bingoo == 1)
						{
							printf("GREAT\n");
							SDL_BlitSurface(great, NULL, screen, &pos);
							SDL_Flip(screen);
							c=0;
						}
						else
						{
							SDL_BlitSurface(wrong, NULL, screen, &pos);
							SDL_Flip(screen);
							printf("false\n");
							c=0;
						}
						SDL_Delay(1000);

						return 0;
					}
				}
			}
			break;
			}
		}
		if (e.positionVraiReponse == e.pos_selected)
		{
			bingoo = 1;
		}
		else
		{
			bingoo = 0;
		}

		SDL_Flip(screen);
	}
}
