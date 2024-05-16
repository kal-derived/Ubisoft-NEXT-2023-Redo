#pragma once
#include "ControllerInfo.h"
#include "Square.h"
#include "Triangle.h"
#include "BoundingBox.h"

class Player
{
public:
	Player();
	~Player();

	void Update();

	BoundingBox* GetCollider();
	Square* GetBody();

private:
	void Move();
	void Action1();
	void Action2();
	void UpdatePosition(/*Position newPosition*/);

	float moveSpeed = 4;
	Position playerPosition;
	Square* playerBody;
	BoundingBox* collider;

	ControllerInfo controlRef;
};

