#include <stdlib.h>
#include "CGame.h"
#include "glut.h"

char player[] = { "Player" };
char enemy[] = { "Enemy" };
char playerWonMessage[] = { "You won!!" };
char chickenWonMessage[] = { "You lost!!" };

CGame::CGame() {
	spaceship = new CSpaceship();
	this->objects.push_back(spaceship);
	chicken = new CChicken();
	chicken->ypos = -100;
	this->objects.push_back(chicken);
	heart1 = new CHeart(10,20,600,1470,1,0,0);
	this->objects.push_back(heart1);
	this->lives.push_back(heart1);
	heart2 = new CHeart(10,20,650,1470,1,0,0);
	this->objects.push_back(heart2);
	this->lives.push_back(heart2);
	heart3 = new CHeart(10,20,700,1470,1,0,0);
	this->objects.push_back(heart3);
	this->lives.push_back(heart3);
	healthbar = new CHealthBar(200);
	this->objects.push_back(healthbar);
}

CGame::~CGame() {
	delete spaceship;
}

void CGame::addBullet()
{
	if (lastBulletFired + fireRate > ticks) {
		return;
	}
	lastBulletFired = ticks;
	CBullet* bullet = new CBullet(10, 40, 100, 275, 1.0f, 0.84f, 0.0f);
	bullet->xpos = spaceship->xpos;
	bullet->ypos = spaceship->ypos;
	this->objects.push_back(bullet);
	this->bullets.push_back(bullet);
}

void CGame::removeHeart(CHeart* obj) {
	auto point = std::find_if(this->lives.begin(), this->lives.end(), [obj](CHeart* b) -> bool {
		return b == obj;
		});
	if (point != this->lives.end()) {
		this->lives.erase(point);
	}
	removeObject(obj);
}

void CGame::addEgg()
{
	CEgg* egg = new CEgg(10, 30, 100, 1100, 1.0f, 1.0f, 1.0f);
	egg->xpos = chicken->xpos;
	egg->ypos = chicken->ypos;
	this->objects.push_back(egg);
	this->eggs.push_back(egg);
}

void CGame::addPowerUp() {
	int x = left + ((int) rand() % right);
	int y = bottom + ((int) rand() % top / 2);
	CPowerUp* powerUp = new CPowerUp();
	powerUp->powerUpClear = ticks + powerUpDuration;
	powerUp->xpos = x;
	powerUp->ypos = y;
	this->powerUps.push_back(powerUp);
	this->objects.push_back(powerUp);
}

void CGame::removeBullet(CBullet* obj) {
	auto point = std::find_if(this->bullets.begin(), this->bullets.end(), [obj](CBullet* b) -> bool {
		return b == obj;
		});
	if (point != this->bullets.end()) {
		this->bullets.erase(point);
	}
	removeObject(obj);
}

void CGame::removePowerUp(CPowerUp* obj) {
	auto point = std::find_if(this->powerUps.begin(), this->powerUps.end(), [obj](CPowerUp* b) -> bool {
		return b == obj;
		});
	if (point != this->powerUps.end()) {
		this->powerUps.erase(point);
	}
	removeObject(obj);
}

void CGame::removeEgg(CEgg* obj) {
	auto point = std::find_if(this->eggs.begin(), this->eggs.end(), [obj](CEgg* b) -> bool {
		return b == obj;
		});
	if (point != this->eggs.end()) {
		this->eggs.erase(point);
	}
	removeObject(obj);
}

void CGame::removeObject(CGameObject* obj) {
	auto point = std::remove_if(this->objects.begin(), this->objects.end(), [obj](CGameObject* b) -> bool {
		return b == obj;
		});
	if (point != this->objects.end()) {
		this->objects.erase(point);
	}
	delete obj;
}


