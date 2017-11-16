#pragma once

#include <string>
#include "SDL.h"
#include "Object.h"

class Image : public Object {
public:
	Image(double x = 0, double y = 0);
	~Image();

	virtual void update(double dt);
	virtual void draw() const;

	void load(const std::string & filename);
	double getH() { return scale * h; }
	double getW() { return scale * w; }
	double getX() { return x; }
	double getY() { return y; }
	void setX(double x) { this->x = x; }
	void setY(double y) { this->y = y; }
	void setScale(double scale) { this->scale = scale; }
	void setVelocity(double dx, double dy);

private:
	double w;
	double h;
	double x;
	double y;
	double dx;
	double dy;
	double scale;
	SDL_Texture  * texture;
};

