/*
    This program illustrates how to start an SDL project.
    It simply renders a rectangle in the center of the screen.

    Use the following to build (under OS X).

        c++ `sdl2-config --libs --cflags` *.cpp
*/

#include <iostream>
#include "SDL.h"
#include "Rectangle.h"

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
	if (window == nullptr) {
		std::cout << "SDL Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	int flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, flags);

	Rectangle rect(renderer, 162, 100, -162, -100);
	rect.setVelocity(50, 30);
	rect.setColor(128, 100, 45);

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
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			SDL_RenderClear(renderer);

			rect.update(dt);
			rect.draw();

			SDL_RenderPresent(renderer);
			previous_millis = millis;
		}
	}
}

