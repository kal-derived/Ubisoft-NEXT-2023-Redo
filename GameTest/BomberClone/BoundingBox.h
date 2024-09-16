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
	PrimitiveShape* GetShape();
	Position center;
	Position extents;

	bool ContainsPoint(Position p);
private:
	void CreateBox();
	Vertex* GetFurthestVert(Axis a);
	Vertex* FindFurthestVertInDirection(bool isVert, bool isGreaterThan);

	PrimitiveShape* shape;

	

};