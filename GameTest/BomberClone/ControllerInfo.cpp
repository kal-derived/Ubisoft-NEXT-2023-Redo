#include "stdafx.h"
#include "ControllerInfo.h"

/// <summary>
/// A class for simplifying access of controller information
/// </summary>

float ControllerInfo::deadzone = 0.5f;

ControllerInfo::ControllerInfo()
{
	vController = App::GetController();
}

ControllerInfo::~ControllerInfo()
{
}

// LEFT STICK

/// <summary>
/// Checks if the Left thumbstick is leaning enough past the 
/// deadzone boundary to be considered pointing "Left"
/// </summary>
/// <returns>Whether it is pointing left or not</returns>
bool ControllerInfo::isLStickLeft()
{
	return GetLStickX() < deadzone * (-1) ? true : false;
}

/// <summary>
/// Checks if the Left thumbstick is leaning enough past the 
/// deadzone boundary to be considered pointing "Right"
/// </summary>
/// <returns>Whether it is pointing right or not</returns>
bool ControllerInfo::isLStickRight()
{
	return GetLStickX() > deadzone ? true : false;
}

/// <summary>
/// Checks if the Left thumbstick is leaning enough past the 
/// deadzone boundary to be considered pointing "Upwards"
/// </summary>
/// <returns>Whether it is pointing up or not</returns>
bool ControllerInfo::isLStickUp()
{
	return GetLStickY() > deadzone ? true : false;
}

/// <summary>
/// Checks if the Left thumbstick is leaning enough past the 
/// deadzone boundary to be considered pointing "Downwards"
/// </summary>
/// <returns>Whether it is pointing down or not</returns>
bool ControllerInfo::isLStickDown()
{
	return GetLStickY() < deadzone * (-1) ? true : false;
}

// RIGHT STICK

bool ControllerInfo::isRStickLeft()
{
	return GetRStickX() < 0 ? true : false;
}

bool ControllerInfo::isRStickRight()
{
	return GetRStickX() > 0 ? true : false;
}

bool ControllerInfo::isRStickUp()
{
	return GetLStickY() > 0 ? true : false;
}

bool ControllerInfo::isRStickDown()
{
	return GetLStickY() < 0 ? true : false;
}



/// <summary>
/// Checks the state of a specified button on the
/// controller that uses binary states
/// </summary>
/// <param name="button"></param>
/// <returns>Whether the button in question is being held or not</returns>
bool ControllerInfo::ButtonCheck(Buttons button, bool heldStatus)
{
	switch (button)
	{
	case ControllerInfo::dpadUp:
		//OutputDebugString(std::to_wstring(vController.CheckButton(XINPUT_GAMEPAD_DPAD_UP, false)).append(L" eugh\n").c_str());
		return vController.CheckButton(XINPUT_GAMEPAD_DPAD_UP, heldStatus);
	case ControllerInfo::dpadDown:
		return vController.CheckButton(XINPUT_GAMEPAD_DPAD_DOWN, heldStatus);
	case ControllerInfo::dpadLeft:
		return vController.CheckButton(XINPUT_GAMEPAD_DPAD_LEFT, heldStatus);
	case ControllerInfo::dpadRight:
		return vController.CheckButton(XINPUT_GAMEPAD_DPAD_RIGHT, heldStatus);
	case ControllerInfo::buttonNorth:
		return vController.CheckButton(XINPUT_GAMEPAD_Y, heldStatus);
	case ControllerInfo::buttonSouth:
		return vController.CheckButton(XINPUT_GAMEPAD_A, heldStatus);
	case ControllerInfo::buttonEast:
		return vController.CheckButton(XINPUT_GAMEPAD_B, heldStatus);
	case ControllerInfo::buttonWest:
		return vController.CheckButton(XINPUT_GAMEPAD_X, heldStatus);
	case ControllerInfo::lThumbstickIn:
		return vController.CheckButton(XINPUT_GAMEPAD_LEFT_THUMB, heldStatus);
	case ControllerInfo::rThumbstickIn:
		return vController.CheckButton(XINPUT_GAMEPAD_RIGHT_THUMB, heldStatus);
	case ControllerInfo::shoulderLeft:
		return vController.CheckButton(XINPUT_GAMEPAD_LEFT_SHOULDER, heldStatus);
	case ControllerInfo::shoulderRight:
		return vController.CheckButton(XINPUT_GAMEPAD_RIGHT_SHOULDER, heldStatus);
	case ControllerInfo::start:
		return vController.CheckButton(XINPUT_GAMEPAD_START, heldStatus);
	case ControllerInfo::select:
		return vController.CheckButton(XINPUT_GAMEPAD_BACK, heldStatus);
	default:
		OutputDebugString(L" Button not found");
		return false;
	}
}
/// <summary>
/// Checks if the specified button is being held down
/// </summary>
/// <param name="button"></param>
/// <returns>Whether the button in question is being held or not</returns>
bool ControllerInfo::isButtonHeld(Buttons button) {
	return ButtonCheck(button, false);
}

/// <summary>
/// Checks if the specifed button was just recently pressed
/// </summary>
/// <param name="button"></param>
/// <returns>Whether the button was just pressed or not</returns>
bool ControllerInfo::isButtonJustPressed(Buttons button)
{
	return ButtonCheck(button, true);
}

void ControllerInfo::Update(CController updated)
{
	vController = updated;
}

void ControllerInfo::SetDeadzone(float dz)
{
	deadzone = dz;
}

// ============= Helpers =========

float ControllerInfo::GetLStickX()
{
	//OutputDebugString(std::to_wstring(vController.GetLeftThumbStickX()).c_str());
	return vController.GetLeftThumbStickX();
}

float ControllerInfo::GetLStickY()
{
	//OutputDebugString(std::to_wstring(vController.GetLeftThumbStickY()).c_str());
	return vController.GetLeftThumbStickY();
}

float ControllerInfo::GetRStickX()
{
	return vController.GetRightThumbStickX();
}

float ControllerInfo::GetRStickY()
{
	return vController.GetRightThumbStickY();
}


