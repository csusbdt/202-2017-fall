#include <stdio.h>
#include <cstring>
#include "Frame.h"

Frame::Frame(int w, int h)  { 
	this->w = w;
	this->h = h;
	pixels = new byte[w * h * 3]; 
}

Frame::~Frame() { 
	delete pixels; 
}

void Frame::setPixel(int x, int y, byte r, byte g, byte b) {
	if (x < 0 || x >= w || y < 0 || y >= h) return;
	pixels[y * w * 3 + x * 3 + 0] = r;
	pixels[y * w * 3 + x * 3 + 1] = g;
	pixels[y * w * 3 + x * 3 + 2] = b;
}

void Frame::blendPixel(int x, int y, byte r, byte g, byte b, byte a) {
	if (x < 0 || x >= w || y < 0 || y >= h) return;
    double q = a / 255.0;
    double p = 1 - q;
	pixels[y * w * 3 + x * 3 + 0] = p * pixels[y * w * 3 + x * 3 + 0] + q * r;
	pixels[y * w * 3 + x * 3 + 1] = p * pixels[y * w * 3 + x * 3 + 1] + q * g;
	pixels[y * w * 3 + x * 3 + 2] = p * pixels[y * w * 3 + x * 3 + 2] + q * b;
}

void Frame::clear() { 
	memset(pixels, 0, h * w * 3); 
}

bool Frame::isOutside(int x, int y) const {
	return x < 0 || x >= w || y < 0 || y >= h;
}

void Frame::write(FILE * file) const {
	fwrite(pixels, 3, w * h, file);
}

