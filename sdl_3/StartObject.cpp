#include <iostream>
#include <random>

#include "StartObject.h"
#include "Engine.h"

StartObject::StartObject() : rectangle(162, 100) {
	rectangle.setX(100);
	rectangle.setY(-100);
	rectangle.setVelocity(0, 200);
	rectangle.setColor(70, 40, 200);
}

void StartObject::update(double dt) {
	if (elapsedSeconds == 0) {
		Engine::addObject(&rectangle);
	}
	if (rectangle.getY() > Engine::getHeight()) {
		std::uniform_int_distribution<int> randomColor(0, 255);
		rectangle.setColor(randomColor(generator), randomColor(generator), randomColor(generator));
		std::uniform_real_distribution<double> randomX(-80, Engine::getWidth() - 80);
		rectangle.setX(randomX(generator));
		rectangle.setY(-100);
	}
	elapsedSeconds += dt;
}

