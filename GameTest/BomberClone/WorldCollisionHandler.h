#pragma once
#include "Collision.h"
#include "Player.h"
#include "MapGenerator.h"

class WorldCollisionHandler {
public:
	WorldCollisionHandler(Player* p,MapGenerator* m);
	~WorldCollisionHandler();

	//void Init(std::vector<BoundingBox*> boxes);
	void Update();
	static void AddCollider(BoundingBox* b) {
		colliders.push_back(b);
	}

private:
	void CheckWorldCollisions();
	static std::vector<BoundingBox*> colliders;
	Player* player;
	MapGenerator* map;
};