void CGame::playerAttacked() {
	if (lives.size() == 0) {
		return;
	}
	CHeart* heart = this->lives[lives.size() - 1];
	for (size_t i = 0;i < this->eggs.size();i++) {
		CEgg* egg = this->eggs[i];
		if (egg->isIntersecting(spaceship)) {
			if (!spaceship->hasPowerUp) {
				removeHeart(heart);
			}
			removeEgg(egg);
		}
	}
	if (lives.size() == 0) {
		this->gameOver = true;
		this->playerLost = true;
	}
}

void CGame::powerUpTaken() {
	if(powerUps.size() == 0) {
		return;
	}
	for (size_t i = 0;i < powerUps.size();i++) {
		CPowerUp* powerUp = powerUps[i];
		if (spaceship->isIntersecting(powerUp)) {
			spaceship->hasPowerUp = true;
			spaceship->immunityEnds = ticks + immunityDuration;
			removePowerUp(powerUp);
		}
	}
}

void CGame::chickenAttacked() {
	if (healthbar->width == 0) {
		return;
	}
	for (size_t i = 0;i < this->bullets.size();i++) {
		CBullet* bullet = this->bullets[i];
		if (bullet->isIntersecting(chicken)) {
			healthbar->width -= 20;
			removeBullet(bullet);
		}
	}
	if (healthbar->width == 0) {
		gameOver = true;
		playerWon = true;
	}
}

void CGame::tick() {
	if (!gameOver) {
		powerUpTaken();
		playerAttacked();
		chickenAttacked();
		if (ticks % eggRate == 0) {
			addEgg();
		}

		if (ticks % powerUpRate == 0 && ticks != 0) {
			addPowerUp();
		}

		for (size_t i = 0;i < powerUps.size();i++) {
			CPowerUp* powerUp = powerUps[i];
			if (ticks >= powerUp->powerUpClear) {
				removePowerUp(powerUp);
			}
		}

		if (spaceship->hasPowerUp && spaceship->immunityEnds < ticks) {
			spaceship->hasPowerUp = false;
		}

		switch (chickenDirection) {
		case -1:
			if (chicken->xpos - chickenSpeed < left) {
				chickenDirection = -chickenDirection;
			}
			break;
		case 1:
			if (chicken->xpos + chickenSpeed > right - 200) {
				chickenDirection = -chickenDirection;
			}
			break;
		}

		chicken->xpos += chickenDirection * chickenSpeed;

		for (size_t i = 0; i < this->bullets.size(); i++) {
			CBullet* bullet = this->bullets[i];
			bullet->ypos += bulletSpeed;
			if (bullet->ypos > top) {
				removeBullet(bullet);
				i--;
			}
		}
		for (size_t i = 0; i < this->eggs.size(); i++) {
			CEgg* egg = this->eggs[i];
			egg->ypos -= bulletSpeed;
			if (egg->ypos > top) {
				removeEgg(egg);
				i--;
			}
		}
	}
	ticks++;
}

void CGame::draw() {
	for (CGameObject* obj : this->objects) {
		obj->draw();
	}

	glRasterPos2d(450, 1440);
	for (size_t i = 0;i < strlen(player);i++) {
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, player[i]);
	}
	glRasterPos2d(-450, 1450);
	for (size_t i = 0;i < strlen(enemy);i++) {
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, enemy[i]);
	}

	if (gameOver) {
		if (playerWon) {
			glRasterPos2d((left + right - strlen(playerWonMessage) * 9) / 2, (top + bottom) / 2);
			for (size_t i = 0;i < strlen(playerWonMessage);i++) {
				glutBitmapCharacter(GLUT_BITMAP_9_BY_15, playerWonMessage[i]);
			}
		}
		else {
			glRasterPos2d((left + right - strlen(chickenWonMessage) * 9) / 2, (top + bottom) / 2);
			for (size_t i = 0;i < strlen(chickenWonMessage);i++) {
				glutBitmapCharacter(GLUT_BITMAP_9_BY_15, chickenWonMessage[i]);
			}
		}
	}
}