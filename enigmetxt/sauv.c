#include "sauv.h"
#include "../player/player.h"
#include"background.h"

void sauvegarder (player p, char * nomfichier)
{	
	FILE *f;
   
	f=fopen(nomfichier, "w");
	fprintf(f, "%d %d\n", p.playerPos.x, p.playerPos.y);
	fclose(f);
}

int charger (player *p, char * nomfichier)
{
	
	FILE *f=fopen(nomfichier,"r");
	if(f==NULL)
	{
	     printf("ERROR !");
	}
	else
	{	int x=0,y=0;
		printf("loading");
		fscanf(f,"%hd %hd\n",&p->playerPos.x,&p->playerPos.y);
	
	}
	fclose(f);
}

