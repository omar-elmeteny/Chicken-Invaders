#pragma once
class CGameObject
{
public :
	int xpos = 0;
	int ypos = 0;

	virtual void draw() = 0;	
};

