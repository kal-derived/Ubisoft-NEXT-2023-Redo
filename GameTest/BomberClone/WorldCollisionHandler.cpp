#include "stdafx.h"
#include "WorldCollisionHandler.h"

std::vector<BoundingBox*> WorldCollisionHandler::colliders;
WorldCollisionHandler::WorldCollisionHandler(Player* p, MapGenerator* m)
{
	player = p;
	map = m;
}

WorldCollisionHandler::~WorldCollisionHandler()
{

}

void WorldCollisionHandler::Update()
{
	CheckWorldCollisions();
}

void WorldCollisionHandler::CheckWorldCollisions()
{
	BoundingBox* playerCollider = player->GetCollider();
	for (int i = 0; i < colliders.size(); i++)
	{
		//Check if the player's BB overlaps that of another registered object's
		if (Collision::isTouching(playerCollider, colliders[i]))
		{
			MapTile* currentTile = map->FindTile(colliders[i]);

			//We're dealing with a non-map tile object
			if (currentTile == nullptr)
			{
				//std::cout << "hey!";
				//currentTile->GetCollider()->GetShape()->SetColor(0, 1, 1);
				Collision::ResolveCollision(player->GetCollider(), colliders[i]);
				playerCollider = player->GetCollider();
				player->SetPosition(playerCollider->center);
			}
			
			//If we're dealing with a map tile...
			else 
			{
				//Check if the map tile has the collider we're checking
				if (currentTile->GetCollider() == colliders[i]) {

					//Solid tile collision
					if (currentTile->GetType() != MapTile::EMPTY)
					{
						Collision::ResolveCollision(player->GetCollider(), colliders[i]);
						playerCollider = player->GetCollider();
						player->SetPosition(playerCollider->center);
					}

					//Non-solid tile handling
					else
					{
						//Update the tile the player is "currently standing on" if their center is within the tile's BB
						if (currentTile->GetCollider()->ContainsPoint(player->GetPosition()))
						{
							player->SetCurrentTile(currentTile);
						}
					}
				}

			}
			//player->GetBody()->SetColor(1, 1, 1);
		}
	}
}
