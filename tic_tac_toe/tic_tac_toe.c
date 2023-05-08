#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include <math.h>
#include "tic_tac_toe.h"

void initialiserTic(tic *t) {
    
    t->background_image = IMG_Load("images/tic_tac_toe/Tic Tac Toe.png");
    t->player_image = IMG_Load("images/tic_tac_toe/o.png");
    t->computer_image = IMG_Load("images/tic_tac_toe/x.png");
    
    
    
    t->tabsuivi[0] = 0;
    t->tabsuivi[1] = 0;
    t->tabsuivi[2] = 0;
    t->tabsuivi[3] = 0;
    t->tabsuivi[4] = 0;
    t->tabsuivi[5] = 0;
    t->tabsuivi[6] = 0;
    t->tabsuivi[7] = 0;
    t->tabsuivi[8] = 0;
    
    
    t->text_position.x = 0;
    t->text_position.y = 0;
    
    
    t->first_player = 1;
    t->tour = 1;
    t->font = TTF_OpenFont("fonts/Raleway-BoldItalic.ttf", 30);
    
    
 
    strcpy(t->text, "");
    t->text_position.x = 200;
    t->text_position.y = 300;
}



void afficherTic(tic t, SDL_Surface* ecran) {
    
    SDL_BlitSurface(t.background_image, NULL, ecran, &(t.background_image->clip_rect));

    for (int i = 0; i < 9; i++) {
        int row = i / 3; 
        int col = i % 3; 

        SDL_Rect rect;
        rect.x = col * t.background_image->w / 3 +30; 
        rect.y = row * t.background_image->h / 3 +35;  
        rect.w = t.background_image->w / 3; 
        rect.h = t.background_image->h / 3; 

        if (t.tabsuivi[i] == 1) {
            
            SDL_BlitSurface(t.player_image, NULL, ecran, &rect);
        } else if (t.tabsuivi[i] == 2) {
          
            SDL_BlitSurface(t.computer_image, NULL, ecran, &rect);
        }
    }

    
    SDL_Surface* text_surface = TTF_RenderText_Solid(t.font, t.text, t.font_color);
    SDL_BlitSurface(text_surface, NULL, ecran, &(t.text_position));
    SDL_FreeSurface(text_surface);
}


int atilganer(int tabsuivi[]) {
    int lignes_gagnantes[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    
    for (int i = 0; i < 8; i++) {
        if (tabsuivi[lignes_gagnantes[i][0]] == tabsuivi[lignes_gagnantes[i][1]] && 
            tabsuivi[lignes_gagnantes[i][0]] == tabsuivi[lignes_gagnantes[i][2]] &&
            tabsuivi[lignes_gagnantes[i][0]] != 0) {
            // On a trouvé une ligne gagnante avec des valeurs identiques et non nulles
            if (tabsuivi[lignes_gagnantes[i][0]] == 1) {
                // Le joueur humain a gagné
                return -1;
            } else {
                // La machine a gagné
                return 1;
            }
        }
    }
    // Aucun gagnant trouvé
    return 0;
}

void Resultat(int tabsuivi[], SDL_Surface* ecran) {
    int resultat = atilganer(tabsuivi);
    char message[50] = "";
    
    if (resultat ==-1) {
       
        strcpy(message, "defeat");
    } else if (resultat == 1) {
       
        strcpy(message, "victory");
    } else {
        
        strcpy(message, "draw");
    }

    
    TTF_Font* font = TTF_OpenFont("fonts/Raleway-BoldItalic.ttf", 24);
    SDL_Color font_color = {0, 0, 0}; 
    SDL_Surface* texte_surface = TTF_RenderText_Solid(font, message, font_color); 
    SDL_Rect texte_position; 
    texte_position.x = (ecran->w - texte_surface->w) / 2; 
    texte_position.y = (ecran->h - texte_surface->h) / 2; 
    SDL_BlitSurface(texte_surface, NULL, ecran, &texte_position); 
    SDL_FreeSurface(texte_surface); 
    TTF_CloseFont(font); 
    
}

void libererMemoire(tic *t) {
   
    SDL_FreeSurface(t->background_image);
    SDL_FreeSurface(t->player_image);
    SDL_FreeSurface(t->computer_image);

    
    TTF_CloseFont(t->font);

    
    TTF_Quit();
}


int minmax(int tabsuivi[9],int joueur)
{

int gagnant=atilganer(tabsuivi);
if(gagnant!=0)
return gagnant *joueur;
int coup=-1;
int score =-2;
int i;
for(i=0;i<9;i++)
{
    if(tabsuivi[i]==0)
    {tabsuivi[i]=joueur;
    int mmscore=-minmax(tabsuivi,joueur*-1);
    if(mmscore>score)
    {
        score=mmscore;
        coup=i;

    }
    tabsuivi[i]=0;
    
    
    }


}
if(coup==-1)
return 0;
return score;

}

void calcul_coup(int tabsuivi[9])
{

int coup=-1;
int score=-2;
int i;
for(i=0;i<9;++i)
{
    if(tabsuivi[i]==0)
    {

        tabsuivi[i]=1;
        int mmscore=-minmax(tabsuivi,-1);
        tabsuivi[i]=0;
        if (mmscore>score)
        {score=mmscore;
        coup=i;
        }
    }
}



tabsuivi[coup]=1;



}
