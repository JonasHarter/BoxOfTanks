#pragma once

namespace Globals {
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	const int CELL_SIZE = 32;
}

struct Vector2 {
	double x, y;

	Vector2() :
		x(0), y(0)
	{}

	Vector2(double x, double y) :
		x(x), y(y)
	{}
};