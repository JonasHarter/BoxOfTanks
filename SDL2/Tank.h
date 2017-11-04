#pragma once

#include "Drawable.h"

class Input;
class Direction;

class Tank : public Drawable
{
	public:
		Tank(Graphics &graphics, Vector2 pos);

		~Tank();

		void update(int elapsedTime, Input input);
	private:

		static double forwardSpeed() { return 0.01; };
		static double backwardSpeed() { return 0.005; };
		static double rotationSpeed() { return 0.02; };
};

