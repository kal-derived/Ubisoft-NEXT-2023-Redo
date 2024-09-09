#pragma once
#include "Square.h"
#include "BoundingBox.h"

class MapGenerator {

public:
	MapGenerator();
	~MapGenerator();

	void Render();
private:
	int cols = 3;
	int rows = 4;
	std::vector<BoundingBox*> tiles;

};