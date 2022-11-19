#include "CGameObject.h"

bool CGameObject::isIntersecting(CGameObject* other) {
	Rectangle r1 = this->getRectangle();
	Rectangle r2 = other->getRectangle();
	return r1.left <= r2.right && r1.right >= r2.left
		&& r1.bottom <= r2.top && r1.top >= r2.bottom;
}

