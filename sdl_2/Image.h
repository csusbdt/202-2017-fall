#pragma once

#include "SDL.h"

typedef unsigned char byte;

class Image {
public:
	Image(SDL_Renderer * renderer);
	~Image();
	void load(const char * filename);
	void draw() const;
	int getWidth()  const { return w; }
	int getHeight() const { return h; }

	int x;
	int y;
	double scale;

private:
	SDL_Renderer * renderer;
	SDL_Texture  * texture;
	int w;
	int h;
};

