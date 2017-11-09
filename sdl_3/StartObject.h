#pragma once

#include <vector>
#include "Object.h"
#include "Rectangle.h"

class StartObject : public Object {
public:
	StartObject();
	~StartObject();
	virtual void update(double dt);
	virtual void draw() const {}

private:
	double elapsedSeconds;
	std::vector<Rectangle *> rectangles;
};

