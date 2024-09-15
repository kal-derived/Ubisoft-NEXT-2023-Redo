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
	void RandomizeTiles(int numWalls, int numPowerups);

	void DisableTileCollision(MapTile* t);

	std::vector<MapTile*> GetTiles();

private:
	int cols = 7;
	int rows = 7;
	std::vector<MapTile*> tiles;
	std::vector<MapTile*> playableTiles;
	int squareRadius = 40;
};