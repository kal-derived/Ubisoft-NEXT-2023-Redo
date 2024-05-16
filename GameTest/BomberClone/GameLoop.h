#pragma once
#include "BomberClone\PrimitiveShape.h"
#include "BomberClone\Triangle.h"
#include "BomberClone\Square.h"
#include "BomberClone\Pentagon.h"
#include "BomberClone\Player.h"
#include "BomberClone/BoundingBox.h"
#include "BomberClone/Collision.h"

class GameLoop {

public:
	GameLoop();
	~GameLoop();

	void Init();
	void Update();
	void Render();
	void Shutdown();
};