#pragma once
#include "Player.h"
#include "ControllerInfo.h"

class PlayerControlsLink {

public:
	PlayerControlsLink();
	~PlayerControlsLink();

	void Update(Player* player, ControllerInfo* controls);

};