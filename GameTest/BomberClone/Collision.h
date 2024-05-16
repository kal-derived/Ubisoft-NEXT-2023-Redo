#pragma once
#include "BoundingBox.h"

class Collision {
public:
	Collision();
	~Collision();

	static bool Collision::isTouching(BoundingBox* a, BoundingBox* b)
	{
		bool horizCheck = (a->center.x <= b->center.x) ? (a->center.x + a->extents.x) >= (b->center.x - b->extents.x) : 
														 (a->center.x - a->extents.x) <= (b->center.x + b->extents.x);

		bool vertCheck = (a->center.y <= b->center.y) ? (a->center.y + a->extents.y) >= (b->center.y - b->extents.y) : 
														(a->center.y - a->extents.y) <= (b->center.y + b->extents.y);

		return horizCheck && vertCheck;
	}
};