#include "Sync_Boss.h"

// in: cup_a object
// in: cup_b object
// in: number of cups/slots
void swap_cups
(
	cup* cup_a,
	cup* cup_b,
	unsigned char num_of_slots
)
{
	// start animations
	cup_a->is_animating = true;
	cup_b->is_animating = true;

	// assign directions
	switch (num_of_slots)
	{
		/* 2 slot game */
	case 2:
		switch (cup_a->slot)
		{
		case 0:
			cup_a->anim_direction = ANIM_MV_R;
			cup_b->anim_direction = ANIM_MV_L;
			break;
		case 1:
			cup_a->anim_direction = ANIM_MV_L;
			cup_b->anim_direction = ANIM_MV_R;
			break;
		}
		break;
		/* 3 slot game */
	case 3:
		break;
		/* 4 slot game */
	case 4:
		break;
	}

	// swap slots
	int temp_slot;
	temp_slot = cup_a->slot;
	cup_a->slot = cup_b->slot;
	cup_b->slot = temp_slot;
}
