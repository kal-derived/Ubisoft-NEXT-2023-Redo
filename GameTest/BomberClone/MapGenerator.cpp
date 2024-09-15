#include "stdafx.h"
#include "MapGenerator.h"

MapGenerator::MapGenerator() {
	
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			float xPos = APP_INIT_WINDOW_WIDTH / 2 + (j * (squareRadius * 2)) - ((squareRadius * 2) * floor(float(cols) / 2));
			xPos += cols % 2 == 0 ? squareRadius : 0;

			float yPos = APP_INIT_WINDOW_HEIGHT / 2 + (i * (squareRadius * 2)) - ((squareRadius * 2) * floor(float(rows) / 2));
			yPos += rows % 2 == 0 ? squareRadius : 0;

			MapTile* newTile = new MapTile({ xPos, yPos }, new BoundingBox(new Square({ xPos, yPos }, squareRadius)));

			if ((i == 0 || j == 0) || (i == rows-1 || j == cols-1)) // Set square boundary of the map to impervious blocks
			{
				newTile->SetType(MapTile::BOUNDARY);
			}

			else if ((i > 0 && i < rows - 1) && (j > 0 && j < cols - 1)) //Set an impervious grid of "pegs" inside the play space
			{
				if (i % 2 == 0 && j % 2 == 0) // Only set the even tiles as pegs
				{
					newTile->SetType(MapTile::BOUNDARY);
				}
			}

			InitTile(newTile);

			tiles.push_back(newTile);
		}
	}

	RandomizeTiles(4, 1);
}

MapGenerator::~MapGenerator() {

}

void MapGenerator::Render()
{
	for (size_t i = 0; i < tiles.size(); i++)
	{
		if (tiles[i]->GetType() == MapTile::EMPTY)
		{
			//tiles[i]->GetCollider()->RenderDebug();

		}
		switch (tiles[i]->GetType()) {
			case MapTile::CRACKED:
				if (tiles[i]->HasDrop()) {
					tiles[i]->GetCollider()->GetShape()->SetColor(1, 1, 0);
				}
				else if (tiles[i]->IsExit()) {
					tiles[i]->GetCollider()->GetShape()->SetColor(1, 0, 1);
				}
				else
				{
					tiles[i]->GetCollider()->GetShape()->SetColor(0.6, 0.5, 0.5);
				}
				break;
			case MapTile::BOUNDARY:
				tiles[i]->GetCollider()->GetShape()->SetColor(1, 0, 0);
				break;
			default:
				tiles[i]->GetCollider()->GetShape()->SetRenderMode(false);
				break;
		}
	}
}

void MapGenerator::InitTile(MapTile* t)
{
	if (t->GetType() == MapTile::EMPTY)
	{
		playableTiles.push_back(t);
		//t->GetCollider()->GetShape()->SetRenderMode(false);
		//t->GetCollider()->GetShape()->SetColor(0.2,0.2,0.2);
	}

}

void MapGenerator::InitTiles()
{
	for (size_t i=0; i < tiles.size(); i++)
	{
		InitTile(tiles[i]);
	}
}

MapTile* MapGenerator::FindTile(BoundingBox* b)
{
	for each (MapTile* tile in tiles)
	{
		if (tile->GetCollider() == b)
		{
			return tile;
		}
	}

	return nullptr;
}

void MapGenerator::RandomizeTiles(int numWalls, int numPowerups)
{
	srand(time(0));
	bool exitSet = false;
	int pCols = cols - 2;
	int pRows = rows - 2;
	int pTotal = (pCols * pRows) - pow((sqrt(pCols * pRows) - 1)/2,2);

		// Loop until all game elmements are present
	while(numWalls > 0 && numPowerups > 0 && exitSet == false) {
		for (size_t i = 0; i < playableTiles.size(); i++)
		{
			//Prevent top-left spawn corner from being occupied
			if (i == pTotal - pCols || i == pTotal - pCols + 1 || i == pTotal - (pCols + (pCols + 1) / 2))
			{
				//playableTiles[i]->GetCollider()->GetShape()->SetColor(1, 1, 1);
				continue;
			}


			// Placing a wall
			if (numWalls > 0 && rand() % 10 < 5)
			{
				playableTiles[i]->SetType(MapTile::CRACKED);

				numWalls -= 1;
			}

			//Setting special walls
			if (playableTiles[i]->GetType() == MapTile::CRACKED)
			{
				//Determining walls with powerups
				if (numPowerups > 0 && playableTiles[i]->IsExit() ==false && rand() % 10 < 4) {
					playableTiles[i]->SetDrop(true);
					numPowerups -= 1;
				}

				//Determining the wall with the exit
				if (exitSet == false && playableTiles[i]->HasDrop() ==false && rand() % 10 <= 2)
				{
					playableTiles[i]->SetExit(true);
					exitSet = true;
				}
			}
		}
	}
}

std::vector<MapTile*> MapGenerator::GetTiles()
{
	return tiles;
}


