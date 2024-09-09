#pragma once
#include "BomberClone\PrimitiveShape.h"
#include "BomberClone\Triangle.h"
#include "BomberClone\Square.h"
#include "BomberClone\Pentagon.h"
#include "BomberClone\Player.h"
#include "BomberClone/BoundingBox.h"
#include "BomberClone/Collision.h"
#include "BomberClone/PlayerControlsLink.h"
#include "BomberClone/WorldCollisionHandler.h"
#include "BomberClone/Debug.h"
#include "BomberClone/MapGenerator.h"

class GameLoop {

public:
	GameLoop();
	~GameLoop();

	void Init();
	void Update();
	void Render();
	void Shutdown();

};