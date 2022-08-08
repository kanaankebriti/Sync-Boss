#include "Sync_Boss.h"

#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif	// _DEBUG

#ifdef _DEBUG
#pragma comment(lib, "SDL2d.lib")
#else
#pragma comment(lib, "SDL2.lib")
#endif
#pragma comment(lib, "SDL2_image.lib")

#ifdef _WIN32
int APIENTRY wWinMain
(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR	lpCmdLine,
	_In_ int nCmdShow
)
#else
int main()
#endif // _WIN32
{
	#ifdef _WIN32
	// not used parameters!
	UNREFERENCED_PARAMETER(hInstance);
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	UNREFERENCED_PARAMETER(nCmdShow);
	#endif // _WIN32

	SDL_Renderer* renderer;
	SDL_Window* main_window;
	SDL_Event event;
	bool game_is_still_running = true;
	bool key_down = false;
	const Uint8* keyboard_state = SDL_GetKeyboardState(NULL);

	// init SDL2
	if (!init_sdl(&renderer, &main_window))
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Failed to init SDL2.dll", main_window);
		return EXIT_FAILURE;
	}

	// populate textures
	SDL_Texture* texture_bank[3];
	texture_bank[0] = IMG_LoadTexture(renderer, "c1.svg");
	texture_bank[1] = IMG_LoadTexture(renderer, "c2.svg");
	//texture_bank[2] = IMG_LoadTexture(renderer, "c3.svg");

	// init cups
	cup cup[2];
	cup[0].texture_index = 0;
	cup[1].texture_index = 1;
	//cup[2].texture_index = 2;
	cup[0].slot = 0;
	cup[1].slot = 1;
	//cup[2].slot = 2;
	cup[0].is_animating = false;
	cup[1].is_animating = false;
	//cup[2].is_animating = false;
	cup[0].rect.w = 50; cup[0].rect.h = 50; cup[0].rect.x = TWO_COL_SLOT_0_X; cup[0].rect.y = 480;
	cup[1].rect.w = 50; cup[1].rect.h = 50; cup[1].rect.x = TWO_COL_SLOT_1_X; cup[1].rect.y = 480;
	//cup[2].rect.w = 50; cup[2].rect.h = 50; cup[2].rect.x = THREE_COL_SLOT_2_X; cup[2].rect.y = 400;

	// main events loop
	while (game_is_still_running)
	{
		// handle events
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_KEYDOWN:
			// ignore long press
			if (key_down)
				break;

			// key combos
			if (keyboard_state[SDL_SCANCODE_1] && keyboard_state[SDL_SCANCODE_2])
			{
				swap_cups(&cup[0], &cup[1]);
				key_down = true;
			}
			else if (keyboard_state[SDL_SCANCODE_1] && keyboard_state[SDL_SCANCODE_3])
			{
				swap_cups(&cup[0], &cup[2]);
				key_down = true;
			}
			else if (keyboard_state[SDL_SCANCODE_2] && keyboard_state[SDL_SCANCODE_3])
			{
				swap_cups(&cup[1], &cup[2]);
				key_down = true;
			}
			break;

		case SDL_KEYUP:
			// ignore long press
			key_down = false;
			break;

		case SDL_QUIT:
			game_is_still_running = false;
		}

		// render
		render_clear(renderer, 40, 190, 100);
		render_cups(renderer, cup, 2, texture_bank);
	}

	// free up memory
	for (unsigned short i = 0; i < 2; i++)
	{
		SDL_DestroyTexture(texture_bank[i]);
		texture_bank[i] = NULL;
	}
	free(texture_bank);
	kill_sdl(renderer, main_window);

	#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
	#endif	//_DEBUG

	return EXIT_SUCCESS;
}
