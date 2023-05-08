#ifndef ENIGMETF_H_INCLUDED
#define ENIGMETF_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
/**
* @file enigmetf.h
* @brief la fonction.h de l'enigme .
* @author WALAA
* @version 0.1
* @date Apr 01, 2023
*
* Testing program for enigmetext header file contain all functions definition
*
*/

/**
* @struct Background
* @brief struct for background
*/

struct backgroundlot5
{
	SDL_Rect bckg;	 /*!< Rectangle*/
	SDL_Surface img; /*!< Surface. */
};
typedef struct backgroundlot5 backgroundlot5;
typedef struct
{ 
	SDL_Surface *background;	/*!< Surface. */
	SDL_Surface *question;		/*!< Surface. */
	SDL_Surface *reponses[4]; /*!< Surface. */
	SDL_Surface *button;			/*!< Surface. */
	SDL_Surface *button_s;		/*!< Surface. */

	int pos_selected;
	SDL_Rect pos_question; /*!< Rectangle*/

	SDL_Rect pos_reponse1; /*!< Rectangle*/

	SDL_Rect pos_reponse2; /*!< Rectangle*/

	SDL_Rect pos_reponse3; /*!< Rectangle*/

	int num_question;

	SDL_Rect pos_reponse1txt; /*!< Rectangle*/

	SDL_Rect pos_reponse2txt; /*!< Rectangle*/

	SDL_Rect pos_reponse3txt; /*!< Rectangle*/
	int vrai_reponse;					
	int positionVraiReponse;	
	TTF_Font *police; /*!<Font*/
	TTF_Font *police1; /*<Font*/
	
    SDL_Surface *image_clock;/*!< Surface. */
	SDL_Rect pos_image_clock;/*!< Rectangle*/

	SDL_Rect single_Clock;/*!< Rectangle*/

	int clock_num;

} enigmetf;

void InitEnigme(enigmetf *e, char nomfichier[]);
void afficherEnigme(enigmetf e, SDL_Surface *ecran);
void displayClock(enigmetf e, SDL_Surface *ecran);
void verify_enigme(enigmetf *e, SDL_Surface *ecran);
void animer(enigmetf *e);
void free_Surface_enigme(enigmetf e);
void enigme(enigmetf e,SDL_Surface *screen);
#endif
