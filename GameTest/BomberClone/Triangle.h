#pragma once
#include "BomberClone\PrimitiveShape.h"
#include "BomberClone\DrawUtils.h"
#include "RenderableItems.h"
class Triangle : public PrimitiveShape
{
public:
	Triangle();
	Triangle(Position position, float height);
	Triangle(Position position, float height, Color c);
	~Triangle();

private:
	void CreateTriangle(float height);
};

