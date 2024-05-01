#pragma once
#include "app\app.h"

class ControllerInfo
{
public:
	ControllerInfo();
	~ControllerInfo();

	float GetLStickX();
	float GetLStickY();
	float GetRStickX();
	float GetRStickY();

	bool isLStickLeft();
	bool isLStickRight();
	bool isLStickUp();
	bool isLStickDown();

	bool isRStickLeft();
	bool isRStickRight();
	bool isRStickUp();
	bool isRStickDown();

	enum Dpad
	{
		
	};

	enum Buttons 
	{
		dpadUp,
		dpadDown,
		dpadLeft,
		dpadRight,
		buttonNorth,
		buttonSouth,
		buttonEast,
		buttonWest,
		shoulderLeft,
		shoulderRight,
		rThumbstickIn,
		lThumbstickIn,
		start,
		select
	};

	bool isButtonHeld(Buttons button);
	bool isButtonJustPressed(Buttons button);

	void Update(CController updated);
	void SetDeadzone(float dz);

private:
	CController vController;
	static float deadzone;

	bool ButtonCheck(Buttons button, bool heldStatus);
};

