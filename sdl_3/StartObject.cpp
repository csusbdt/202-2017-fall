#include <iostream>
#include <random>

#include "StartObject.h"
#include "Engine.h"

StartObject::StartObject() : elapsedSeconds(0) {
	Rectangle * r = new Rectangle(162, 100);
	r->setX(100);
	r->setY(-100);
	r->setVelocity(0, 200);
	r->setColor(70, 40, 200);
	rectangles.push_back(r);

	r = new Rectangle(50, 50);
	r->setX(300);
	r->setY(-50);
	r->setVelocity(0, 100);
	r->setColor(170, 40, 100);
	rectangles.push_back(r);
}

StartObject::~StartObject() {
	for (int i = 0; i < rectangles.size(); ++i) {
		delete rectangles[i];
	}
}

void StartObject::update(double dt) {
	if (elapsedSeconds == 0) {
		for (int i = 0; i < rectangles.size(); ++i) {
			Engine::addObject(rectangles[i]);
		}
	}
	for (int i = 0; i < rectangles.size(); ++i) {
		if (rectangles[i]->getY() > Engine::getHeight()) {
			std::uniform_int_distribution<int> randomColor(0, 255);
			rectangles[i]->setColor(
				randomColor(generator), 
				randomColor(generator), 
				randomColor(generator)
			);
			std::uniform_real_distribution<double> randomX(
				-80, 
				Engine::getWidth() - 80
			);
			rectangles[i]->setX(randomX(generator));
			rectangles[i]->setY(-rectangles[i]->getH());
		}
	}
	elapsedSeconds += dt;
}

