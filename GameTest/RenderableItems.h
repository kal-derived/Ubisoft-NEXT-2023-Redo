#pragma once
#include "stdafx.h"
#include "PrimitiveShape.h"
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

