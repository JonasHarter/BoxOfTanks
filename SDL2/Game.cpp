#include <SDL.h>
#include "Game.h"
#include "Graphics.h"
#include "Input.h"
#include "Tank.h"
#include "Cell.h"
#include "Terrain.h"

namespace {
	const int FPS = 60;
	const int MAX_FRAME_TIME = 5 * 1000 / FPS; //1000?
}

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	gameloop();
}

Game::~Game()
{
}

/* Gets called ever frame */
void Game::gameloop()
{
	Graphics graphics;
	Input input;
	SDL_Event event;

	Cell::initializeSpritePacks(graphics);
	_player1 = new Tank(graphics, Vector2(1, 1));
	_terrain = new Terrain();

	int LAST_UPDATE_TIME_MS = SDL_GetTicks();
	// Each iteration is a frame
	while (true) {
		input.beginNewFrame();
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN) {
				if (event.key.repeat == 0) {
					input.keyDownEvent(event);
				}
			}
			else if (event.type == SDL_KEYUP) {
				input.keyUpEvent(event);
			}
			else if (event.type == SDL_QUIT) {
				return;
			}
		}

		const int CURRENT_TIME_MS = SDL_GetTicks();
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME_MS;
		int min = (ELAPSED_TIME_MS < MAX_FRAME_TIME) ? ELAPSED_TIME_MS : MAX_FRAME_TIME;
		update(min, input);
		LAST_UPDATE_TIME_MS = CURRENT_TIME_MS;

		draw(graphics);
	}
}

void Game::draw(Graphics &graphics)
{
	graphics.clear();
	
	_terrain->draw(graphics);
	_player1->draw(graphics);

	graphics.flip();
}

void Game::update(int elapsedTime, Input input)
{
	_terrain->update(elapsedTime);
	_player1->update(elapsedTime, input);
}