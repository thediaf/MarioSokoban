#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL_image.h>
#include "interfaces.c"


int main(int argc, char* argv[])
{
    SDL_Surface *ecran = NULL, *caisse = NULL, *mario_haut = NULL,
        *mario_bas = NULL, *mario_droite = NULL, *mario_gauche = NULL,
            *mario = NULL, *objectif = NULL, *mur = NULL;
    SDL_Rect murPosition, objectifPosition, caissePosition[3] = {0}, marioPosition;
    int i = 0;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_WM_SetCaption("Mario Sokoban",NULL);
    SDL_WM_SetIcon(IMG_Load("images/caisse.jpg"),NULL);

    ecran = SDL_SetVideoMode(410, 410, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);


    mur = IMG_Load("images/mur.jpg");
   // murs(ecran,mur,murPosition);

    objectif = IMG_Load("images/objectif.png");
    //objectifs(ecran,objectif,objectifPosition);

    caisse = IMG_Load("images/caisse.jpg");
    //caisses(ecran, caisse, caissePosition);

    mario_bas = IMG_Load("images/mario_bas.gif");
    mario_haut = IMG_Load("images/mario_haut.gif");
    mario_droite = IMG_Load("images/mario_droite.gif");
    mario_gauche = IMG_Load("images/mario_gauche.gif");
    mario = mario_bas;
    //personnage(ecran,mario,marioPosition);

    SDL_Flip(ecran);

    marioPosition.x = 170;
    marioPosition.y = 34;
//    pause(marioPosition);*/

    int continuer = 1;
    SDL_Event event;

    SDL_Flip(ecran);

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
                    case SDLK_RIGHT :
                        //SDL_BlitSurface(mario_droite,NULL,ecran,&marioPosition);
                        mario = mario_droite;
                        marioPosition.x += 34;
                        break;
                    case SDLK_LEFT :
                        mario = mario_gauche;
                        //SDL_BlitSurface(mario_gauche,NULL,ecran,&marioPosition);
                        if ((murPosition.x - 34) != marioPosition.x && (murPosition.y - 34) != marioPosition.y)
                            marioPosition.x -= 34;
                        break;
                    case SDLK_UP :
                    {
                        marioPosition.y -= 34;
                        mario = mario_haut;
                        //SDL_BlitSurface(mario_haut,NULL,ecran,&marioPosition);
                        for (i = 0; i < 3; i++)

                            if (marioPosition.y == (caissePosition[i].y ) && marioPosition.y == (caissePosition[i].x))
                                caissePosition[i].y -= 34;     /* code */


                        break;
                    }
                    case SDLK_DOWN :
                        marioPosition.y += 34;
                       mario = mario_bas;
                       //SDL_BlitSurface(mario_bas,NULL,ecran,&marioPosition);
                        break;

                }
                break;
        }

        SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
        murs(ecran,mur,murPosition);
        objectifs(ecran,objectif,objectifPosition);
        caisses(ecran, caisse, caissePosition);
        SDL_BlitSurface(mario,NULL,ecran,&marioPosition);

        //personnage(ecran,mario,marioPosition);
        SDL_Flip(ecran);

    }

    SDL_FreeSurface(mario_haut);
    SDL_FreeSurface(mario_bas);
    SDL_FreeSurface(mario_droite);
    SDL_FreeSurface(mario_gauche);
    SDL_FreeSurface(caisse);
    SDL_FreeSurface(objectif);
    SDL_FreeSurface(mur);
    SDL_Quit();

    return EXIT_SUCCESS;
}
