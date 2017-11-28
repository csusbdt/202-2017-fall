#include <stdio.h>
#include <cstring>
#include <iostream>
#include <cerrno>
#include "Font.h"
#include "Frame.h"
#include "Glyph.h"

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
	for (int i = 0; i < text.size(); ++i) {
		Glyph g(text[i]);
		for (int i = 0; i < g.fw; ++i) {
			for (int j = 0; j < g.fh; ++j) {
				byte red   = pixels[(g.fy + j) * w * 3 + (g.fx + i) * 3 + 0];
				byte green = pixels[(g.fy + j) * w * 3 + (g.fx + i) * 3 + 1];
				byte blue  = pixels[(g.fy + j) * w * 3 + (g.fx + i) * 3 + 2];
				frame.blendPixel(
					x + g.xOffset + i, 
					y + g.yOffset + j, 
					red, 
					green, 
					blue,
					128
				);
			}
		}
		x += g.xAdvance;
	}
}

