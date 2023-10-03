#include <SDL.h>

int main(int argc, char* argv[])
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	int nge_running = 0;
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_SHOWN, &window, &renderer);
	SDL_RenderSetLogicalSize(renderer, 160, 144);
	int running = 1;
	while (running) {
		SDL_Event ev;
		while (SDL_PollEvent(&ev)) {
			if (ev.type == SDL_QUIT) {
				running = 0;
			}
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderDrawPoint(renderer, 1, 1);
		SDL_RenderDrawPoint(renderer, 159, 1);
		SDL_RenderDrawPoint(renderer, 1, 143);
		SDL_RenderDrawPoint(renderer, 159, 143);

		SDL_RenderPresent(renderer);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}