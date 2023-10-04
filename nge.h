#ifndef __NGE__
#define __NGE__

#ifndef __linux__
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

static SDL_Window* window;
static SDL_Renderer* renderer;
static int running = 0;

int nge_running()
{
  return running;
}

void nge_init()
{
  /* TODO: Check the return value. It can fail, lol. */
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_SHOWN, &window, &renderer);
	SDL_RenderSetLogicalSize(renderer, 160, 144);
	running = 1;
}

void nge_quit()
{
  /* TODO: Check the return value. It can fail, lol. 
   * Also check if renderer and window is NULL
   * */
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void nge_update()
{
  SDL_Event ev;
  while (SDL_PollEvent(&ev)) {
    if (ev.type == SDL_QUIT) {
      running = 0;
    }
  }
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
  SDL_RenderClear(renderer);
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

void nge_swap()
{
  SDL_RenderPresent(renderer);
}

void nge_draw_point(int x, int y)
{
  SDL_RenderDrawPoint(renderer, x, y);
}

#endif /* __NGE__ */
