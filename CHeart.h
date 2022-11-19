#pragma once
#include "CGameObject.h"
class CHeart :
    public CGameObject
{
public:
	CHeart(int rx, int ry, int xc, int yc, float r, float g, float b)
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

