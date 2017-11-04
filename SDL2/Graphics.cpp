#include "Graphics.h"
#include "Direction.h"
#include "Tank.h"

Graphics::Graphics() {
	SDL_CreateWindowAndRenderer(Globals::SCREEN_WIDTH, Globals::SCREEN_HEIGHT, 0, &_window, &_renderer);
	SDL_SetWindowTitle(_window, "Box of Tanks");
}


Graphics::~Graphics() {
	SDL_DestroyWindow(_window);
}

SDL_Surface* Graphics::loadImage(const std::string &filepath)
{
	if (_spriteSheets.count(filepath) == 0) {
		_spriteSheets[filepath] = IMG_Load(filepath.c_str());
	}
	return _spriteSheets[filepath];
}

void Graphics::blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle, Direction* direction)
{
	double angle = 0;
	angle = direction->get();
	// Necessary
	angle += 90.0;
	SDL_RenderCopyEx(_renderer, source, sourceRectangle, destinationRectangle, angle, NULL, SDL_FLIP_NONE);
}

void Graphics::flip()
{
	SDL_RenderPresent(_renderer);
}

void Graphics::clear()
{
	SDL_SetRenderDrawColor(_renderer, 0, 0, 255, 255);
	SDL_RenderClear(_renderer);
}

SDL_Renderer* Graphics::getRenderer() const
{
	return _renderer;
}
