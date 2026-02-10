#pragma once
#include "Square.h"
#include "MapTile.h"

class MapGenerator {

public:
	MapGenerator();
	~MapGenerator();

	void Render();
	void Update();
	void InitTile(MapTile* t);
	void InitTiles();
	MapTile* FindTile(BoundingBox* b);
	void RandomizeTiles(int numWalls, int numPowerups);

	void ExplodeTiles();
	void DisableTileCollision(MapTile* t);

	std::vector<MapTile*> GetTiles();

private:
	int cols = 7;
	int rows = 7;
	std::vector<MapTile*> tiles;
	std::vector<MapTile*> playableTiles;
	int squareRadius = 40;
	//int timestamp = 0;


};