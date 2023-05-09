#include "sauv.h"
#include "../player/player.h"

void sauvegarder (player p, char * nomfichier)
{	
	FILE *f;
   
	f=fopen(nomfichier, "w");
	fprintf(f, "%d %d %d %d\n", p.playerPos.x, p.playerPos.y,p.score.playerScore,p.health.playerHP);
	fclose(f);
}

void charger (player *p , char * nomfichier)
{
	
	FILE *f=fopen(nomfichier,"r");
	if(f==NULL)
	{
	     printf("ERROR !");
	}
	else
	{	
		printf("loading");
		fscanf(f,"%d %d %d %d\n",&(p->playerPos.x),&(p->playerPos.y),&(p->score.playerScore),&(p->health.playerHP));
	
	}
	fclose(f);
}

