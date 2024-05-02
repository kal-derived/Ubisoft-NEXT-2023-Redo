//------------------------------------------------------------------------
// GameTest.cpp
//------------------------------------------------------------------------
#include "stdafx.h"
//------------------------------------------------------------------------
#include <windows.h> 
#include <math.h>  
//------------------------------------------------------------------------
#include "app\app.h"
//------------------------------------------------------------------------
#include "BomberClone\ControllerInfo.h"
#include "BomberClone\PrimitiveShape.h"
#include "BomberClone\Triangle.h"
#include "BomberClone\Square.h"
#include "BomberClone\Pentagon.h"
#include "BomberClone\Player.h"
#include "BomberClone/BoundingBox.h"
//------------------------------------------------------------------------
// Example data....
//------------------------------------------------------------------------
CSimpleSprite *testSprite;
// ===== This is *my* example data =====
ControllerInfo padInfo;
Triangle* primshape;
Square* sq;
Player* player;
Pentagon* penta;
BoundingBox* box;

enum
{
	ANIM_FORWARDS,
	ANIM_BACKWARDS,
	ANIM_LEFT,
	ANIM_RIGHT,
};
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// Called before first update. Do any initial setup here.
//------------------------------------------------------------------------
void Init()
{
#pragma region ExampleCode

	//------------------------------------------------------------------------
	// Example Sprite Code....
	testSprite = App::CreateSprite(".\\TestData\\Test.bmp", 8, 4);
	testSprite->SetPosition(400.0f, 400.0f);
	float speed = 1.0f / 15.0f;
	testSprite->CreateAnimation(ANIM_BACKWARDS, speed, { 0,1,2,3,4,5,6,7 });
	testSprite->CreateAnimation(ANIM_LEFT, speed, { 8,9,10,11,12,13,14,15 });
	testSprite->CreateAnimation(ANIM_RIGHT, speed, { 16,17,18,19,20,21,22,23 });
	testSprite->CreateAnimation(ANIM_FORWARDS, speed, { 24,25,26,27,28,29,30,31 });
	testSprite->SetScale(1.0f);
	//------------------------------------------------------------------------
	padInfo = ControllerInfo();
#pragma endregion

	//primshape = new Triangle({500,400}, 100);
	//sq = new Square({200, 300}, 30);
	penta = new Pentagon();
	player = new Player();
	box = new BoundingBox((PrimitiveShape*)penta);
}

//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void Update(float deltaTime)
{
#pragma region ExampleCode
	padInfo.Update(App::GetController());

	//------------------------------------------------------------------------
	// Example Sprite Code....
	testSprite->Update(deltaTime);

	//if (App::GetController().GetLeftThumbStickX() > 0.5f)
	if(padInfo.isLStickRight())
	{
		testSprite->SetAnimation(ANIM_RIGHT);
		float x, y;
		testSprite->GetPosition(x, y);
		x += 1.0f;
		testSprite->SetPosition(x, y);
	}
	//if (App::GetController().GetLeftThumbStickX() < -0.5f)
	if(padInfo.isLStickLeft())
	{
		testSprite->SetAnimation(ANIM_LEFT);
		float x, y;
		testSprite->GetPosition(x, y);
		x -= 1.0f;
		testSprite->SetPosition(x, y);
	}
	//if (App::GetController().GetLeftThumbStickY() > 0.5f)
	if(padInfo.isLStickUp())
	{
		testSprite->SetAnimation(ANIM_FORWARDS);
		float x, y;
		testSprite->GetPosition(x, y);
		y += 1.0f;
		testSprite->SetPosition(x, y);
	}
	//if (App::GetController().GetLeftThumbStickY() < -0.5f)
	if(padInfo.isLStickDown())
	{
		testSprite->SetAnimation(ANIM_BACKWARDS);
		float x, y;
		testSprite->GetPosition(x, y);
		y -= 1.0f;
		testSprite->SetPosition(x, y);
	}
	//OutputDebugString(std::to_wstring(padInfo.isDpadDown(padInfo.padUp)).append(L" eugh\n").c_str());
	//OutputDebugString(std::to_wstring(App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_UP, true)).append(L" eugh\n").c_str());

	//if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_UP, false))
	if (padInfo.isButtonHeld(padInfo.dpadUp))
	{
		OutputDebugString(L"Up on pad hit!\n");
		testSprite->SetScale(testSprite->GetScale() + 0.1f);
	}
	//if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_DOWN, false))
	if(padInfo.isButtonHeld(padInfo.dpadDown))
	{
		//OutputDebugString(L"IKJJ");
		testSprite->SetScale(testSprite->GetScale() - 0.1f);
	}
	//if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_LEFT, false))
	if(padInfo.isButtonHeld(padInfo.dpadLeft))
	{
		testSprite->SetAngle(testSprite->GetAngle() + 0.1f);
	}
	//if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_RIGHT, false))
	if(padInfo.isButtonHeld(padInfo.dpadRight))
	{
		testSprite->SetAngle(testSprite->GetAngle() - 0.1f);
	}
	//if (App::GetController().CheckButton(XINPUT_GAMEPAD_A, true))
	if(padInfo.isButtonJustPressed(padInfo.buttonSouth))
	{
		testSprite->SetAnimation(-1);
	}
	//------------------------------------------------------------------------
	// Sample Sound.
	//------------------------------------------------------------------------
	//if (App::GetController().CheckButton(XINPUT_GAMEPAD_B, true))
	if(padInfo.isButtonJustPressed(padInfo.buttonEast))
	{
		App::PlaySound(".\\TestData\\Test.wav");
	}
#pragma endregion

	/*Position ex = {};
	App::GetMousePos(ex.x, ex.y);*/
	//Position ex = primshape->GetCenter();
	//primshape->SetCenter({ex.x+0.1f, ex.y});
	player->Update();
}

//------------------------------------------------------------------------
// Add your display calls here (DrawLine,Print, DrawSprite.) 
// See App.h 
//------------------------------------------------------------------------
void Render()
{	
	RenderableItems::RenderAll();
	box->RenderDebug();
	//primshape->Render();
	//------------------------------------------------------------------------
	// Example Sprite Code....
	testSprite->Draw();
	//------------------------------------------------------------------------
	App::DrawLine(0, 0, 100, 100, 1, 0, 0);
	//------------------------------------------------------------------------
	// Example Text.
	//------------------------------------------------------------------------
	App::Print(100, 100, "Sample Text");

	//------------------------------------------------------------------------
	// Example Line Drawing.
	//------------------------------------------------------------------------
	static float a = 0.0f;
	float r = 1.0f;
	float g = 1.0f;
	float b = 1.0f;
	a += 0.1f;
	for (int i = 0; i < 20; i++)
	{

		float sx = 200 + sinf(a + i * 0.1f)*60.0f;
		float sy = 200 + cosf(a + i * 0.1f)*60.0f;
		float ex = 700 - sinf(a + i * 0.1f)*60.0f;
		float ey = 700 - cosf(a + i * 0.1f)*60.0f;
		g = (float)i / 20.0f;
		b = (float)i / 20.0f;
		App::DrawLine(sx, sy, ex, ey,r,g,b);
	}
}
//------------------------------------------------------------------------
// Add your shutdown code here. Called when the APP_QUIT_KEY is pressed.
// Just before the app exits.
//------------------------------------------------------------------------
void Shutdown()
{	
	//------------------------------------------------------------------------
	// Example Sprite Code....
	delete testSprite;
	//------------------------------------------------------------------------
	//delete sq;
	//delete primshape;
	delete player;
}