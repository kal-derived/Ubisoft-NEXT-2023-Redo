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

	static void Collision::ResolveCollision(BoundingBox* a, BoundingBox* b)
	{
		float horizDiff = a->center.x - b->center.x;
		float vertDiff = a->center.y - b->center.y;
		float xPenetration = (a->center.x <= b->center.x) ? (b->center.x - b->extents.x) - (a->center.x + a->extents.x) :
															(b->center.x + b->extents.x) - (a->center.x - a->extents.x);

		float yPenetration = (a->center.y <= b->center.y) ? (b->center.y - b->extents.y) - (a->center.y + a->extents.y) :
															(b->center.y + b->extents.y) - (a->center.y - a->extents.y);

		//Horizontal resolving
		if (abs(horizDiff) > 0 && abs(horizDiff) > abs(vertDiff))
		{
			//Left check
			if (horizDiff < 0)
			{
				a->SetPosition({ a->center.x - abs(xPenetration), a->center.y });
			}
			//Right check
			else
			{
				a->SetPosition({ a->center.x + abs(xPenetration), a->center.y });
			}
		}
		//Vertical Resolving
		if (abs(vertDiff) > 0 && abs(vertDiff) > abs(horizDiff))
		{
			//Up check
			if (vertDiff < 0)
			{
				a->SetPosition({ a->center.x, a->center.y - abs(yPenetration) });
			}
			//Down check
			else
			{
				a->SetPosition({ a->center.x, a->center.y + abs(yPenetration) });
			}
		}
	}
};