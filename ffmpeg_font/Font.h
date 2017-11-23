#pragma once

#include <string>

using namespace std;

typedef unsigned char byte;

class Font {
public:
	Font();
	~Font() { delete [] pixels; }
	void draw(const string & text, double x, double y) const;

private:
	byte * pixels;
	int w;  // width of font image in pixels
	int h;  // height of font image in pixels
};

