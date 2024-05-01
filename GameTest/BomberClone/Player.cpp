#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	playerPosition = { APP_INIT_WINDOW_WIDTH / 2, APP_INIT_WINDOW_HEIGHT / 2 };
	playerBody = new Square({ playerPosition.x, playerPosition.y }, 20);
}

Player::~Player()
{
	delete playerBody;
}

void Player::Update()
{
	controlRef.Update(App::GetController());
	Move();
	Action1();
}

void Player::UpdatePosition(/*Position newPosition*/)
{
	//playerPosition = newPosition;
	playerBody->SetCenter(playerPosition);
}


void Player::Move()
{
	if (controlRef.isLStickLeft() == true) 
	{
		playerPosition.x -= moveSpeed / 10.0f;
	}
	else if (controlRef.isLStickRight() == true) 
	{
		playerPosition.x += moveSpeed / 10.0f;
	}

	if (controlRef.isLStickUp() == true) 
	{
		playerPosition.y += moveSpeed / 10.0f;
	}
	else if (controlRef.isLStickDown() == true)
	{
		playerPosition.y -= moveSpeed / 10.0f;
	}

	UpdatePosition();
}

void Player::Action1()
{
	if (controlRef.isButtonJustPressed(controlRef.buttonSouth)) 
	{
		Triangle* t = new Triangle(playerPosition, 20);
	}
}

void Player::Action2()
{
}


