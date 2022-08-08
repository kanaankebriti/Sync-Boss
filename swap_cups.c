#include "Sync_Boss.h"

void swap_cups(cup* cup_a, cup* cup_b)
{
	// assign directions and start animations
	cup_a->is_animating = true;
	cup_b->is_animating = true;
	cup_a->anim_direction = ANIM_MV_R;
	cup_b->anim_direction = ANIM_MV_L;
}
