#include "Frame.h"
#include "Glyph.h"

using namespace std;

extern Frame frame;

Glyph::Glyph(char c) {
	if (c == '0') {
		fx = 344;
		fy = 98;
		fw = 30;
		fh = 42;
		xOffset = 4;
		yOffset = 8;
		xAdvance = 28;
	} else if(c == '1') {
		fx = 354;
		fy = 56;
		fw = 22;
		fh = 40;
		xOffset = 8;
		yOffset = 10;
		xAdvance = 28;
	} else if(c == '2') {
		fx = 178;
		fy = 142;
		fw = 30;
		fh = 40;
		xOffset = 3;
		yOffset = 10;
		xAdvance = 28;
	} else { // '3'
		fx = 312;
		fy = 98;
		fw = 30;
		fh = 42;
		xOffset = 3;
		yOffset = 8;
		xAdvance = 28;
	}	
}


