#pragma once
#include "DrawUtils.h"
#include "BoundingBox.h"

class MapTile {
public:
	MapTile(Position p, BoundingBox* box);
	~MapTile();

	void Update();

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
	bool IsExploding();
	void SetExploding(bool e);
	//int GetTimestamp();
	//int GetExplosionDelayAmount();
	//void SetExplosionDelayAmount(int d);


private:
	bool hasDrop = false;
	bool isExit = false;
	bool isExploding = false;
	Position center;
	BoundingBox* collider;
	int type = tileType::EMPTY;
	//int timestamp = 0;
	int delay = 4;
	//void CheckIfExplodeFuseElapsed();
};