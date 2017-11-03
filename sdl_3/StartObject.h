#pragma once

#include "Object.h"
#include "Rectangle.h"

class StartObject : public Object {
public:
	StartObject();
	virtual void update(double dt);
	virtual void draw() const {}

private:
	double elapsedSeconds;
	Rectangle rectangle;
};

