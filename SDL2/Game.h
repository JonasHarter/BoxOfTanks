#pragma once

class Graphics;
class Tank;
class Input;
class Cell;
class Terrain;

class Game {
public:
	Game();
	~Game();
private:
	void gameloop();
	void draw(Graphics &graphics);
	void update(int elapsedTime, Input input);

	Tank* _player1;
	Terrain* _terrain;
};