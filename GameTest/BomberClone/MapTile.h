#pragma once
#include "DrawUtils.h"
#include "BoundingBox.h"

class MapTile {
public:
	MapTile(Position p, BoundingBox* box);
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
	void SetDrop(bool d);
	bool HasDrop();
	bool IsExit();
	void SetExit(bool e);

private:
	bool hasDrop = false;
	bool isExit = false;
	Position center;
	BoundingBox* collider;
	int type = tileType::EMPTY;
};