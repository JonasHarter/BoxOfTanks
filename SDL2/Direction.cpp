#include "Direction.h"
#include "Math.h"

Direction::Direction()
{
	_direction = 270.0;
}

double Direction::get()
{
	return _direction;
}

void Direction::add(double d)
{
	_direction += d;
	_direction = fmod(_direction, 360.0);
}

void Direction::sub(double d)
{
	_direction -= d;
	if (_direction < 0)
	{
		_direction += 360.0;
	}
	_direction = fmod(_direction, 360.0);
}

void Direction::set(double d)
{
	_direction = 270.0 - 90.0;
	add(d);
}
