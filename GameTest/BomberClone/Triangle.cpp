#include "stdafx.h"
#include "Triangle.h"

/// <summary>
/// Shape definition for a triangle
/// </summary>

Triangle::Triangle()
{
	color = { 1,0,0 };
	center.x = APP_INIT_WINDOW_WIDTH / 2;
	center.y = APP_INIT_WINDOW_HEIGHT / 2;
	CreateTriangle(10);
}

Triangle::Triangle(Position position, float height)
{
	color = { 1,0,0 };
	center.x = position.x;
	center.y = position.y;
	CreateTriangle(height);
}

Triangle::Triangle(Position position, float height, Color c)
{
	color = c;
	center.x = position.x;
	center.y = position.y;
	CreateTriangle(height);
}

Triangle::~Triangle()
{
	PrimitiveShape::~PrimitiveShape();
}

void Triangle::CreateTriangle(float height)
{
	//PrimitiveShape::Register(this);
	vertices.push_back(new Vertex(center.x, center.y + height / 2));
	vertices.push_back(new Vertex(center.x + (height / 0.866f) / 2, center.y - height / 2)); //0.866 is an approximation of sqrt(3)/2 - The constant that gives the length of equilateral triangle side when dividing height
	vertices.push_back(new Vertex(center.x - (height / 0.866f) / 2, center.y - height / 2));
	RenderableItems::RegisterPrimitive(this);
	OutputDebugString(L"Registered a triangle.");
	OutputDebugString(std::to_wstring(vertices.size()).c_str());
}
