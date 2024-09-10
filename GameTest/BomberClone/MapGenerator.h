#pragma once
#include "Square.h"
#include "MapTile.h"

class MapGenerator {

public:
	MapGenerator();
	~MapGenerator();

	void Render();
private:
	int cols = 3;
	int rows = 4;
	std::vector<MapTile*> tiles;

};