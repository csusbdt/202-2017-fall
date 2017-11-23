#include <stdio.h>
#include <cstring>
#include <iostream>
#include <cerrno>
#include "Font.h"
#include "Frame.h"

using namespace std;

extern Frame frame;

Font::Font() : w(384), h(384) {
	pixels = new byte[w * h * 3];

	const char * cmd = 
		"ffmpeg           "
		"-i arial50.bmp   "
		"-f rawvideo      "
		"-pix_fmt rgb24   "
		"-                ";

#ifdef _WIN32
	FILE * pipe = _popen(cmd, "rb");
#else
	FILE * pipe = popen(cmd, "r");
#endif
	if (pipe == 0) {
		std::cout << "error: " << strerror(errno) << std::endl;
		exit(1);
	}
	fread(pixels, 3, w * h, pipe);

	fflush(pipe);
#ifdef _WIN32
	_pclose(pipe);
#else
	pclose(pipe);
#endif
}

void Font::draw(const string & text, double x, double y) const {
/*
	for (int i = 0; i < text.size(); ++i) {
		char c = text[i];
		glyphs[c].draw(x, y);
	}
*/

	int fx = 160;
	int fy = 56;
	int fw = 36;
	int fh = 40;
	for (int i = fx; i < fx + fw; ++i) {
		for (int j = fy; j < fy + fh; ++j) {
			byte r = pixels[j * w * 3 + i * 3 + 0];
			byte g = pixels[j * w * 3 + i * 3 + 1];
			byte b = pixels[j * w * 3 + i * 3 + 2];
			frame.setPixel(x + i, y + j, r, g, b);
		}
	}
}

