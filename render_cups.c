#include "Sync_Boss.h"

// in: renderer
// in: cups array
// in: number of cups
// in: array of textures
void render_cups
(
	SDL_Renderer* renderer,
	cup* cup,
	unsigned char num_of_cups,
	SDL_Texture* texture_bank[]
)
{
	for (unsigned char i = 0; i < num_of_cups; i++)
	{
		// animating the cups based on the number of columns
		if(cup[i].is_animating)
			switch (cup[i].anim_direction)
			{
				// animating to left
			case ANIM_MV_L:
				switch(num_of_cups)
				{
				case 2:
					if (cup[i].rect.x <= TWO_COL_SLOT_0_X)
					{
						cup[i].rect.x = TWO_COL_SLOT_0_X;
						cup[i].is_animating = false;
					}
					break;
				case 3:
					break;
				case 4:
					break;
				}
				cup[i].rect.x -= 20;
				break;
				// animating to right
			case ANIM_MV_R:
				switch (num_of_cups)
				{
				case 2:
					if (cup[i].rect.x >= TWO_COL_SLOT_1_X)
					{
						cup[i].rect.x = TWO_COL_SLOT_1_X;
						cup[i].is_animating = false;
					}
					break;
				case 3:
					break;
				case 4:
					break;
				}
				cup[i].rect.x += 20;
				break;
			}
		// copy all cups to display
		SDL_RenderCopy
		(
			renderer,
			texture_bank[cup[i].texture_index],
			NULL,
			&cup[i].rect
		);
	}

	SDL_RenderPresent(renderer);
}
