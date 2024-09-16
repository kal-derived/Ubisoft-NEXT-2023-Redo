#include "stdafx.h"
#include "BoundingBox.h"

BoundingBox::BoundingBox() 
{
	shape = new PrimitiveShape();
	center = { APP_INIT_WINDOW_WIDTH / 2, APP_INIT_WINDOW_HEIGHT / 2 };
	extents = {60, 60};
}

BoundingBox::BoundingBox(PrimitiveShape* newShape)
{
	shape = newShape;
	center = shape->GetCenter();
	extents.x = abs(GetFurthestVert(Horizontal)->vertPos.x - center.x);
	extents.y = abs(GetFurthestVert(Vertical)->vertPos.y - center.y);
}

BoundingBox::~BoundingBox()
{
}

bool BoundingBox::ContainsPoint(Position p)
{
	//Check horizontal bounds
	if (p.x <= center.x + extents.x && p.x >= center.x - extents.x)
	{
		//Check vertical bounds
		if (p.y <= center.y + extents.y && p.y >= center.y -extents.y)
		{
			return true;
		}
	}
	return false;
}

void BoundingBox::CreateBox()
{

}

/// <summary>
/// Finds and returns the vertex furthest along an axis
/// </summary>
/// <param name="axis">The axis in question to compare values of vertex coordinates along</param>
/// <returns></returns>
Vertex* BoundingBox::GetFurthestVert(Axis axis) 
{
	switch (axis)
	{
		case Horizontal:
		{
			Vertex* left = FindFurthestVertInDirection(false, false);
			Vertex* right = FindFurthestVertInDirection(false, true);
			return  abs(left->vertPos.x) > abs(right->vertPos.x) ? left : right;
		}
		case Vertical: {
			Vertex* up = FindFurthestVertInDirection(true, true);
			Vertex* down = FindFurthestVertInDirection(true, false);
			return abs(down->vertPos.y) > abs(up->vertPos.y) ? down : up;
		}
		default:
			OutputDebugString(L"No vertex found");
			break;
	}
}
/// <summary>
/// Finds and returns the vertex with the greatest absolute x or y value in a certain direction
/// </summary>
/// <param name="isVert"> True checks up and down, False checks left and right</param>
/// <param name="isGreaterThan"> True checks for greater than positive, False checks for less than negative</param>
/// <returns></returns>
Vertex* BoundingBox::FindFurthestVertInDirection(bool isVert, bool isGreaterThan)
{
	std::vector<Vertex*> verts = shape->GetVerts();
	Vertex* record = NULL;

	for (int i = 0; i < verts.size(); i++)
	{
		if (isVert == true) // Up or Down check
		{
			if (isGreaterThan == true) // Up check
			{
				if (record == NULL || verts[i]->vertPos.y - center.y > record->vertPos.y -center.y)
				{
					record = verts[i];
				}
			}
			else // Down check
			{
				if (record == NULL || center.y - verts[i]->vertPos.y < center.y - record->vertPos.y)
				{
					record = verts[i];
				}
			}
		}
		else // Left or Right check
		{
			if (isGreaterThan == true) // Right check
			{
				if (record == NULL || verts[i]->vertPos.x - center.x > record->vertPos.x - center.x)
				{
					record = verts[i];
				}
			}
			else // Left check
			{
				if (record == NULL || center.x - verts[i]->vertPos.x < center.x - record->vertPos.x)
				{
					record = verts[i];
				}
			}
		}
	}
	return record;
}

void BoundingBox::SetPosition(Position newPosition)
{
	center = newPosition;
	shape->SetCenter(newPosition);
}

void BoundingBox::RenderDebug()
{
	Position leftUp, rightUp, leftDown, rightDown;
	leftUp = {center.x - extents.x, center.y + extents.y};
	rightUp = { center.x + extents.x, center.y + extents.y };
	rightDown = { center.x + extents.x, center.y - extents.y };
	leftDown = { center.x - extents.x, center.y - extents.y };
	App::DrawLine(leftUp.x,leftUp.y, rightUp.x, rightUp.y, 0.3, 0.3, 1);
	App::DrawLine(rightUp.x, rightUp.y, rightDown.x, rightDown.y, 0.3, 0.3, 1);
	App::DrawLine(rightDown.x, rightDown.y, leftDown.x, leftDown.y, 0.3, 0.3, 1);
	App::DrawLine(leftDown.x, leftDown.y, leftUp.x, leftUp.y , 0.3, 0.3, 1);
}

PrimitiveShape* BoundingBox::GetShape()
{
	return shape;
}
