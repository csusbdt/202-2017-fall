#include <iostream>
#include "SDL.h"
#include "Image.h"

const int screenWidth  = 640;
const int screenHeight = 480;

int main(int argc, char * argv[]) {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Window * window = SDL_CreateWindow(
		"CSE 202", 
		SDL_WINDOWPOS_UNDEFINED, 
		SDL_WINDOWPOS_UNDEFINED, 
		screenWidth, 
		screenHeight, 
		0);
	if (!window) {
		std::cout << "SDL Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	Image image(renderer);
	image.scale = .5;
	image.x = -image.getWidth() * image.scale;
	image.y = 100;
	image.load("ducky.bmp");

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
		if (dt > 1.0 / 30) {
			SDL_RenderClear(renderer);
			image.x += dt * 100;
			if (image.x > screenWidth) image.x = -image.getWidth() * image.scale;
			image.draw();
			SDL_RenderPresent(renderer);
			previous_millis = millis;
		}
	}


	SDL_Quit();

	std::cout << "OK" << std::endl;
}

