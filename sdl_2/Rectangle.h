#pragma once

#include "SDL.h"

class Rectangle {
public:
	Rectangle(SDL_Renderer * renderer, double w, double h, double x = 0, double y = 0);

	void setVelocity(double dx, double dy);
	void setColor(unsigned char red, unsigned char green, unsigned char blue);
	void update(double dt);
	void draw() const;

private:
	SDL_Renderer * renderer;
	double w;
	double h;
	double x;
	double y;
	double dx;
	double dy;
	unsigned char red;
	unsigned char green;
	unsigned char blue;
};

