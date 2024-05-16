#include "stdafx.h"
#include "GameLoop.h"

Triangle* primshape;
Square* sq;
Player* player;
Pentagon* penta;
BoundingBox* box;

GameLoop::GameLoop()
{
}

GameLoop::~GameLoop()
{
}

void GameLoop::Init()
{
	//primshape = new Triangle({500,400}, 100);
	//sq = new Square({200, 300}, 30);
	penta = new Pentagon({ 600, 300 }, 30.0f);
	player = new Player();
	box = new BoundingBox((PrimitiveShape*)penta);
}

void GameLoop::Update()
{
	/*Position ex = {};
	App::GetMousePos(ex.x, ex.y);*/
	//Position ex = primshape->GetCenter();
	//primshape->SetCenter({ex.x+0.1f, ex.y});

	player->Update();
	player->GetBody()->renderMode = false;
	bool touch = Collision::isTouching(player->GetCollider(), box);
	if (touch)
	{
		penta->SetColor(1, 1, 1);
	}
}

void GameLoop::Render()
{
	RenderableItems::RenderAll();
	//primshape->Render();
	box->RenderDebug();
	player->GetCollider()->RenderDebug();
}

void GameLoop::Shutdown()
{
	//delete sq;
	//delete primshape;
	delete penta;
	delete player;
	delete box;
}
