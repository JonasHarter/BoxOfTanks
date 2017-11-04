#pragma once

#include <vector>

#include "Drawable.h"

class Cell;

class Terrain : public Drawable
{
public:
	Terrain();
	~Terrain();
	void draw(Graphics& graphics);
	void update(int elapsedTime);
	std::vector<Cell> _terrain = std::vector<Cell>();
};

