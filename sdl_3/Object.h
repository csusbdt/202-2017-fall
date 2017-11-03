#pragma once

#include <random>

class Object {
public:
	static std::default_random_engine generator;
	static const double PI;
	static const double PHI;

	virtual void update(double dt) = 0;
	virtual void draw() const = 0;
};

