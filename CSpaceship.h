#pragma once
#include "CGameObject.h"
class CSpaceship :
    public CGameObject
{
public:
    bool hasPowerUp = false;
    void draw();
    Rectangle getRectangle();
};

