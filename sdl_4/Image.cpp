#include <iostream>
#include "Image.h"

extern SDL_Renderer * renderer;

Image::Image(double x, double y)
: w(0), h(0), x(x), y(y), dx(0), dy(0), scale(1), texture(nullptr) {
}

Image::~Image() {
	SDL_DestroyTexture(texture);
}

void Image::load(const std::string & filename) {
	SDL_Surface * surface = SDL_LoadBMP(filename.c_str());
	if (surface == nullptr) {
		std::cout << "SDL Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		exit(1);
	}
	w = surface->w;
	h = surface->h;

	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}

void Image::setVelocity(double dx, double dy) {
	this->dx = dx;
	this->dy = dy;
}

void Image::update(double dt) {
	x += dx * dt;
	y += dy * dt;
}

void Image::draw() const {
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w * scale;
	rect.h = h * scale;
	SDL_RenderCopy(renderer, texture, nullptr, &rect);
}

