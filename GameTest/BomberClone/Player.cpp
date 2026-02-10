#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	playerPosition = { APP_INIT_WINDOW_WIDTH / 3, APP_INIT_WINDOW_HEIGHT / 2 };
	playerBody = new Square({ playerPosition.x, playerPosition.y }, 20);
	collider = new BoundingBox(playerBody);
	direction = { 0,0 };
	bomb1 = new Bomb();
}

Player::~Player()
{
	delete playerBody;
	delete collider;
}

void Player::Update()
{
	//controlRef.Update(App::GetController());
	//Move();
	//Action1();
	if (bomb1->IsActive())
	{
		bomb1->Update();
	}
}

void Player::SetPosition(Position p)
{
	playerPosition = p;
}

BoundingBox* Player::GetCollider()
{
	return collider;
}

Square* Player::GetBody()
{
	return playerBody;
}

Position Player::GetPosition()
{
	return playerPosition;
}

float Player::GetSpeed()
{
	return moveSpeed / 10.0f;
}

Position Player::GetDirection()
{
	return direction;
}

void Player::SetCurrentTile(MapTile* t)
{
	currentTile = t;
}

void Player::UpdatePosition(/*Position newPosition*/)
{
	//playerPosition = newPosition;
	//playerBody->SetCenter(playerPosition);
	collider->SetPosition(playerPosition);
}


//void Player::Move()
//{
//	if (controlRef.isLStickLeft() == true) 
//	{
//		playerPosition.x -= moveSpeed / 10.0f;
//	}
//	else if (controlRef.isLStickRight() == true) 
//	{
//		playerPosition.x += moveSpeed / 10.0f;
//	}
//
//	if (controlRef.isLStickUp() == true) 
//	{
//		playerPosition.y += moveSpeed / 10.0f;
//	}
//	else if (controlRef.isLStickDown() == true)
//	{
//		playerPosition.y -= moveSpeed / 10.0f;
//	}
//
//	UpdatePosition();
//}

void Player::Action1()
{
	//Triangle* t = new Triangle(currentTile->GetCenter(), 20);
	currentTile->SetExploding(true);
	//if (currentTile->GetTimestamp() + currentTile->GetExplosionDelayAmount() <= time(nullptr))
	//{
	//	//NOT GONNA WORK - WILL ONLY UPDATE TRIANGLE WHEN BUTTON PRESSED. PROBABLY NEED A BOMB OBJ/CLASS
	//	OutputDebugString(L"bomb despawned");
	//}
	if (bomb1->IsActive() == false)
	{
		bomb1->ActivateBomb(currentTile);
	}
	
}

void Player::Action2()
{
}

void Player::SetDirection(Position dir)
{
	direction = dir;
	if (dir.x != 0 || dir.y != 0)
	{
		float div = sqrt(pow(dir.x,2) + pow(dir.y,2));
		direction.x /= div;
		direction.y /= div;
	}
}

void Player::SetDirectionX(float xDir)
{
	SetDirection({xDir, direction.y});
}

void Player::SetDirectionY(float yDir)
{
	SetDirection({direction.x, yDir});
}


