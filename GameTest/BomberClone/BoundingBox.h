#pragma once
#include "PrimitiveShape.h"

enum Axis
{
	Horizontal,
	Vertical
};

class BoundingBox 
{
public:
	BoundingBox();
	BoundingBox(PrimitiveShape* newShape);
	~BoundingBox();

	void SetPosition(Position newPosition);
	void RenderDebug();
	Position center;
	Position extents;

private:
	void CreateBox();
	Vertex* GetFurthestVert(Axis a);
	Vertex* FindFurthestVertInDirection(bool isVert, bool isGreaterThan);

	PrimitiveShape* shape;

	

};