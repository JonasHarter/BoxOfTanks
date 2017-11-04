#pragma once
class Direction
{
	public:
		Direction();
		double get();
		void add(double d);
		void sub(double d);
		void set(double d);
	private:
		double _direction;
};

