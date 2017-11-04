#include <iostream>

#include "SpritePack.h"

void SpritePack::addSprite(AnimationType animationType, Sprite sprite)
{
	_spriteMap.emplace(animationType, sprite);
}

void SpritePack::setAnimation(AnimationType animationType, bool once)
{
	if (_spriteMap.count(animationType) != 1)
	{
		std::cout << "ERROR: Unknown animation type";
		return;
	}
	if (!once)
	{
		_currentAnimation = animationType;
	}
	else
	{
		_currentAnimationOnce.emplace(animationType);
	}
}

void SpritePack::draw(Graphics & graphics, double x, double y)
{
	if (_currentAnimationOnce.has_value())
	{
		_spriteMap.at(_currentAnimationOnce.value()).draw(graphics, x, y, _rotation);
	}
	else
	{
		_spriteMap.at(_currentAnimation).draw(graphics, x, y, _rotation);
	}
}

void SpritePack::update(int elapsedTime)
{
	if (_currentAnimationOnce.has_value())
	{
		bool animationDone = _spriteMap.at(_currentAnimationOnce.value()).update(elapsedTime);
		if (animationDone)
		{
			_currentAnimationOnce = std::optional<AnimationType>();
		}
	}
	else
	{
		_spriteMap.at(_currentAnimation).update(elapsedTime);
	}
}
