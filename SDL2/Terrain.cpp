#include "Terrain.h"
#include "Cell.h"
#include "Base.h"
#include "Blocked.h"



Terrain::Terrain()
{
	_terrain.push_back(Blocked(Vector2(0, 0)));
	_terrain.push_back(Blocked(Vector2(0, 1)));
	_terrain.push_back(Blocked(Vector2(0, 2)));
	_terrain.push_back(Blocked(Vector2(1, 0)));
	_terrain.push_back(Blocked(Vector2(2, 0)));
	_terrain.push_back(Base(Vector2(1, 1)));
	_terrain.push_back(Base(Vector2(1, 2)));
	_terrain.push_back(Base(Vector2(2, 1)));
	_terrain.push_back(Base(Vector2(2, 2)));
}


Terrain::~Terrain()
{
}

void Terrain::draw(Graphics& graphics)
{
	for (Cell& c : _terrain)
	{
		c.draw(graphics);
	}
}

void Terrain::update(int elapsedTime)
{
	for (Cell& c : _terrain)
	{
		c.update(elapsedTime);
	}
}
