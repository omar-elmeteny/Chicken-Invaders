#pragma once

struct Rectangle {
	int top;
	int bottom;
	int left;
	int right;
};
class CGameObject
{
public :
	int xpos = 0;
	int ypos = 0;

	virtual void draw() = 0;
	virtual Rectangle getRectangle() = 0;
	bool isIntersecting(CGameObject* other);
};

