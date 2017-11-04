#pragma once

#include <map>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

class Direction;

class Graphics {
public:
	Graphics();
	~Graphics();
	/*
	Loads an image into the _spriteheets map if it doesn't already exist
	*/
	SDL_Surface* loadImage(const std::string &filepath);

	/*
	Draws a texture
	*/
	void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle, Direction* direction);

	/*
	Renders everything on the screen
	*/
	void flip();

	/*
	Clears the screen
	*/
	void clear();

	SDL_Renderer* getRenderer() const;
private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;

	std::map<std::string, SDL_Surface*> _spriteSheets;
};