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

			if (currentTile == nullptr)
			{
				//std::cout << "hey!";
				//currentTile->GetCollider()->GetShape()->SetColor(0, 1, 1);
				Collision::ResolveCollision(player->GetCollider(), colliders[i]);
				playerCollider = player->GetCollider();
				player->SetPosition(playerCollider->center);
			}
			else
			{
				if (currentTile->GetCollider() == colliders[i] && currentTile->GetType() != MapTile::EMPTY) {
					Collision::ResolveCollision(player->GetCollider(), colliders[i]);
					playerCollider = player->GetCollider();
					player->SetPosition(playerCollider->center);
				}
			}
			//player->GetBody()->SetColor(1, 1, 1);
		}
	}
}
