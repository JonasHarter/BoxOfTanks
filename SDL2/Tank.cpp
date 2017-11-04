#include "Input.h"
#include "Tank.h"
#include "Direction.h"
#include <memory>
#include <vector>

Tank::Tank(Graphics &graphics, Vector2 pos)
{
	_pos = pos;

	SpritePack spChassis = SpritePack();
	Sprite s = Sprite(graphics, "./Sprites/Tank.png", 1, 0, 0);
	spChassis.addSprite(AnimationType::stand, s);
	Sprite s2 = Sprite(graphics, "./Sprites/Tank.png", 2, 0, 0);
	spChassis.addSprite(AnimationType::move, s2);
	spChassis.setAnimation(AnimationType::stand);

	SpritePack spTurrent = SpritePack();
	Sprite s3 = Sprite(graphics, "./Sprites/Tank.png", 1, 0, 1);
	spTurrent.addSprite(AnimationType::stand, s3);
	spTurrent.setAnimation(AnimationType::stand);

	_sprites = std::make_shared<std::vector<SpritePack>>(std::vector<SpritePack>());
	_sprites->push_back(spChassis);
	_sprites->push_back(spTurrent);
}


Tank::~Tank()
{ }

void Tank::update(int elapsedTime, Input input)
{
	// Chassis movement
	Direction * chassisRotation = _sprites->at(0)._rotation;

	double c = elapsedTime;
	if (input.isKeyHeld(SDL_SCANCODE_UP) || input.isKeyHeld(SDL_SCANCODE_W))
	{
		c *= forwardSpeed();
		_sprites->at(0).setAnimation(AnimationType::move);
	}
	else if (input.isKeyHeld(SDL_SCANCODE_DOWN) || input.isKeyHeld(SDL_SCANCODE_S))
	{
		c *= -1 * backwardSpeed();
		_sprites->at(0).setAnimation(AnimationType::move);
	}
	else
	{
		_sprites->at(0).setAnimation(AnimationType::stand);
		c = 0;
	}
	_pos.x += c * cos(chassisRotation->get() * M_PI / 180);
	_pos.y += c * sin(chassisRotation->get() * M_PI / 180);

	if (input.isKeyHeld(SDL_SCANCODE_RIGHT) || input.isKeyHeld(SDL_SCANCODE_D))
	{
		chassisRotation->add(rotationSpeed());
	}
	else if (input.isKeyHeld(SDL_SCANCODE_LEFT) || input.isKeyHeld(SDL_SCANCODE_A))
	{
		chassisRotation->sub(rotationSpeed());
	}

	// Turrent movement
	Direction * turrentRotation = _sprites->at(1)._rotation;
	int * x = new int();
	int * y = new int();
	SDL_GetMouseState(x, y);
	int yy = _pos.y * Globals::CELL_SIZE;
	int xx = _pos.x * Globals::CELL_SIZE;
	float angle = atan2(yy - *y, xx - *x);
	turrentRotation->set(angle * 180 / M_PI);
	delete x;
	delete y;
}
