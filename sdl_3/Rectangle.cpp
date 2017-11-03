#include "Rectangle.h"

extern SDL_Renderer * renderer;

Rectangle::Rectangle(double w, double h, double x, double y)
: w(w), h(h), x(x), y(y), dx(0), dy(0), red(255), green(255), blue(255) {
}

void Rectangle::setXY(double x, double y) {
	this->x = x;
	this->y = y;
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

