#include "Triangle.h"
#include "MapTile.h"

class Bomb 
{
public:
	Bomb();
	~Bomb();

	void Update();
	int GetBombFuseLength();
	int GetTimeBombWasDropped();
	void SetIsActive(bool b);
	bool IsActive();
	void SetCurrentTile(MapTile* m);
	void ActivateBomb(MapTile* m);

private:
	Triangle* bombSprite;
	MapTile* currentTile;
	bool isActive = false;
	int timeBombWasDropped = 0;
	int bombFuseLength = 4;

	bool Timer(int secs, int oldtime);
	void CheckIfBombFuseElapsed();

	//maybe shift explosion timer logic here?
	//could do the timer check here (registered under player's update), update the map tiles using isexploding as a "this instant" check, and set sprites on them when they are "exploding"
};
