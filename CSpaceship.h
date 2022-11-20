#pragma once
#include "CGameObject.h"
class CSpaceship :
    public CGameObject
{
public:
    bool hasPowerUp = false;
    int immunityEnds = 0;
    void draw();
    Rectangle getRectangle();
};

