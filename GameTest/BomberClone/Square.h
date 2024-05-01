#pragma once

#include "BomberClone\PrimitiveShape.h"
#include "BomberClone\DrawUtils.h"
#include "RenderableItems.h"
class Square : public PrimitiveShape
{
public:
	Square();
	Square(Position position, float radius);
	Square(Position position, float radius, Color c);
	~Square();

private:
	void CreateSquare(float radius);
};

