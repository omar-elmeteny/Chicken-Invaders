#pragma once
#include "CGameObject.h"
#include "CBullet.h"
#include <vector>
#include "CSpaceship.h"
#include "CChicken.h"
#include "CEgg.h"
#include "CHeart.h"
#include "CHealthBar.h"
#include "CPowerUp.h"
#include "CPowerUp.h"

class CGame
{
private:

	std::vector<CGameObject*> objects;
	std::vector<CBullet*> bullets;
	std::vector<CEgg*> eggs;
	std::vector<CHeart*> lives;
	std::vector<CPowerUp*> powerUps;
	void removeBullet(CBullet* obj);
	void removeObject(CGameObject* obj);
	int fireRate = 50;
	int eggRate = 75;
	int powerUpRate = 2000;
	int lastBulletFired = -50;
	int immunityDuration = 1000;
	int powerUpDuration = 750;
	int ticks = 0;	
	int chickenSpeed = 3;
	int chickenDirection = 1;
	bool playerWon = false;
	bool playerLost = false;

	void addEgg();
	void removeEgg(CEgg* obj);
	void removeHeart(CHeart* obj);
	void addPowerUp();
	void removePowerUp(CPowerUp* obj);

public:
	
	bool gameOver = false;
	int left = -560;
	int right = 750;
	int top = 1500;
	int bottom = -100;
	int spaceShipSpeed = 15;
	int bulletSpeed = 4;
	CGame();
	~CGame();
	CSpaceship* spaceship;
	CChicken* chicken;
	CHeart* heart1;
	CHeart* heart2;
	CHeart* heart3;
	CHealthBar* healthbar;
	void tick();
	void draw();
	void addBullet();
	void playerAttacked();
	void chickenAttacked();
	void powerUpTaken();
};

