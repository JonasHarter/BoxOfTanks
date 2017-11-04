#pragma once

#include <vector>
#include <SDL.h>

#include "Globals.h"
#include "Direction.h"

class Graphics;

// A sprite, possibly animated
class Sprite
{
	public:

		Sprite(Graphics &graphics, const std::string &filePath, int frames, int x, int y);

		// Returns true if the animation is done
		bool update(int elapsedTime);

		void draw(Graphics &graphics, double x, double y, Direction* rotation);

		void resetAnimation();

	protected:
		// The source rect on _textures
		std::vector<SDL_Rect> _rectangles;
		// The source texture
		SDL_Texture* _texture;
		int _frameIndex;
		// Time that needs to pass, before next animation stage
		int _timeToUpdate;
		// Keps track of time for this object
		int _timeElapsed;
};

