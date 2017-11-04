#include "Blocked.h"

Blocked::Blocked(Vector2 pos)
{
	_pos = pos;
	_sprites = Cell::blocked;
}