#include "stdafx.h"
#include "WorldCollisionHandler.h"

std::vector<BoundingBox*> WorldCollisionHandler::colliders;
WorldCollisionHandler::WorldCollisionHandler(Player* p)
{
	player = p;
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
		if (Collision::isTouching(playerCollider, colliders[i]))
		{
			//player->GetBody()->SetColor(1, 1, 1);
			Collision::ResolveCollision(player->GetCollider(), colliders[i]);
			playerCollider = player->GetCollider();
			player->SetPosition(playerCollider->center);
		}
	}
}
