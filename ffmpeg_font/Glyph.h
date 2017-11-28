#pragma once

#include <string>

using namespace std;

typedef unsigned char byte;

class Glyph {
private:
	Glyph(char c);
	int fx;       // x position of glyph in font image
	int fy;       // y position of glyph in font image
	int fw;       // width of glyph
	int fh;       // height of glyph
	int xAdvance; // (x + advance) = start position of next glyph when rendering
	int xOffset;  // x adjustment to make when rendering
	int yOffset;  // y adjustment to make when rendering

	friend class Font;
};

