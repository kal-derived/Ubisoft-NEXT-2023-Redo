#pragma once

	struct Position
	{
		float x;
		float y;
	};

	struct Vertex
	{
		Vertex(float x, float y);
		~Vertex();
		Position vertPos;
	};

	struct Color
	{
		float r;
		float g;
		float b;
	};


