#include "stdafx.h"
#include "MapTile.h"

MapTile::MapTile(Position p, BoundingBox* box)
{
	center = p;
	collider = box; 
	//timestamp = 0;
}

MapTile::~MapTile()
{
}

void MapTile::Update() 
{
	/*if(IsExploding())
	{
		CheckIfExplodeFuseElapsed();
	}*/
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

bool MapTile::IsExploding()
{
	return isExploding;
}

void MapTile::SetExploding(bool e)
{
	isExploding = e;
	/*if (e == true)
	{
		timestamp = time(nullptr);
	}*/
}

//int MapTile::GetTimestamp()
//{
//	return timestamp;
//}
//
//int MapTile::GetExplosionDelayAmount()
//{
//	return delay;
//}
//
//void MapTile::SetExplosionDelayAmount(int d)
//{
//	delay = d;
//}
//
//void MapTile::CheckIfExplodeFuseElapsed()
//{
//	if (isExploding && timestamp != 0)
//	{
//		if (timestamp + delay <= time(nullptr))
//		{
//			OutputDebugString(L"idk");
//			SetExploding(false);
//		}
//	}
//}
