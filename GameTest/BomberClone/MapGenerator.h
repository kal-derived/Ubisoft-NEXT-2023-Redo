#pragma once
#include "Square.h"
#include "MapTile.h"

class MapGenerator {

public:
	MapGenerator();
	~MapGenerator();

	void Render();
	void InitTile(MapTile* t);
	void InitTiles();
	void DisableTileCollision(MapTile* t);

private:
	int cols = 3;
	int rows = 4;
	std::vector<MapTile*> tiles;

};