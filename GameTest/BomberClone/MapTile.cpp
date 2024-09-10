#include "stdafx.h"
#include "MapTile.h"

MapTile::MapTile(Position p, BoundingBox* box)
{
	center = p;
	collider = box;

	WorldCollisionHandler::AddCollider(collider);
}

MapTile::~MapTile()
{
}

Position MapTile::GetCenter()
{
	return center;
}

BoundingBox* MapTile::GetCollider()
{
	return collider;
}

bool MapTile::HasDrop()
{
	return hasDrop;
}
