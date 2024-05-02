#include "stdafx.h"
#include "PrimitiveShape.h"

PrimitiveShape::~PrimitiveShape()
{
	for each (Vertex* v in vertices)
	{
		delete v;
	}
}

PrimitiveShape::PrimitiveShape()
{
	color = { 1,0,0 };
	center.x = APP_INIT_WINDOW_WIDTH / 2;
	center.y = APP_INIT_WINDOW_HEIGHT / 2;
	//CreateDebugShape();
	//CreateShape();
}

PrimitiveShape::PrimitiveShape(float x, float y) 
{
	color = { 1,0,0 };
	center.x = x;
	center.y = y;
}

void PrimitiveShape::CreateShape()
{
	return;
}

//void PrimitiveShape::Register(PrimitiveShape* self)
//{
//	RenderableItems::RegisterPrimitive(self);
//}

void PrimitiveShape::CreateDebugShape()
{
	vertices.push_back(new Vertex(center.x, center.y + 50));
	vertices.push_back(new Vertex(center.x + 28, center.y)); // Length of a triangle side is height / (sqrt(3)/2) - drawing from the middle gives half of that
	vertices.push_back(new Vertex(center.x - 28, center.y));
}


void PrimitiveShape::Render()
{
	Position start = {-1, -1};
	Position end = {-1, -1};

	for (int i = 0; i < vertices.size(); i++)
	{
		if (start.x == -1 && end.x == -1) {
			start = vertices[i]->vertPos;
			end = vertices[i + 1]->vertPos;
		}


		if(start.x > -1 && end.x > -1) {

			App::DrawLine(start.x, start.y, end.x, end.y, 1, 0, 0);
			if (i == vertices.size() - 1)
			{
				App::DrawLine(end.x, end.y, vertices[0]->vertPos.x, vertices[0]->vertPos.y, 0, 1, 0);
			}
			else {
				start = vertices[i]->vertPos;
				end = vertices[i+1]->vertPos;
			}
			
		}
	}
}

void PrimitiveShape::SetCenter(Position newPosition)
{
	UpdateVertPositions(newPosition);
	center = newPosition;
}

Position PrimitiveShape::GetCenter()
{
	return center;
}

std::vector<Vertex*> PrimitiveShape::GetVerts()
{
	return vertices;
}


void PrimitiveShape::UpdateVertPositions(Position newPosition)
{
	Position deltaPosition = { newPosition.x - center.x, newPosition.y - center.y}; //Difference between new position and old position
	for (int i = 0; i < vertices.size(); i++)
	{

			vertices[i]->vertPos.x += deltaPosition.x;

			vertices[i]->vertPos.y += deltaPosition.y;
		

	}
}


