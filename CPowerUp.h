#pragma once
#include "CGameObject.h"
class CPowerUp :
    public CGameObject
{
public:

    void draw();
    Rectangle getRectangle();
};

