#pragma once
#include "ControllerInfo.h"
#include "Square.h"
#include "Triangle.h"

class Player
{
public:
	Player();
	~Player();

	void Update();

private:
	void Move();
	void Action1();
	void Action2();
	void UpdatePosition(/*Position newPosition*/);

	float moveSpeed = 4;
	Position playerPosition;
	Square* playerBody;

	ControllerInfo controlRef;
};

