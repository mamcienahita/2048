#pragma once

#include <memory>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "Board.h"
#include <string>
#include <utility>

struct NumTexture {
	NumTexture(void) {
		texture = nullptr;
	}
	NumTexture(SDL_Renderer* renderer, SDL_Surface* surface) {
		w = surface->w;
		h = surface->h;
		texture=SDL_CreateTextureFromSurface(renderer, surface);
	}
	~NumTexture() {
		//SDL_DestroyTexture(texture);//to fix
	}
	SDL_Texture* texture;
	int w;
	int h;
};

class BlockDrawer
{
public:
	BlockDrawer(const Board& board_, SDL_Renderer* renderer_);
	~BlockDrawer();
	void test_draw_nums(void); //TO DELETE
private:
	const Board& board;
	SDL_Renderer* renderer;
	std::unique_ptr<SDL_Rect> rect;
	const std::array<NumTexture, 10> nums;
	const int blockSize = 70;
	const int spaceBetweenBlocks = 10;
	const int topOffset = 145;
	const int leftOffset = 25;
	void set_rect(int x, int y, int w, int h);
	const std::array<NumTexture, 10> initialize_nums(SDL_Renderer* renderer_);
};

