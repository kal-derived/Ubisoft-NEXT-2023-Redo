#include "stdafx.h"
#include "Pentagon.h"

Pentagon::Pentagon()
{
	color = { 1,0,0 };
	center.x = APP_INIT_WINDOW_WIDTH / 2;
	center.y = APP_INIT_WINDOW_HEIGHT / 2;
	CreatePentagon(80);
}

Pentagon::Pentagon(Position position, float size)
{
	color = { 1,0,0 };
	center.x = position.x;
	center.y = position.y;
	CreatePentagon(size);
}

Pentagon::Pentagon(Position position, float size, Color c)
{
	color = c;
	center.x = position.x;
	center.y = position.y;
	CreatePentagon(size);
}

Pentagon::~Pentagon()
{
}

void Pentagon::CreatePentagon(float size)
{
	Position mid = {size * cos(32), size * sin(32)/2.3f};	//Pythagorean triangle from center to 2nd tier of vertices
	Position bottom = {size * cos(62)/1.2f, size * sin(62)};	//Triangle from center to 3rd tier of vertices

	vertices.push_back(new Vertex(center.x, center.y + size / (2 * 0.587f) )); // Top vert - constant replaces sin(180/5)
	vertices.push_back(new Vertex(center.x + mid.x, center.y + mid.y));	// Mid-right vert
	vertices.push_back(new Vertex(center.x + bottom.x, center.y + bottom.y));	// Bottom-right vert
	vertices.push_back(new Vertex(center.x - bottom.x, center.y + bottom.y));	// Bottom-left vert
	vertices.push_back(new Vertex(center.x - mid.x, center.y + mid.y));	// Mid-left vert

	RenderableItems::RegisterPrimitive(this);
}
