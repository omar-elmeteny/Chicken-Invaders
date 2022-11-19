#pragma once
#include "CGameObject.h"
class CEgg :
    public CGameObject
{
public:
	CEgg(int rx, int ry, int xc, int yc, float r, float g, float b)
	{
		this->rx = rx;
		this->ry = ry;
		this->xc = xc;
		this->yc = yc;
		this->r = r;
		this->g = g;
		this->b = b;
	}

	int rx;
	int ry;
	int xc;
	int yc;
	float r;
	float g;
	float b;
	void draw();
	Rectangle getRectangle();
};

