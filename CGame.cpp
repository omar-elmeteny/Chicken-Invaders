#include "CGame.h"

CGame::CGame() {
	spaceship = new CSpaceship();
	this->objects.push_back(spaceship);
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

void CGame::removeBullet(CBullet* obj) {
	auto point = std::find_if(this->bullets.begin(), this->bullets.end(), [obj](CBullet* b) -> bool {
		return b == obj;
		});
	if (point != this->bullets.end()) {
		this->bullets.erase(point);
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

void CGame::tick() {
	for (size_t i = 0; i < this->bullets.size(); i++) {
		CBullet* bullet = this->bullets[i];
		bullet->ypos += bulletSpeed;
		if (bullet->ypos > top) {
			removeBullet(bullet);
			i--;
		}
	}
	ticks++;
}

void CGame::draw() {
	for (CGameObject* obj : this->objects) {
		obj->draw();
	}
}