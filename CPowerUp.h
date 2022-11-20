#pragma once
#include "CGameObject.h"
class CPowerUp :
    public CGameObject
{
public:
    int powerUpClear = 750;
    void draw();
    Rectangle getRectangle();
};

