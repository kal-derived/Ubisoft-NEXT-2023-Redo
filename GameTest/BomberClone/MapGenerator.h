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
	MapTile* FindTile(BoundingBox* b);
	void DisableTileCollision(MapTile* t);

	std::vector<MapTile*> GetTiles();

private:
	int cols = 7;
	int rows = 7;
	std::vector<MapTile*> tiles;
	int squareRadius = 40;
};