#include "stdafx.h"
#include "Square.h"

/// <summary>
/// Shape definition for a square
/// </summary>

Square::Square()
{
	color = { 1,0,0 };
	center.x = APP_INIT_WINDOW_WIDTH / 2;
	center.y = APP_INIT_WINDOW_HEIGHT / 2;
	CreateSquare(10);
}

Square::Square(Position position, float radius)
{
	color = { 1,0,0 };
	center.x = position.x;
	center.y = position.y;
	CreateSquare(radius);
}

Square::Square(Position position, float radius, Color c)
{
	color = c;
	center.x = position.x;
	center.y = position.y;
	CreateSquare(radius);
}


Square::~Square()
{
	PrimitiveShape::~PrimitiveShape();
}

void Square::CreateSquare(float radius)
{
	//PrimitiveShape::Register(this);
	vertices.push_back(Vertex(center.x - radius, center.y + radius)); // Top-Left corner
	vertices.push_back(Vertex(center.x + radius, center.y + radius));// Top-Right Corner
	vertices.push_back(Vertex(center.x + radius, center.y - radius));// Bottom-Right Corner
	vertices.push_back(Vertex(center.x - radius, center.y - radius));// Bottom-Left Corner
	RenderableItems::RegisterPrimitive(this);
	OutputDebugString(L"Registered a square.");
	OutputDebugString(std::to_wstring(vertices.size()).c_str());
}
