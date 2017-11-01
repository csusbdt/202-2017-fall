/*
    This program illustrates how to start an SDL project.
    It simply renders a rectangle in the center of the screen.

    Use the following to build (under OS X).

        c++ `sdl2-config --libs --cflags` -I /usr/local/include *.cpp
*/

#include <iostream>
#include "SDL.h"

int main(int argc, char * argv[]) {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Window * window = SDL_CreateWindow(
		"CSE 202", 
		SDL_WINDOWPOS_UNDEFINED, 
		SDL_WINDOWPOS_UNDEFINED, 
		640, 
		480, 
		0);
	if (!window) {
		std::cout << "SDL Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	int flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, flags);

	SDL_Rect rect;
	rect.w = 162;
	rect.h = 100;
	rect.x = (640 - rect.w) / 2;
	rect.y = (480 - rect.h) / 2;

	Uint32 previous_millis = SDL_GetTicks();
	while (true) {
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				SDL_Quit();
				return 0;
			}
		}
		Uint32 millis = SDL_GetTicks();
		double dt =  (millis - previous_millis) / 1000.0;
		if (dt > 1.0 / 60) {
			SDL_RenderClear(renderer);
			SDL_RenderFillRect(renderer, &rect);
			SDL_RenderPresent(renderer);
			previous_millis = millis;
		}
	}

	SDL_Quit();

	std::cout << "OK" << std::endl;
}

