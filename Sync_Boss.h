#pragma once
#define _CRT_SECURE_NO_WARNINGS

#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif	// _DEBUG

#include "resource.h"

#include <Windows.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define WIN_TITLE_STR "Sync Boss"
#define WIN_WIDTH 1280
#define WIN_HEIGHT 720
#define TWO_COL_SLOT_0_X 320
#define TWO_COL_SLOT_1_X 960
#define THREE_COL_SLOT_0_X 120
#define THREE_COL_SLOT_1_X 360
#define THREE_COL_SLOT_2_X 480
#define FOUR_COL_SLOT_0_X 90
#define FOUR_COL_SLOT_1_X 270
#define FOUR_COL_SLOT_2_X 450
#define FOUR_COL_SLOT_3_X 630
#define ANIM_MV_R 0
#define ANIM_MV_L 1

struct cup
{
	unsigned char texture_index : 3;
	unsigned char slot : 3;
	unsigned char is_animating : 1;
	unsigned char anim_direction : 1;
	SDL_Rect rect;
}typedef cup;

bool init_sdl(SDL_Renderer** renderer, SDL_Window** window);
void kill_sdl(SDL_Renderer* renderer, SDL_Window* main_window);
void render_clear(SDL_Renderer* renderer, unsigned char r, unsigned char b, unsigned char g);
void render_cups(SDL_Renderer* renderer, cup* cup, unsigned char num_of_cups, SDL_Texture* texture_bank[]);
void swap_cups(cup* cup_a, cup* cup_b);
