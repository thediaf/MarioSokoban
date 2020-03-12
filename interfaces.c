#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL_image.h>
#include "interfaces.h"

/*void pause(SDL_Rect marioPosition)
{
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
            case SDL_QUIT :
                continuer = 0;
                break;
            case SDL_KEYDOWN :
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE :
                        continuer = 0;
                        break;
                    case SDLK_UP :
                        marioPosition.x -= 34;
                        break;
                    case SDLK_DOWN :
                        marioPosition.x += 34;
                        break;
                    case SDLK_RIGHT :
                        marioPosition.y += 34;
                        break;
                    case SDLK_LEFT :
                        marioPosition.y -= 34;
                        break;
                }
                break;
        }
    }
}
*/
void murs(SDL_Surface *ecran,SDL_Surface *mur,SDL_Rect murPosition)
{
    int i = 0;

    for (i = 0; i<12; i++)
    {
        murPosition.x = 34 * i;
        murPosition.y = 0;
        if (murPosition.x != 170 && murPosition.x != 204)
        {
            SDL_BlitSurface(mur, NULL, ecran, &murPosition);
        }
    }

    for (i = 0; i<4; i++)
    {
        murPosition.x = 34 * i;
        murPosition.y = 68;
        SDL_BlitSurface(mur, NULL, ecran, &murPosition);
    }

    murPosition.x = 102;
    murPosition.y = 102;
    SDL_BlitSurface(mur, NULL, ecran, &murPosition);


    for (i = 0; i<12; i++)
    {
        murPosition.x = 34 * i;
        murPosition.y = 34;
        if (murPosition.x <= 136)
        {
            SDL_BlitSurface(mur, NULL, ecran, &murPosition);
        }
    }

    for (i = 0; i<12; i++)
    {
        murPosition.x = 374;
        murPosition.y = 34 *i;
        SDL_BlitSurface(mur, NULL, ecran, &murPosition);
    }

    for (i = 0; i<12; i++)
    {
        murPosition.x = 34 *i;
        murPosition.y = 306;
        SDL_BlitSurface(mur, NULL, ecran, &murPosition);
    }

    for (i = 0; i<12; i++)
    {
        murPosition.x = 34 *i;
        murPosition.y = 340;
        SDL_BlitSurface(mur, NULL, ecran, &murPosition);
    }

    for (i = 0; i<12; i++)
    {
        murPosition.x = 34 *i;
        murPosition.y = 374;
        SDL_BlitSurface(mur, NULL, ecran, &murPosition);
    }

    for (i = 0; i<9; i++)
    {
        murPosition.x = 34 *i;
        murPosition.y = 238;
        SDL_BlitSurface(mur, NULL, ecran, &murPosition);
    }

    for (i = 0; i<4; i++)
    {
        murPosition.x = 34 *i;
        murPosition.y = 204;
        SDL_BlitSurface(mur, NULL, ecran, &murPosition);
    }

    for (i = 0; i<4; i++)
    {
        murPosition.x = 34 *i;
        murPosition.y = 272;
        SDL_BlitSurface(mur, NULL, ecran, &murPosition);
    }

    for (i = 0; i<12; i++)
    {
        murPosition.x = 34 * i;
        murPosition.y = 170;
        if (murPosition.x == 0 || murPosition.x == 102 || murPosition.x == 170
             || murPosition.x == 340)
        {
            SDL_BlitSurface(mur, NULL, ecran, &murPosition);
        }
    }

    for (i = 0; i<4; i++)
    {
        murPosition.x = 340;
        murPosition.y = 102 + (34*i);
        SDL_BlitSurface(mur, NULL, ecran, &murPosition);
    }

    for (i = 0; i<5; i++)
    {
        murPosition.x = 272;
        murPosition.y = 68 + (34*i);
        if (murPosition.y != 170)
            SDL_BlitSurface(mur, NULL, ecran, &murPosition);
    }

    for (i = 0; i<5; i++)
    {
        murPosition.x = 238;
        murPosition.y = 68 + (34*i);
        if (murPosition.y != 170 && murPosition.y != 136)
            SDL_BlitSurface(mur, NULL, ecran, &murPosition);
    }

    murPosition.x = 170;
    murPosition.y = 102;
    SDL_BlitSurface(mur,NULL,ecran,&murPosition);

}

void objectifs(SDL_Surface *ecran,SDL_Surface *objectif,SDL_Rect objectifPosition)
{

    objectifPosition.x = 34;
    objectifPosition.y = 102;
    SDL_BlitSurface(objectif,NULL,ecran,&objectifPosition);

    objectifPosition.x = 68;
    objectifPosition.y = 102;
    SDL_BlitSurface(objectif,NULL,ecran,&objectifPosition);

    objectifPosition.x = 138;
    objectifPosition.y = 272;
    SDL_BlitSurface(objectif,NULL,ecran,&objectifPosition);

}

void caisses(SDL_Surface *ecran,SDL_Surface *caisse,SDL_Rect caissePosition[3])
{

    caissePosition[0].x = 170;
    caissePosition[0].y = 136;
    SDL_BlitSurface(caisse, NULL, ecran, &caissePosition[0]);

    caissePosition[1].x = 306;
    caissePosition[1].y = 136;
    SDL_BlitSurface(caisse, NULL, ecran, &caissePosition[1]);

    caissePosition[2].x = 306;
    caissePosition[2].y = 204;
    SDL_BlitSurface(caisse, NULL, ecran, &caissePosition[2]);


}

void personnage(SDL_Surface *ecran, SDL_Surface *mario, SDL_Rect marioPosition)
{
    marioPosition.x = 170;
    marioPosition.y = 34;
    SDL_BlitSurface(mario, NULL, ecran, &marioPosition);
}
