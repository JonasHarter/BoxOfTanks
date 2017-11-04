#include "Drawable.h"

void Drawable::update(int elapsedTime)
{
	for (int i = 0; i < _sprites->size(); i++)
	{
		_sprites->at(i).update(elapsedTime);
	}
}

void Drawable::draw(Graphics & graphics)
{
	for (int i = 0; i < _sprites->size(); i++)
	{
		_sprites->at(i).draw(graphics, _pos.x, _pos.y);
	}
}