#pragma once

#include "global.h"

class Frame {
public:
	Frame();
	~Frame();
	void setPixel(int x, int y, byte r, byte g, byte blue);
	void clear();
	bool isOutside(int * x, int * y) const;
	void write(FILE * file) const;
	

private:
	unsigned char * pixels;
};

