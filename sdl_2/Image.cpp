#include <cassert>
#include <iostream>

#include "Image.h"

using namespace std;

Image::Image(SDL_Renderer * renderer) 
: renderer(renderer), texture(nullptr), w(0), h(0), x(0), y(0), scale(1) {
}

Image::~Image() {
	SDL_DestroyTexture(texture);
}

void Image::load(const char * filename) {
	SDL_Surface * surface = SDL_LoadBMP(filename);
	if (surface == nullptr) {
		cout << "SDL Error: " << SDL_GetError() << endl;
		SDL_Quit();
		exit(1);
	}
	w = surface->w;
	h = surface->h;

	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}

//void Image::update(double dt) {
//	this->x += 100 * dt;
//}

void Image::draw() const {
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w * scale;
	rect.h = h * scale;
	SDL_RenderCopy(renderer, texture, nullptr, &rect);
}

