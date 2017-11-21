#pragma once

typedef unsigned char byte;

class Image {
public:
	Image() : pixels(0), w(0), h(0) {}
	void load(const char * filename, int w, int h);
	void draw() const;

private:
	byte * pixels;
	int w;
	int h;
};

