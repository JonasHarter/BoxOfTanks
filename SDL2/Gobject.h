#pragma once
#include <SDL.h>
#include "Sprite.h"

class Graphics;
class Direction;

/* Base Object of the game */
class Gobject
{
	public:
		virtual ~Gobject() {};
		virtual void update(int elapsedTime) = 0;
};