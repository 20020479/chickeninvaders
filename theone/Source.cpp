#include"COMMON_FUNCTION.h"
#include"MainObject.h"
 bool Init()
{
  if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
  {
      return false;
  }
  g_screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
  if (g_screen == NULL)
  {
    return false;
  }

  return true;
}

 
 
int main(int arc, char* argv[])
{
  bool is_quit = false;
  if (Init() == false)
   return 0;
 
    g_bkground = SDL_CF::LoadImage("img//sky2.png");
  if (g_bkground == NULL)
  {
      return 0;
  }
 
 


 //load nhân vật:
 MainObject plane_object;
 plane_object.SetRect(300,120);
 bool ret = plane_object.LoadImage("img/plane.png");
   if(!ret)
   {
	   return 0;
   }
   
  while (!is_quit) 
  {
    while (SDL_PollEvent(&g_even)) 
    {
      if (g_even.type == SDL_QUIT)
      {
        is_quit = true;
        break;
      }
	  plane_object.HandleInputAction(g_even);
    }
		SDL_CF:: ApplySurface(g_bkground, g_screen, 0, 0);

	plane_object.Show(g_screen);
	plane_object.HandleMove();
  
    if ( SDL_Flip(g_screen) == -1)
    return 0;
  }
 SDL_CF:: CleanUp();
  SDL_Quit();
  return 1;
}