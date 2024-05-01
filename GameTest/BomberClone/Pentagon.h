#pragma once
#include "BomberClone\PrimitiveShape.h"
#include "BomberClone\DrawUtils.h"
#include "BomberClone\RenderableItems.h"

class Pentagon : public PrimitiveShape 
{
public:
	Pentagon();
	Pentagon(Position position, float size);
	Pentagon(Position position, float size, Color c);
	~Pentagon();

private:
	void CreatePentagon(float size);
};