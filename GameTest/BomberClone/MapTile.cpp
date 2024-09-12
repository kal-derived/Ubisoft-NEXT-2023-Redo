#include "stdafx.h"
#include "MapTile.h"

MapTile::MapTile(Position p, BoundingBox* box)
{
	center = p;
	collider = box;
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

int MapTile::GetType()
{
	return type;
}

void MapTile::SetType(tileType i)
{
	type = i;
}

bool MapTile::HasDrop()
{
	return hasDrop;
}
