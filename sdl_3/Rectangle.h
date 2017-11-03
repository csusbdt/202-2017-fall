#pragma once

#include "SDL.h"
#include "Object.h"

class Rectangle : public Object {
public:
	Rectangle(double w, double h, double x = 0, double y = 0);

	virtual void update(double dt);
	virtual void draw() const;

	void setXY(double x, double y);
	void setVelocity(double dx, double dy);
	void setColor(unsigned char red, unsigned char green, unsigned char blue);

private:
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

