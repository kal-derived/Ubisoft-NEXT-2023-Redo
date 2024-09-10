#include "stdafx.h"
#include "MapGenerator.h"

MapGenerator::MapGenerator() {
	int squareRadius = 20;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			float xPos = APP_INIT_WINDOW_WIDTH / 2 + (j * (squareRadius * 2)) - ((squareRadius * 2) * floor(float(cols) / 2));
			xPos += cols % 2 == 0 ? squareRadius : 0;

			float yPos = APP_INIT_WINDOW_HEIGHT / 2 + (i * (squareRadius * 2)) - ((squareRadius * 2) * floor(float(rows) / 2));
			yPos += rows % 2 == 0 ? squareRadius : 0;

			MapTile* newTile = new MapTile({ xPos, yPos }, new BoundingBox(new Square({ xPos, yPos }, squareRadius)));

			if ((i == 0 || j == 0) || (i == rows-1 || j == cols-1))
			{
				newTile->SetType(MapTile::BOUNDARY);
			}

			InitTile(newTile);

			tiles.push_back(newTile);
		}
	}
}

MapGenerator::~MapGenerator() {

}

void MapGenerator::Render()
{
	for (size_t i = 0; i < tiles.size(); i++)
	{
		if (tiles[i]->GetType() == MapTile::EMPTY)
		{
			tiles[i]->GetCollider()->RenderDebug();

		}
	}
}

void MapGenerator::InitTile(MapTile* t)
{
	if (t->GetType() == MapTile::EMPTY)
	{
		t->GetCollider()->GetShape()->SetRenderMode(false);
	}
}

void MapGenerator::InitTiles()
{
	for (size_t i=0; i < tiles.size(); i++)
	{
		InitTile(tiles[i]);
	}
}
