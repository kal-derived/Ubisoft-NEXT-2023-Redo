#include "stdafx.h"
#include "GameLoop.h"

Triangle* primshape;
Square* sq;
Player* player;
Pentagon* penta;
BoundingBox* box;
ControllerInfo padInfo;
PlayerControlsLink mechanicsLoop;
WorldCollisionHandler* physicsLoop;

MapGenerator* map;

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
	box = new BoundingBox(penta);
	padInfo = ControllerInfo();
	//player->GetBody()->renderMode = false;

	map = new MapGenerator();

	for each (MapTile* t in map->GetTiles())
	{
		WorldCollisionHandler::AddCollider(t->GetCollider());
	}

	physicsLoop = new WorldCollisionHandler(player, map);
	physicsLoop->AddCollider(box);
	//for (size_t i = 0; i < Debug::testColliders.size(); i++)
	//{
	//	physicsLoop->AddCollider(Debug::testColliders[i]);
	//}

}

void GameLoop::Update()
{
	/*Position ex = {};
	App::GetMousePos(ex.x, ex.y);*/
	//Position ex = primshape->GetCenter();
	//primshape->SetCenter({ex.x+0.1f, ex.y});
	padInfo.Update(App::GetController());
	//player->Update();
	physicsLoop->Update();
	mechanicsLoop.Update(player, &padInfo);

	//bool touch = Collision::isTouching(player->GetCollider(), box);
	//if (touch)
	//{
	//	penta->SetColor(1, 1, 1);
	//	Collision::ResolveCollision(player->GetCollider(), box);
	//	player->SetPosition(player->GetCollider()->center);
	//}

	

}

void GameLoop::Render()
{

	RenderableItems::RenderAll();
	//primshape->Render();
	box->RenderDebug();
	//player->GetCollider()->RenderDebug();
	//for (size_t i = 0; i < Debug::testColliders.size(); i++) // Render debug squares collision
	//{
	//	Debug::testColliders[i]->RenderDebug();
	//}
	map->Render();

}

void GameLoop::Shutdown()
{
	//delete sq;
	//delete primshape;
	delete penta;
	delete player;
	delete box;
}
