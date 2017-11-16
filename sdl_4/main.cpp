/*
    This program illustrates how to start an SDL project.
    It simply renders a rectangle in the center of the screen.

    Use the following to build (under OS X).

        c++ `sdl2-config --libs --cflags` *.cpp
*/

#include <iostream>
#include "SDL.h"
#include "Engine.h"
#include "StartObject.h"

SDL_Renderer * renderer = nullptr;

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
	renderer = SDL_CreateRenderer(window, -1, flags);
	if (renderer == nullptr) {
		std::cout << "SDL Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	StartObject startObject;
	Engine::addObject(&startObject);
	return Engine::run();
}

