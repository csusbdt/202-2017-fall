#include <iostream>

#include "StartObject.h"
#include "Engine.h"

StartObject::StartObject() : rectangle(162, 100) {
	rectangle.setXY((Engine::getWidth() - 162) / 2, (Engine::getHeight() - 100) / 2);
	rectangle.setVelocity(50, 30);
	rectangle.setColor(70, 40, 200);
}

void StartObject::update(double dt) {
	if (elapsedSeconds == 0) {
		Engine::addObject(&rectangle);
	}
	elapsedSeconds += dt;
}

