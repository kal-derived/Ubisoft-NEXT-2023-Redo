#pragma once
#include "DrawUtils.h"
#include "WorldCollisionHandler.h"

class MapTile {
public:
	MapTile(Position p, BoundingBox*);
	~MapTile();

	enum tileType {
		EMPTY,
		SPAWN,
		EXIT,
		WALL,
		CRACKED,
		BOUNDARY
	};

	Position GetCenter();
	BoundingBox* GetCollider();
	int GetType();
	void SetType(tileType i);
	bool HasDrop();

private:
	bool hasDrop = false;
	Position center;
	BoundingBox* collider;
	int type = tileType::EMPTY;
};