#include "Sync_Boss.h"

// in: renderer
// in: cups array
// in: number of cups/slots
// in: array of textures
void render_cups
(
	SDL_Renderer* renderer,
	cup* cup,
	unsigned char num_of_slots,
	SDL_Texture* texture_bank[]
)
{
	for (unsigned char i = 0; i < num_of_slots; i++)
	{
		// animating the cups based on the number of columns
		if (cup[i].is_animating)
			switch (cup[i].anim_direction)
			{
				// animating to left
			case ANIM_MV_L:
				switch (num_of_slots)
				{
					/* 2 slot game */
				case 2:
					// go from slot 1 to slot 0
					if (cup[i].rect.x <= TWO_COL_SLOT_0_X)
					{
						cup[i].rect.x = TWO_COL_SLOT_0_X;
						cup[i].is_animating = false;
					}
					break;
					/* 3 slot game */
				case 3:
					break;
					/* 4 slot game */
				case 4:
					break;
				}
				cup[i].rect.x -= SWAP_X_SPEED;
				break;
				// animating to right
			case ANIM_MV_R:
				switch (num_of_slots)
				{
					/* 2 slot game */
				case 2:
					// go from slot 0 to slot 1
					if (cup[i].rect.x >= TWO_COL_SLOT_1_X)
					{
						cup[i].rect.x = TWO_COL_SLOT_1_X;
						cup[i].is_animating = false;
					}
					break;
					/* 3 slot game */
				case 3:
					break;
					/* 4 slot game */
				case 4:
					break;
				}
				cup[i].rect.x += SWAP_X_SPEED;
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
