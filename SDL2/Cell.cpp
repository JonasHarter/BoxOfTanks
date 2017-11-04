#include "Cell.h"

std::shared_ptr<std::vector<SpritePack>> Cell::base;
std::shared_ptr<std::vector<SpritePack>> Cell::blocked;

void Cell::initializeSpritePacks(Graphics &graphics)
{
	std::string terrain = "./Sprites/Terrain.png";
	{
		SpritePack sp = SpritePack();
		Sprite s = Sprite(graphics, terrain, 1, 0, 0);
		sp.addSprite(AnimationType::stand, s);
		sp.setAnimation(AnimationType::stand);
		base = std::make_shared<std::vector<SpritePack>>(std::vector<SpritePack>());
		base->push_back(sp);
	}
	{
		SpritePack sp = SpritePack();
		Sprite s = Sprite(graphics, terrain, 1, 1, 0);
		sp.addSprite(AnimationType::stand, s);
		sp.setAnimation(AnimationType::stand);
		blocked = std::make_shared<std::vector<SpritePack>>(std::vector<SpritePack>());
		blocked->push_back(sp);
	}
}
