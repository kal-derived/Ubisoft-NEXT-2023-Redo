#include "stdafx.h"
#include "PlayerControlsLink.h"

PlayerControlsLink::PlayerControlsLink()
{
}

PlayerControlsLink::~PlayerControlsLink()
{
}

void PlayerControlsLink::Update(Player* player, ControllerInfo* controls)
{
	Position playerPos = player->GetPosition();
	float moveSpeed = player->GetSpeed();

	player->SetDirection({0, 0});

	if (controls->isLStickRight()) 
	{
		player->SetDirectionX( 1 );
	}
	if (controls->isLStickLeft()) 
	{
		player->SetDirectionX( -1 );
	}
	if (controls->isLStickUp()) 
	{
		player->SetDirectionY( 1 );
	}
	if (controls->isLStickDown()) 
	{
		player->SetDirectionY( -1 );
	}

	Position playerDirection = player->GetDirection();

	player->SetPosition({ playerPos.x + playerDirection.x * moveSpeed, playerPos.y + playerDirection.y * moveSpeed });
	player->UpdatePosition();

	if (controls->isButtonHeld(controls->dpadUp)) {}
	if (controls->isButtonHeld(controls->dpadDown)) {}
	if (controls->isButtonHeld(controls->dpadLeft)) {}
	if (controls->isButtonHeld(controls->dpadRight)) {}
	if (controls->isButtonJustPressed(controls->buttonSouth)) 
	{
		player->Action1();
	}
	if (controls->isButtonJustPressed(controls->buttonEast)) {}
}
