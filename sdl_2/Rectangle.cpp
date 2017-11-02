#include "Rectangle.h"

Rectangle::Rectangle(SDL_Renderer * renderer, double w, double h, double x, double y)
: renderer(renderer), w(w), h(h), x(x), y(y), dx(0), dy(0), red(255), green(255), blue(255) {
}

void Rectangle::setVelocity(double dx, double dy) {
	this->dx = dx;
	this->dy = dy;
}

void Rectangle::setColor(unsigned char red, unsigned char green, unsigned char blue) {
	this->red = red;
	this->green = green;
	this->blue = blue;
}

void Rectangle::update(double dt) {
	x += dx * dt;
	y += dy * dt;
}

void Rectangle::draw() const {
	SDL_Rect rect;
	rect.w = w;
	rect.h = h;
	rect.x = x;
	rect.y = y;
	SDL_SetRenderDrawColor(renderer, red, green, blue, 255);
	SDL_RenderFillRect(renderer, &rect);
}

