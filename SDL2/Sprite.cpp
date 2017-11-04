#include <iostream>

#include "Sprite.h"
#include "Graphics.h"
#include "Direction.h"

Sprite::Sprite(Graphics &graphics, const std::string &filePath, int frames, int x, int y)
{
	_texture = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filePath));
	if (_texture == NULL) {
		std::cout << "ERROR: Cannot load file: " << filePath;
	}
	for (int i = 0; i < frames; i++) {
		SDL_Rect newRect = { (i + x) * Globals::CELL_SIZE, y * Globals::CELL_SIZE, Globals::CELL_SIZE, Globals::CELL_SIZE };
		_rectangles.push_back(newRect);
	}
	_frameIndex = 0;
	_timeToUpdate = 0;
	_timeElapsed = 0;
}

bool Sprite::update(int elapsedTime)
{
	// Don't update nonanimated sprites
	if (_rectangles.size() <= 1)
	{
		return false;
	}
	_timeElapsed += elapsedTime;
	if (_timeElapsed > _timeToUpdate)
	{
		_timeElapsed -= _timeToUpdate;
		if (_frameIndex < _rectangles.size() - 1)
		{
			_frameIndex++;
			return false;
		}
		else
		{
			_frameIndex = 0;
			return true;
		}
	}
	return false;
}

void Sprite::draw(Graphics & graphics, double x, double y, Direction* rotation)
{
	x *= Globals::CELL_SIZE;
	y *= Globals::CELL_SIZE;
	int w = _rectangles[_frameIndex].w;
	int h = _rectangles[_frameIndex].h;
	SDL_Rect destinationRectangle = { x - w/2, y - h/2, w, h };
	graphics.blitSurface(_texture, &_rectangles[_frameIndex], &destinationRectangle, rotation);
}

void Sprite::resetAnimation()
{
	_frameIndex = 0;
}
