#include "SDL.h"
#include "Engine.h"

extern SDL_Renderer * renderer;
std::vector<Object *> Engine::objects;

void Engine::addObject(Object * object) {
	objects.push_back(object);
}

void Engine::removeObject(Object * object) {
	int s = -1;
	for (int i = 0; i < objects.size(); ++i) {
		if (objects[i] == object) {
			s = i;
			break;
		}
	}
	for (int i = s; i < objects.size() - 1; ++i) {
		objects[i] = objects[i + 1];
	}
	objects.pop_back();
}

int Engine::run() {
	Uint32 previous_millis = SDL_GetTicks();
	while (true) {
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				SDL_Quit();
				return 0;
			}
		}
		Uint32 millis = SDL_GetTicks();
		double dt =  (millis - previous_millis) / 1000.0;
		if (dt > 1.0 / 60) {
			// Clear canvas.
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			SDL_RenderClear(renderer);

			// Update objects.
			for (int i = 0; i < objects.size(); ++i) {
				objects[i]->update(dt);
			}

			// Draw objects onto canvas.
			for (int i = 0; i < objects.size(); ++i) {
				objects[i]->draw();
			}

			// Render canvas.
			SDL_RenderPresent(renderer);
			previous_millis = millis;
		}
	}
	return 0;
}

