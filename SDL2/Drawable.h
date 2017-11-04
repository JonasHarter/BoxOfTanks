#pragma once

#include <map>
#include <string>
#include <vector>
#include <memory>

#include "Gobject.h"
#include "Sprite.h"
#include "SpritePack.h"

class Drawable : public Gobject
{
	public:

		void update(int elapsedTime);

		void draw(Graphics &graphics);

	protected:
		Vector2 _pos;

		// The sprites the object is build of
		std::shared_ptr<std::vector<SpritePack>> _sprites;

};