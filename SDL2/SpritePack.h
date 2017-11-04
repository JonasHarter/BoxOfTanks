#pragma once

#include <map>
#include <memory>
#include <optional>

#include "Gobject.h"
#include "Sprite.h"
#include "Direction.h"
#include "AnimationType.h"

// Abstracts a sprite in different animation states
class SpritePack
{
	public:

		void draw(Graphics & graphics, double x, double y);

		void update(int elapsedTime);

		void addSprite(AnimationType animationType, Sprite sprite);

		void setAnimation(AnimationType animationType, bool once = false);

		Direction* _rotation = new Direction();

	private:

		AnimationType _currentAnimation;
		std::optional<AnimationType> _currentAnimationOnce;

		std::map<AnimationType, Sprite> _spriteMap = std::map<AnimationType, Sprite>();;
};

