#include <stdlib.h>
#include <stdio.h>

#include "aff.h"





int main(int argc, char *argv[])
{ SDL_Surface *ecran=NULL ;
  SDL_Surface *bg=NULL;
  SDL_Surface *perso=NULL;
  
  SDL_Rect pos_bg;
  SDL_Rect pos_perso;
 
  SDL_Event event;

  int continuer = 1 ;



SDL_Init(SDL_INIT_VIDEO );

ecran = SDL_SetVideoMode(640, 450, 32, SDL_HWSURFACE| SDL_DOUBLEBUF | SDL_ACTIVEEVENT);

SDL_WM_SetCaption("FENETRE", NULL); //donner un titre a la fenetre

SDL_EnableKeyRepeat(50,20);

 


bg = IMG_Load("background.jpg");
pos_bg.x = 0 ; //position image
pos_bg.y = 0 ;


perso = IMG_Load("perso.png");
pos_perso.x = 200;
pos_perso.y = 250;



while (continuer)
{  
  SDL_WaitEvent(&event) ; //en attente d'un event
   switch ( event.type)
   {
    case SDL_QUIT :    //arret du prog 
      continuer = 0; 
      break;  

    case SDL_KEYDOWN:
       switch (event.key.keysym.sym)
       { case SDLK_ESCAPE : //apui sur echape
         continuer = 0;
         break;
         case SDLK_d:
         if (pos_perso.x < 580)       
         pos_perso.x +=10;      
                   
         break;
         case SDLK_q:
         pos_perso.x -=10;
         break;
         case SDLK_z:
         if (pos_perso.y >= 0)
         pos_perso.y -=10;
         break;
         case SDLK_s :
         if (pos_perso.y < 250)
         pos_perso.y +=10;
         break;

       }
             
         
         break; 
      }
SDL_BlitSurface(bg, NULL ,ecran, &pos_bg) ;
SDL_BlitSurface(perso, NULL ,ecran , &pos_perso);
SDL_Flip(ecran); 

      }


         

//pause(); 
SDL_FreeSurface(bg);
SDL_FreeSurface(perso);

SDL_Quit(); // Arrêt de la SDL
return EXIT_SUCCESS; // Fermeture du programme
}
