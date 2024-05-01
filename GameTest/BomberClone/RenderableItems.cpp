#include "stdafx.h"
#include "RenderableItems.h"




RenderableItems::RenderableItems()
{
	
}
std::vector<PrimitiveShape*> RenderableItems::renderables;
RenderableItems::~RenderableItems()
{
	for each (PrimitiveShape * shape in renderables)
	{
		delete shape;
	}
}

void RenderableItems::RenderAll()
{
	for (int i = 0; i < renderables.size(); i++)
	{
		renderables.at(i)->Render();
	}
}

void RenderableItems::RegisterPrimitive(PrimitiveShape* item)
{
	renderables.push_back(item);
}
