#pragma once
#include "CGameObject.h"
#include "CBullet.h"
#include <vector>
#include "CSpaceship.h"

class CGame
{
private:

	std::vector<CGameObject*> objects;
	std::vector<CBullet*> bullets;
	void removeBullet(CBullet* obj);
	void removeObject(CGameObject* obj);
	int fireRate = 50;
	int lastBulletFired = -50;
	int ticks = 0;	
public:
	
	int left = -560;
	int right = 750;
	int top = 1500;
	int bottom = -100;
	int spaceShipSpeed = 15;
	int bulletSpeed = 4;
	CGame();
	~CGame();
	CSpaceship* spaceship;
	void tick();
	void draw();
	void addBullet();
};

