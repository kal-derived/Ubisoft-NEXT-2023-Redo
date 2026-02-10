#include "stdafx.h"
#include "Bomb.h"



Bomb::Bomb()
{
	isActive = false;
	currentTile = nullptr;
	bombSprite = new Triangle({-1,-1}, 20);
}

Bomb::~Bomb()
{
}

void Bomb::Update()
{
	if (timeBombWasDropped != 0)
	{
		CheckIfBombFuseElapsed();
	}
}

int Bomb::GetBombFuseLength()
{
	return bombFuseLength;
}

int Bomb::GetTimeBombWasDropped()
{
	return timeBombWasDropped;
}

void Bomb::SetIsActive(bool b)
{
	isActive = b;
	if (b == true)
	{
		bombSprite->SetRenderMode(true);
	}
	else
	{
		bombSprite->SetRenderMode(false);
	}
}

bool Bomb::IsActive()
{
	return isActive;
}

void Bomb::SetCurrentTile(MapTile* m)
{
	currentTile = m;
}

void Bomb::ActivateBomb(MapTile* m)
{
	SetIsActive(true);
	SetCurrentTile(m);
	timeBombWasDropped = time(nullptr);
	bombSprite->SetCenter(currentTile->GetCenter());
}

bool Bomb::Timer(int secs, int oldtime)
{
	if (oldtime + secs <= time(nullptr)) {
		return true;

	}
	return false;
}

void Bomb::CheckIfBombFuseElapsed()
{
	if (IsActive())
	{
		OutputDebugString(L"E");
		if (timeBombWasDropped + bombFuseLength <= time(nullptr)) 
		{
			OutputDebugString(L"Explosion!");
			SetIsActive(false);
		}
	}
}
