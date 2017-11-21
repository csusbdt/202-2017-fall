#pragma once

typedef unsigned char byte;

class Image {
public:
	Image() : pixels(0), w(0), h(0), x(0), y(0) { }
	~Image() { delete [] pixels; }
	void load(const char * filename, int w, int h);
	void draw() const;

private:
	byte * pixels;
	int w;  // width of image in pixels
	int h;  // height of image in pixels
	int x;  // Location of image inside of the frame.
	int y;
};

