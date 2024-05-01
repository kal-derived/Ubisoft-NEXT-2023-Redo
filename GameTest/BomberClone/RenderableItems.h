#pragma once
#include "stdafx.h"
#include "BomberClone\PrimitiveShape.h"
class RenderableItems
{
public:
	RenderableItems();
	~RenderableItems();


	static void RenderAll();
	static void RegisterPrimitive(PrimitiveShape* item);

private:

	static std::vector<PrimitiveShape*> renderables;

};

