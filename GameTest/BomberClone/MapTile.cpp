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

void MapTile::SetDrop(bool d)
{
	hasDrop = d;
}

bool MapTile::HasDrop()
{
	return hasDrop;
}

bool MapTile::IsExit()
{
	return isExit;
}

void MapTile::SetExit(bool e)
{
	isExit = e;
}
