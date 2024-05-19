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
	void SetPosition(Position p);
	void UpdatePosition(/*Position newPosition*/);
	void Action1();
	void Action2();

	void SetDirection(Position dir);
	void SetDirectionX(float xDir);
	void SetDirectionY(float yDir);


	BoundingBox* GetCollider();
	Square* GetBody();
	Position GetPosition();
	float GetSpeed();
	Position GetDirection();

private:
	//void Move();

	float moveSpeed = 4;
	Position playerPosition;
	Position direction;
	Square* playerBody;
	BoundingBox* collider;

	//ControllerInfo controlRef;
};

