#pragma once


#include <map>
#include <string>
#include <vector>
#include <memory>

#include "Gobject.h"
#include "Drawable.h"
#include "SpritePack.h"
#include "Sprite.h"

class Cell : public Drawable
{
	public:
		static void initializeSpritePacks(Graphics &graphics);
	protected:
		static std::shared_ptr<std::vector<SpritePack>> base;
		static std::shared_ptr<std::vector<SpritePack>> blocked;
};

